#include "downloadFile.h"


namespace download {
    size_t DownloadFile::writeCallback(void* contents, size_t size, size_t nmemb, FILE* stream) {
        return fwrite(contents, size, nmemb, stream);
    }
    // Реализация конструктора
    DownloadFile::DownloadFile(CURL* curl, CURLcode res, FILE* file) : curl_test(curl), res_test(res), fp(file)
    {
        this->curl_test = curl;
        this->res_test = res;
        this->fp = file;
    }

    // Реализация деструктора
    DownloadFile::~DownloadFile() {
        if (curl_test) {
            curl_easy_cleanup(curl_test);
        }
        if (fp) {
            std::fclose(fp);
        }
    }

    // Реализация метода fopen
    void DownloadFile::fopen(std::string path) {
        fp = std::fopen(path.c_str(), "w+");
        if (fp == NULL) {
            std::cerr << "Failed to open file for writing." << std::endl;
            return;
        }
    }

    // Реализация метода download
    void DownloadFile::download(const char* URL) {
        curl_test = curl_easy_init();
        if (curl_test) {
            curl_easy_setopt(curl_test, CURLOPT_URL, URL);

            curl_easy_setopt(curl_test, CURLOPT_WRITEFUNCTION, &DownloadFile::writeCallback);
            curl_easy_setopt(curl_test, CURLOPT_WRITEDATA, fp);

            res_test = curl_easy_perform(curl_test);

            if (res_test != CURLE_OK) {
                fprintf(stderr, "Error cURL: %s\n", curl_easy_strerror(res_test));
            }
        }
    }
}