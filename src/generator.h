#pragma once
#include <Magick++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include "./types.h"

class Generator {
    public:
        static void makeDatabase(std::string, URLMap);
};