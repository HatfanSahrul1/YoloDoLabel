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