#include <iostream>
#include <string>

#if defined(_WIN32) || defined(_WIN64)
    #define OS_WINDOWS
#elif defined(__linux__)
    #define OS_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
    #define OS_MAC
#endif

#if defined(__GNUC__)
    #define COMPILER_GCC
#elif defined(_MSC_VER)
    #define COMPILER_MSVC
#elif defined(__clang__)
    #define COMPILER_CLANG
#endif

std::string getLibraryName(const std::string& fileName) {
    std::string prefix;
    std::string postfix;

    #if defined(OS_WINDOWS)
        // TODO
        // MSVC or MinGW-W64 ???
        prefix = "lib";     // or "" ???
        postfix = ".dll";   // static lib => .lib
        // import library => .dll.a
    #elif defined(OS_LINUX)
        prefix = "lib";
        postfix = ".so";    // static lib => .a
    #elif defined(OS_MAC)
        prefix = "lib";
        postfix = ".dylib"; // static lib => .a
    #endif

    // You can add specific handling for different compilers if needed
    #if defined(COMPILER_GCC)
        // GCC-specific prefix/postfix adjustments
    #elif defined(COMPILER_MSVC)
        // MSVC-specific prefix/postfix adjustments
    #elif defined(COMPILER_CLANG)
        // Clang-specific prefix/postfix adjustments
    #endif

    return prefix + fileName + postfix;
}

int main() {
    std::string fileName = "myLibrary";
    std::string libraryName = getLibraryName(fileName);
    std::cout << "Library Name: " << libraryName << std::endl;
    return 0;
}
