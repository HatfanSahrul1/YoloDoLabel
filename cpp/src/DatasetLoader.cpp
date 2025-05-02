#include "include/DatasetLoader.h"

std::vector<std::string> DatasetLoader::loadImages(const std::string& directory, const std::vector<std::string>& extensions)
{
    std::vector<std::string> imagePaths;

    if (!fs::exists(directory) || !fs::is_directory(directory)) {
        throw std::runtime_error("DatasetLoader error: directory does not exist - " + directory);
    }

    for (const auto& entry : fs::directory_iterator(directory)) {
        if (!entry.is_regular_file()) continue;

        std::string path = entry.path().string();
        std::string ext = entry.path().extension().string();

        // lower-case comparison
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

        if (std::find(extensions.begin(), extensions.end(), ext) != extensions.end()) {
            imagePaths.push_back(path);
        }
    }

    return imagePaths;
}