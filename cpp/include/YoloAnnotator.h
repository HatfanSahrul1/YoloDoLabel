#ifndef YOLO_ANNOTATOR_H
#define YOLO_ANNOTATOR_H

#include <iostream>
#include <vector>
#include <map>

#include "inference.h"
#include "LabelMapper.h"

class YoloAnnotator {
    public:
        YoloAnnotator(const std::string& modelPath,
                      const std::string& classFile,
                      const std::string& datasetDir,
                      const std::string& outputDir,
                      const std::map<int, int>& classRemap,
                      bool useCuda = true);
    
        void run();
    
    private:
        Inference inference;
        LabelMapper mapper;
        std::string datasetPath;
        std::string outputPath;
};

#endif