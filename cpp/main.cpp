#include <iostream>
#include <string>
#include <map>

// #include "YoloAnnotator.h"
#include "include/DataLoader.h"

int main() {
    DataLoader dataLoader("/home/eros/clone/yoloDoLabel/cpp/config.yaml");
    // std::string modelPath = "model.onnx";
    // std::string classFile = "model_classes.txt";
    // std::string datasetDir = "dataset/images";
    // std::string outputDir = "dataset/labels";

    // std::map<int, int> classRemap = {
    //     {0, 2}, // bola dari model (id 0) disimpan sebagai id 2
    //     {1, 0}, // robot biru → id 0
    //     {2, 1}  // robot merah → id 1
    // };

    // YoloAnnotator annotator(modelPath, classFile, datasetDir, outputDir, classRemap);
    // annotator.run();
    return 0;
}