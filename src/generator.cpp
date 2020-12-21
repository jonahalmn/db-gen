#include "generator.h"

void Generator::makeDatabase(std::string dir, URLMap urls) {
    URLMap::iterator it;
    mkdir(dir.c_str(), 0777);

    for (it = urls.begin(); it != urls.end(); it++)
    {
        int result = mkdir(std::string{dir + "/" + it->first}.c_str(), 0777);
        if(result == -1) {
            if( errno != EEXIST ) {
                std::cout << "error while creating folder : " << it->first;
                exit(2);
            }
        }

        std::cout << "generating images: " << dir << "/" << it->first << std::endl;

        for(unsigned long j = 0; j < it->second.size(); j++) {
            const std::string &source = it->second[j];
            Magick::Image url_image(source);
            url_image.magick("JPEG");
            url_image.resize("400x400!");
            url_image.write(std::string{dir + "/" + it->first + "/" + it->first + "-" + std::to_string(j) + ".jpg"});
        }

    }
}