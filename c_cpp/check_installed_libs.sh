#!/bin/bash

# Check if OpenCV is installed using dpkg
echo "Checking if OpenCV is installed..."
dpkg -l | grep opencv
if [ $? -eq 0 ]; then
    echo "OpenCV is installed."
else
    echo "OpenCV is not installed."
    exit 1
fi

# Check the installed version of OpenCV
echo "Checking OpenCV version..."
OPENCV_VERSION=$(pkg-config --modversion opencv4 2>/dev/null)
if [ $? -eq 0 ]; then
    echo "OpenCV version: $OPENCV_VERSION"
else
    echo "pkg-config could not find OpenCV. Trying Python..."
    OPENCV_PYTHON_VERSION=$(python3 -c "import cv2; print(cv2.__version__)" 2>/dev/null)
    if [ $? -eq 0 ]; then
        echo "OpenCV Python version: $OPENCV_PYTHON_VERSION"
    else
        echo "Could not determine OpenCV version."
        exit 1
    fi
fi

# Find the installation directory using pkg-config
echo "Finding OpenCV installation directory..."
INCLUDE_DIR=$(pkg-config --cflags opencv4 2>/dev/null | grep -oP '(?<=-I)[^ ]+')
LIB_DIR=$(pkg-config --libs opencv4 2>/dev/null | grep -oP '(?<=-L)[^ ]+')

if [ -n "$INCLUDE_DIR" ] && [ -n "$LIB_DIR" ]; then
    echo "OpenCV include directory: $INCLUDE_DIR"
    echo "OpenCV library directory: $LIB_DIR"
else
    echo "pkg-config could not find OpenCV directories. Trying Python..."
    PYTHON_OPENCV_DIR=$(python3 -c "import cv2; print(cv2.__file__)" 2>/dev/null)
    if [ $? -eq 0 ]; then
        echo "OpenCV Python installation directory: $PYTHON_OPENCV_DIR"
    else
        echo "Could not determine OpenCV installation directory."
        exit 1
    fi
fi

echo "Script completed."
