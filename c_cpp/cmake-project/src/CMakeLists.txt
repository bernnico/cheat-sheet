# src/CMakeLists.txt

# Füge die Quelle-Dateien hinzu
file(GLOB SOURCES "*.cpp")

# Erstelle das ausführbare Ziel
add_executable(MyExecutable ${SOURCES})

# Setze das Ausgabeverzeichnis für die ausführbare Datei
set_target_properties(MyExecutable PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Verlinke Bibliotheken
target_link_libraries(MyExecutable ${OpenCV_LIBS} -lexiv2 Eigen3::Eigen)

