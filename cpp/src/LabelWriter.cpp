#include "include/LabelWriter.h"

void LabelWriter::write(const std::string& image_name, 
                        const std::vector<Detection>& detections, 
                        const cv::Size& img_size, 
                        const LabelMapper& mapper, 
                        const std::string& outputDir){

    fs::path inputPath(image_name);
    std::string baseName = inputPath.stem().string() + ".txt";
    
    fs::create_directories(outputDir);
    fs::path outPath = fs::path(outputDir) / baseName;

    std::ofstream file(outPath);
    if (!file.is_open()) {
        throw std::runtime_error("Gagal membuka file untuk menulis: " + outPath.string());
    }

    for (const auto& det : detections) {
        int remappedID = mapper.map(det.class_id);

        float x_center = (det.box.x + det.box.width / 2.0f) / img_size.width;
        float y_center = (det.box.y + det.box.height / 2.0f) / img_size.height;
        float width = det.box.width / static_cast<float>(img_size.width);
        float height = det.box.height / static_cast<float>(img_size.height);

        file << remappedID << " "
        << x_center << " "
        << y_center << " "
        << width << " "
        << height << std::endl;
    }

    file.close();
}