#include "include/YoloAnnotator.h"

YoloAnnotator::YoloAnnotator(const DataLoader& dataLoader) 
    : inference(dataLoader.GetModelPath(),
                cv::Size(dataLoader.GetModelShape(), dataLoader.GetModelShape()),
                dataLoader.GetModelClasses(),
                false),
    mapper(dataLoader.GetClassRemap()),
    datasetPath(dataLoader.GetDatasetPath()),
    outputPath(dataLoader.GetOutputPath())
{}

void YoloAnnotator::Run(){
    std::vector<std::string> images = DatasetLoader::loadImages(datasetPath);
    
    for(const auto& image_path : images){
        cv::Mat image = cv::imread(image_path);

        std::vector<Detection> det = inference.runInference(image);

        LabelWriter::write(image_path, det, image.size(), mapper, outputPath);
    }
}