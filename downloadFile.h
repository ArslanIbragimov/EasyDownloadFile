#pragma once
#include <curl/curl.h>
#include <iostream>

#ifndef DOWNLOADFILE_H
#define DOWNLOADFILE_H

namespace download {
    class DownloadFile {
    private:
        CURL* curl_test;
        CURLcode res_test;
        FILE* fp;

    public:
        
        DownloadFile(CURL* curl, CURLcode res, FILE* file);
        ~DownloadFile();

        void fopen(std::string path);

        void download(const char* URL);

    protected:
        size_t writeCallback(void* contents, size_t size, size_t nmemb, FILE* stream);
    };
}
#endif
