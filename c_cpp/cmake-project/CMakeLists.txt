# Mindestanforderung an die CMake-Version
cmake_minimum_required(VERSION 3.25)

# Projektname und Version
project(MyProject VERSION 1.0)

# C++ Standard festlegen
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include-Verzeichnis hinzufügen
include_directories(include)

# Suche nach den externen Bibliotheken
find_package(OpenCV REQUIRED)
find_package(exiv2 REQUIRED)
find_package(Eigen3 REQUIRED)

# Include-Verzeichnisse für die externen Bibliotheken hinzufügen
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${EXIV2_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIR})

# Quellverzeichnis hinzufügen
add_subdirectory(src)

# Bibliotheksverzeichnis hinzufügen (falls nötig)
#add_subdirectory(lib)

# Datenverzeichnis hinzufügen (falls nötig)
#add_subdirectory(data)

# Ausgabeverzeichnisse für binäre Dateien festlegen
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Optionale: Compiler-Warnungen einschalten
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()