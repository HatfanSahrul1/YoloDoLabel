#include <iostream>
#include <string>
#include <map>

#include "include/YoloAnnotator.h"
#include "include/DataLoader.h"

int main() {
    DataLoader dataLoader("/home/user/yoloDoLabel/cpp/config.yaml");
    YoloAnnotator yoloAnnotator(dataLoader);

    yoloAnnotator.Run();

    return 0;
}