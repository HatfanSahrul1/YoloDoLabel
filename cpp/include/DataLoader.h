#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <iostream>
#include <vector>
#include <map>

#include "yaml-cpp/yaml.h"

class DataLoader {
public:
    DataLoader(std::string config_file);

    std::string GetModelPath();
    int GetModelShape();
    std::vector<std::string> GetModelClasses();
    std::string GetDatasetPath();
    std::string GetOutputPath();
    std::map<int, int> GetClassRemap();

private:
    int model_input_size;
    std::string modelPath;
    std::vector<std::string> classes;
    std::string datasetDir;
    std::string outputDir;
    std::map<int, int> classRemap;
};

#endif