# NetVision Desktop Client

## Overview
NetVision Desktop Client is a modern Qt-based desktop application that combines network connectivity with image processing capabilities. It integrates OpenCV for image handling and libcurl for HTTP communications, making it ideal for applications that need to process and transmit image data over networks.

## Features
- Modern C++ (C++17) implementation
- Qt GUI framework integration
- OpenCV integration for image processing
- libcurl implementation for HTTP requests
- Internationalization support
- Cross-platform compatibility (Windows, macOS, Linux)

## Prerequisites
To build and run this project, you need the following dependencies:

- CMake (version 3.5 or higher)
- Qt5 or Qt6 development libraries
- OpenCV 4.5.2 or higher
- libcurl
- C++17 compatible compiler
- MinGW (for Windows) or appropriate compiler for your platform

## Directory Structure
```
netvision-desktop/
├── CMakeLists.txt
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
└── untitled_en_US.ts
```

## Building the Project

### 1. Configure Dependencies

#### Windows
Set the following environment variables or update paths in CMakeLists.txt:

```cmake
set(CURL_DIR "path/to/curl")
set(OpenCV_DIR "path/to/opencv")
```

#### Linux/macOS
Install dependencies using package manager:

```bash
# Ubuntu/Debian
sudo apt-get install qt6-base-dev libcurl4-openssl-dev libopencv-dev

# macOS
brew install qt6 curl opencv
```

### 2. Build Instructions

```bash
# Create build directory
mkdir build
cd build

# Configure CMake
cmake ..

# Build the project
cmake --build .
```

## Usage
The application provides a GUI interface with the following functionality:

1. HTTP Request Handling
   - Demonstrates basic HTTP GET request to JSONPlaceholder API
   - Configurable endpoint URLs
   - Error handling for network requests

2. Image Processing (Ready for Implementation)
   - OpenCV integration enabled
   - Framework ready for image processing features

## Development

### Adding New Features
1. Create new UI elements in `mainwindow.ui`
2. Implement corresponding functionality in `mainwindow.cpp`
3. Update headers in `mainwindow.h`

### Internationalization
The project includes translation support:
- Translation files are managed in `untitled_en_US.ts`
- Use Qt Linguist to add new translations
- Additional languages can be added by creating new .ts files

## Architecture
- `main.cpp`: Application entry point and translator setup
- `mainwindow.h/.cpp`: Main application window implementation
- `CMakeLists.txt`: Build system configuration
- Translation files: Internationalization support

## Contributing
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## Acknowledgments
- Qt Framework
- OpenCV Library
- libcurl
