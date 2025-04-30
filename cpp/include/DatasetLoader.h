#ifndef DATASET_LOADER_H
#define DATASET_LOADER_H

#include <iostream>
#include <vector>

class DatasetLoader {
    public:
        static std::vector<std::string> loadImages(const std::string& folder, const std::vector<std::string>& extensions = {".jpg", ".png"});
};

#endif