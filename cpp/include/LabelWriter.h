#ifndef LABEL_WRITER_H
#define LABEL_WRITER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

#include "opencv2/opencv.hpp"
#include "LabelMapper.h"
#include "inference.h"

namespace fs = std::filesystem;

class LabelWriter {
    public:
        static void write(const std::string& image_name, const std::vector<Detection>& detections, 
                   const cv::Size& img_size, const LabelMapper& mapper, const std::string& outputDir);
};

#endif