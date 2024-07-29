OPENCV_INSTALL_DIR = "d:/lib/opencv"
#OPENCV_INSTALL_DIR = "d:/lib/opencv-4.8.1_mingw1120_64/install"
EIGEN_INSTALL_DIR = "d:/lib/eigen"

INCLUDEPATH += $${OPENCV_INSTALL_DIR}/include \
                $${EIGEN_INSTALL_DIR}

OPENCV_ARCHITECURE  = ""
OPENCV_BUILD_SYS = "/mingw" #"/vc16"
OPENCV_VERSION = "481"
OPENCV_ARCHITECURE = "/x64"

OPENCV_LIB_NAME = "opencv_world"
OPENCV_LIB_DIR = $${OPENCV_INSTALL_DIR}$${OPENCV_ARCHITECURE}$${OPENCV_BUILD_SYS}"/lib"
OPENCV_LIB_PREFIX = ""
OPENCV_LIB_EXTENSION = ""
OPENCV_LIB_BUILD_TYPE = ""

equals(OPENCV_BUILD_SYS, "/mingw") {
    #OPENCV_LIB_PREFIX = "lib"
    #OPENCV_LIB_EXTENSION = ".dll.a"
    #OPENCV_LIB_EXTENSION = ".dll"
} else {
    OPENCV_LIB_BUILD_TYPE = "d"
}

OPENCV_LIB_FILE_NAME = $${OPENCV_LIB_PREFIX}$${OPENCV_LIB_NAME}$${OPENCV_VERSION}$${OPENCV_LIB_BUILD_TYPE}$${OPENCV_LIB_EXTENSION}

Debug: {
    message("Debug")
    equals(OPENCV_BUILD_SYS, "/mingw") {
        message("      NOTE: Debug Lib is not supported by MinGW")
    }
}
Release: {
    message("Release")

}

LIBS += -L$${OPENCV_LIB_DIR} \
        -l$${OPENCV_LIB_FILE_NAME}

message($${TARGET})
message("INCLUDEPATH: "$${INCLUDEPATH})
message("LIBS:        "$${LIBS})
message("")

HEADERS +=

