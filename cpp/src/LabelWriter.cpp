#include "include/LabelWriter.h"

void LabelWriter::write(const std::string& imagePath,
                        const std::vector<Detection>& detections,
                        const cv::Size& imageSize,
                        const LabelMapper& mapper,
                        const std::string& outputDir){

    // Ambil nama file tanpa ekstensi
    fs::path inputPath(imagePath);
    std::string baseName = inputPath.stem().string(); // contoh: "image_001"

    // Buat path output
    fs::create_directories(outputDir);
    std::string outPath = outputDir + "/" + baseName + ".txt";

    std::ofstream file(outPath);
    if (!file.is_open()) {
        throw std::runtime_error("Gagal membuka file untuk menulis: " + outPath);
    }

    for (const auto& det : detections) {
        int remappedID = mapper.map(det.class_id);

        // Normalisasi koordinat bounding box
        float x_center = (det.box.x + det.box.width / 2.0f) / imageSize.width;
        float y_center = (det.box.y + det.box.height / 2.0f) / imageSize.height;
        float width = det.box.width / static_cast<float>(imageSize.width);
        float height = det.box.height / static_cast<float>(imageSize.height);

        file << remappedID << " "
        << x_center << " "
        << y_center << " "
        << width << " "
        << height << std::endl;
    }

    file.close();
}