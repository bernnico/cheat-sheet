#include <iostream>

class ClassWithAllOperators {
private:
    int value;

public:
    // Konstruktoren
    ClassWithAllOperators(int v = 0) : value(v) {}
    
    // Zuweisungsoperator
    ClassWithAllOperators& operator=(const ClassWithAllOperators& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    // Arithmetische Operatoren
    ClassWithAllOperators operator+(const ClassWithAllOperators& other) const {
        return ClassWithAllOperators(value + other.value);
    }

    ClassWithAllOperators operator-(const ClassWithAllOperators& other) const {
        return ClassWithAllOperators(value - other.value);
    }

    ClassWithAllOperators operator*(const ClassWithAllOperators& other) const {
        return ClassWithAllOperators(value * other.value);
    }

    ClassWithAllOperators operator/(const ClassWithAllOperators& other) const {
        return ClassWithAllOperators(value / other.value);
    }

    ClassWithAllOperators operator%(const ClassWithAllOperators& other) const {
        return ClassWithAllOperators(value % other.value);
    }

    // Inkrement-/Dekrementoperatoren (Prä- und Postfix)
    ClassWithAllOperators& operator++() {
        ++value;
        return *this;
    }

    ClassWithAllOperators operator++(int) {
        ClassWithAllOperators temp = *this;
        ++value;
        return temp;
    }

    ClassWithAllOperators& operator--() {
        --value;
        return *this;
    }

    ClassWithAllOperators operator--(int) {
        ClassWithAllOperators temp = *this;
        --value;
        return temp;
    }

    // Vergleichsoperatoren
    bool operator==(const ClassWithAllOperators& other) const {
        return value == other.value;
    }

    bool operator!=(const ClassWithAllOperators& other) const {
        return value != other.value;
    }

    bool operator<(const ClassWithAllOperators& other) const {
        return value < other.value;
    }

    bool operator<=(const ClassWithAllOperators& other) const {
        return value <= other.value;
    }

    bool operator>(const ClassWithAllOperators& other) const {
        return value > other.value;
    }

    bool operator>=(const ClassWithAllOperators& other) const {
        return value >= other.value;
    }

    // Logische Operatoren
    bool operator!() const {
        return !value;
    }

    ClassWithAllOperators operator&&(const ClassWithAllOperators& other) const {
        return ClassWithAllOperators(value && other.value);
    }

    ClassWithAllOperators operator||(const ClassWithAllOperators& other) const {
        return ClassWithAllOperators(value || other.value);
    }

    // Bitweise Operatoren
    ClassWithAllOperators operator&(const ClassWithAllOperators& other) const {
        return ClassWithAllOperators(value & other.value);
    }

    ClassWithAllOperators operator|(const ClassWithAllOperators& other) const {
        return ClassWithAllOperators(value | other.value);
    }

    ClassWithAllOperators operator^(const ClassWithAllOperators& other) const {
        return ClassWithAllOperators(value ^ other.value);
    }

    ClassWithAllOperators operator~() const {
        return ClassWithAllOperators(~value);
    }

    ClassWithAllOperators operator<<(int shift) const {
        return ClassWithAllOperators(value << shift);
    }

    ClassWithAllOperators operator>>(int shift) const {
        return ClassWithAllOperators(value >> shift);
    }

    // Zuweisungsoperatoren (kombinierte Zuweisung)
    ClassWithAllOperators& operator+=(const ClassWithAllOperators& other) {
        value += other.value;
        return *this;
    }

    ClassWithAllOperators& operator-=(const ClassWithAllOperators& other) {
        value -= other.value;
        return *this;
    }

    ClassWithAllOperators& operator*=(const ClassWithAllOperators& other) {
        value *= other.value;
        return *this;
    }

    ClassWithAllOperators& operator/=(const ClassWithAllOperators& other) {
        value /= other.value;
        return *this;
    }

    ClassWithAllOperators& operator%=(const ClassWithAllOperators& other) {
        value %= other.value;
        return *this;
    }

    ClassWithAllOperators& operator&=(const ClassWithAllOperators& other) {
        value &= other.value;
        return *this;
    }

    ClassWithAllOperators& operator|=(const ClassWithAllOperators& other) {
        value |= other.value;
        return *this;
    }

    ClassWithAllOperators& operator^=(const ClassWithAllOperators& other) {
        value ^= other.value;
        return *this;
    }

    ClassWithAllOperators& operator<<=(int shift) {
        value <<= shift;
        return *this;
    }

    ClassWithAllOperators& operator>>=(int shift) {
        value >>= shift;
        return *this;
    }

    // Array-Subscript-Operator (Indexierung)
    int& operator[](int index) {
        // Angenommen, wir haben nur eine Variable. Normalerweise würde dies auf ein Array oder einen Container zugreifen.
        // Dies ist hier nur ein Beispiel, das in der Realität anders implementiert werden sollte.
        return value;
    }

    // Dereferenzierungsoperator
    int& operator*() {
        return value;
    }

    // Funktionsaufrufoperator
    void operator()() const {
        std::cout << "MyClass with value: " << value << std::endl;
    }
};

int main() {
    ClassWithAllOperators obj1(10), obj2(20);
    
    // Beispiele für den Einsatz der Operatoren
    ClassWithAllOperators result = obj1 + obj2;
    ++obj1;
    obj2--;
    bool isEqual = (obj1 == obj2);
    int indexedValue = obj1[0];
    *obj1 = 30;
    obj1();

    return 0;
}
