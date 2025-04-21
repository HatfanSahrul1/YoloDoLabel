cmake_minimum_required(VERSION 3.8)

project(seat C CXX)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 17)


include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})

add_executable(DoLabel yolov8Normal.cpp inference.cpp)
target_link_libraries(DoLabel
${OpenCV_LIBS}
)
