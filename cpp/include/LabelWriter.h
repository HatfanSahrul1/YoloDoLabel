#ifndef LABEL_WRITER_H
#define LABEL_WRITER_H

#include <iostream>
#include <vector>
#include <map>

#include "LabelMapper.h"
#include "opencv2/opencv.hpp"

class LabelWriter {
    public:
        void write(const std::string& image_name, const std::vector<Detection>& detections, 
                   const cv::Size& img_size, const LabelMapper& mapper, const std::string& save_dir);
};

#endif