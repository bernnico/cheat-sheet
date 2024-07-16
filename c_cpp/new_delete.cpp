#include <cstdlib>
#include <iostream>

// Benutzerdefinierter 'new'-Operator
void* operator new(std::size_t size) {
    std::cout << "Custom global new: allocating " << size << " bytes\n";
    if (void* ptr = std::malloc(size)) {
        return ptr;
    }
    throw std::bad_alloc();
}

// Benutzerdefinierter 'new[]'-Operator
void* operator new[](std::size_t size) {
    std::cout << "Custom global new[]: allocating " << size << " bytes\n";
    if (void* ptr = std::malloc(size)) {
        return ptr;
    }
    throw std::bad_alloc();
}

// Benutzerdefinierter 'delete'-Operator
void operator delete(void* ptr) noexcept {
    std::cout << "Custom global delete: deallocating memory\n";
    std::free(ptr);
}

// Benutzerdefinierter 'delete[]'-Operator
void operator delete[](void* ptr) noexcept {
    std::cout << "Custom global delete[]: deallocating memory\n";
    std::free(ptr);
}

// Benutzerdefinierter 'delete'-Operator mit Größe
void operator delete(void* ptr, std::size_t size) noexcept {
    std::cout << "Custom global delete with size: deallocating " << size << " bytes\n";
    std::free(ptr);
}

// Benutzerdefinierter 'delete[]'-Operator mit Größe
void operator delete[](void* ptr, std::size_t size) noexcept {
    std::cout << "Custom global delete[] with size: deallocating " << size << " bytes\n";
    std::free(ptr);
}
