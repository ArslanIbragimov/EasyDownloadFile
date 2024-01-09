#include "ExampleMain.h"

CURL* curl;
CURLcode res;
FILE* fp;

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);

    download::DownloadFile obj(curl, res, fp);
    std::string filePath = "C:\\Users\\user\\testapp\\1352618498_ekosistemy.ppt";
    obj.fopen(filePath);
    obj.download("https://prezented.ru/uploads/files/1352618498_ekosistemy.ppt");
    
    curl_global_cleanup();

    return 0;
}