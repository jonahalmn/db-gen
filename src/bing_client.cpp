#include "bing_client.h"

std::vector<std::string> BingClient::search(std::string query) {
    return extractUrls(File("file.json").read());
    CURL *c;
    struct curl_slist *chunk = NULL;
    c = curl_easy_init();

    std::string buffer;

    chunk = curl_slist_append(chunk, std::string{
            "Ocp-Apim-Subscription-Key : " + m_api_key
        }.c_str());

    curl_easy_setopt(c, CURLOPT_HTTPHEADER, chunk);
    curl_easy_setopt( c, CURLOPT_URL, std::string{
        m_base_url + "?q=" + query + "&count=" + std::to_string(POST_PER_PAGE)
        }.c_str() );
    curl_easy_setopt(c, CURLOPT_WRITEDATA, &buffer);
    curl_easy_perform( c );
    curl_easy_cleanup( c );

    return extractUrls(buffer);
}

URLMap BingClient::searchAll(int count, char* keywords[]) {
    URLMap result;
    for (int i = 0; i < count; i++)
    {
        std::vector<std::string> urls = search(keywords[i]);
        result[keywords[i]] += urls;
        //std::cout << keywords[i] << std::endl;
    }

    return result;
}

std::vector<std::string> BingClient::extractUrls(std::string json_string) {
    nlohmann::json formatted = nlohmann::json::parse(json_string);
    std::vector<std::string> strings{};

    for (unsigned long i = 0; i < formatted["value"].size(); i++)
    {
        strings.push_back(formatted["value"][i]["contentUrl"].get<std::string>());
    }

    return strings;
}