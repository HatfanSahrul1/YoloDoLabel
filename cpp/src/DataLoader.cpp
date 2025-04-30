#include "include/DataLoader.h"

DataLoader::DataLoader(std::string config_file){
    YAML::Node config = YAML::LoadFile(config_file);
    
    modelPath           = config["model_path"].as<std::string>();
    model_input_size    = config["model_path"].as<int>();
    datasetDir          = config["dataset_path"].as<std::string>();
    outputDir           = config["output_dir"].as<std::string>();

    for(const auto& data : config["model_config"]){
        const auto& value = data.second;

        std::string label = value["label"].as<std::string>();
        
        classRemap.insert({
                            data.first.as<int>(), 
                            value["remap"].as<int>()
                        });

        classes.push_back(label);
    }
}

std::string DataLoader::GetModelPath(){
    return modelPath;
}

int DataLoader::GetModelShape(){
    return model_input_size;
}

std::string DataLoader::GetDatasetPath(){
    return datasetDir;
}

std::string DataLoader::GetOutputPath(){
    return outputDir;
}

std::vector<std::string> DataLoader::GetModelClasses(){
    return classes;
}

std::map<int, int> DataLoader::GetClassRemap(){
    return classRemap;
}