#include "include/LabelMapper.h"

LabelMapper::LabelMapper(const std::map<int, int>& class_map){
    mapping = class_map;
}

int LabelMapper::map(int model_class_id) const{
    auto it = mapping.find(model_class_id);
    if (it != mapping.end()) {
        return it->second;
    } else {
        throw std::runtime_error("LabelMapper error: model_class_id " + std::to_string(model_class_id) + " not found in mapping.");
    }
}