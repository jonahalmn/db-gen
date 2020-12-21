#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "types.h"
#include "utils/concat_vectors.h"
#include "./utils/file.h"

#define POST_PER_PAGE 150
#define ITERATIONS_COUNT 2

class BingClient {

    std::string m_base_url;
    std::string m_api_key;
    // std::map<std::string, std::vector<std::string>>

    public:

        BingClient(std::string base_url, std::string api_key) : m_base_url{base_url}, m_api_key{api_key} {};
        void debug();
        std::vector<std::string> search(std::string);
        std::vector<std::string> extractUrls(std::string);

        URLMap searchAll(int count, char* keywords[]);


};