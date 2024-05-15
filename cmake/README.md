## Best Practices
### CMakeLists.txt

#### 1. CMake-Minimum-Version und Projektname festlegen
```
cmake_minimum_required(VERSION 3.14)
project(MyProject VERSION 1.0 LANGUAGES CXX)
```
#### 2. CMake-Module und -Pakete finden
```
find_package(Eigen3 REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
```
#### 3. Optionen und Variablen setzen
```
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```
#### 4. Quell- und Header-Dateien auflisten
```
set(SOURCES
    src/main.cpp
    src/myclass.cpp
)

set(HEADERS
    include/myclass.h
)
```
#### 5. Erstellen von Zielen (Executables und Libraries)
```
add_executable(MyApp ${SOURCES} ${HEADERS})
add_library(MyLib src/mylib.cpp include/mylib.h)
```
#### 6. Include-Verzeichnisse hinzufügen
```
target_include_directories(MyApp PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(MyLib PUBLIC ${CMAKE_SOURCE_DIR}/include ${Eigen3_INCLUDE_DIR})
```
#### 7. Linker-Bibliotheken hinzufügen
```
target_link_libraries(MyApp PRIVATE Qt6::Widgets MyLib)
```
#### 8. Zieleigenschaften und Abhängigkeiten festlegen
```
set_target_properties(MyApp PROPERTIES VERSION ${PROJECT_VERSION})
add_dependencies(MyApp MyLib)
```
#### 9. Benutzerdefinierte Befehle und Abhängigkeiten hinzufügen
```
add_custom_command(TARGET MyApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:Qt6::Widgets>
    $<TARGET_FILE_DIR:MyApp>)
```
#### 10. Installation und Packaging
```
install(TARGETS MyApp MyLib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)
```
### Beispiel-CMakeLists.txt
```
cmake_minimum_required(VERSION 3.14)
project(MyProject VERSION 1.0 LANGUAGES CXX)

# Find packages
find_package(Eigen3 REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source and header files
set(SOURCES
    src/main.cpp
    src/myclass.cpp
)

set(HEADERS
    include/myclass.h
)

# Create targets
add_executable(MyApp ${SOURCES} ${HEADERS})
add_library(MyLib src/mylib.cpp include/mylib.h)

# Include directories
target_include_directories(MyApp PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(MyLib PUBLIC ${CMAKE_SOURCE_DIR}/include ${Eigen3_INCLUDE_DIR})

# Link libraries
target_link_libraries(MyApp PRIVATE Qt6::Widgets MyLib)

# Set target properties
set_target_properties(MyApp PROPERTIES VERSION ${PROJECT_VERSION})

# Add dependencies
add_dependencies(MyApp MyLib)

# Custom commands
add_custom_command(TARGET MyApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:Qt6::Widgets>
    $<TARGET_FILE_DIR:MyApp>)

# Installation
install(TARGETS MyApp MyLib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)
```
