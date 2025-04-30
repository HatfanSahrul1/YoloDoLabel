#ifndef LABEL_MAPPER_H
#define LABEL_MAPPER_H

#include <iostream>
#include <vector>
#include <map>

class LabelMapper {
    public:
        LabelMapper(const std::map<int, int>& class_map);
        int map(int model_class_id) const;
    
    private:
        std::map<int, int> mapping;
};

#endif