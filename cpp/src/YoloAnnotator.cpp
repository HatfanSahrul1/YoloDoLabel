#include "include/YoloAnnotator.h"

YoloAnnotator::YoloAnnotator(const DataLoader& dataLoader){
    inference = new Inference(dataLoader.GetModelPath(),
                                dataLoader.GetModelShape(),
                                dataLoader.GetModelClasses(),
                                false)
    
    mapper = new LabelMapper(dataLoader.GetClassRemap());
    datasetPath = dataLoader.GetDatasetPath();
    outputPath = dataLoader.GetOutputPath();
}