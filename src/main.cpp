#include <iostream>
#include <map>
#include "./utils/concat_vectors.h"
#include "./bing_client.h"
#include "./utils/file.h"
#include "generator.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "[USAGE] " << argv[0] << " <APIKEY> <...LABELS>" << std::endl;
    }

    argc-=2;
    argv+=2;

    BingClient client{"https://api.bing.microsoft.com/v7.0/images/search", argv[1]};
    URLMap map = client.searchAll(argc, argv);

    Generator::makeDatabase("database", map);

    // File file{"file.json"};
    // std::string json = file.read();
    // client.extractUrls(json);

    return 0;
}