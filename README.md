# YOLO Labeling Tool (C++)

This is a simple C++ tool to annotate images using a pre-trained YOLOv5/YOLOv8 model and export the results in YOLO format.

## Features

- Load images from a dataset directory
- Run YOLO inference on each image
- Write normalized bounding box results to `.txt` files (YOLO format)
- Configurable via `config.yaml`

## Requirements

- OpenCV
- A trained YOLOv5/YOLOv8 model (recommended to have one before using this tool)
- C++17 or later

## Usage

1. Edit `config.yaml` with your dataset path and output directory.
2. Build the project with CMake.
3. Run the tool to process and label images automatically.

