# C++ Operator Overloading Cheatsheet

## 1 Welche Operatoren kann man überladen?
### Mathematische Operatoren
- `+`, `-`, `*`, `/`, `%`
- `+=`, `-=`, `*=`, `/=`, `%=`
- `++`, `--`

### Vergleichsoperatoren
- `==`, `!=`, `<`, `>`, `<=`, `>=`

### Logische Operatoren
- `&&`, `||`, `!`

### Bitweise Operatoren
- `&`, `|`, `^`, `~`, `<<`, `>>`
- `&=`, `|=`, `^=`, `<<=`, `>>=`

### Speicherverwaltung
- `new`, `delete`

### Zugriff und Dereferenzierung
- `[]`, `*`, `->`, `()`

### Typumwandlungsoperatoren
- `operator T()`

## 2 Syntax: Wie definiert man Operatoren?
### **Als Mitgliedsfunktion**
```cpp
class Vector {
public:
    int x, y;
    Vector(int x, int y) : x(x), y(y) {}

    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }
};
```

### **Als globale Funktion**
```cpp
Vector operator+(const Vector& lhs, const Vector& rhs) {
    return Vector(lhs.x + rhs.x, lhs.y + rhs.y);
}
```

## 3 Expliziter Aufruf eines Operators
```cpp
Vector a(1, 2), b(3, 4);
Vector c = a + b; // Normaler Aufruf
Vector d = a.operator+(b); // Expliziter Aufruf
```

## 4 Spezielle Operatoren
### **Typkonvertierung `operator T()`**
```cpp
class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {}
    operator int() const { return value; }
};
```

### **Index-Operator `operator[]`**
```cpp
class Array {
private:
    int data[10];
public:
    int& operator[](int index) { return data[index]; }
};
```

### **Funktionsaufruf `operator()`**
```cpp
class Functor {
public:
    void operator()(int x) { std::cout << "Value: " << x << std::endl; }
};
```

### **Stream-Operator `operator<<`**
```cpp
friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
    return os << "(" << v.x << ", " << v.y << ")";
}
```

### **`new` und `delete` überladen**
```cpp
class MyClass {
public:
    static void* operator new(size_t size) {
        std::cout << "Custom new\n";
        return malloc(size);5 
    static void operator delete(void* ptr) {
        std::cout << "Custom delete\n";
        free(ptr);
    }
};
```

## 5 Best Practices
**Immer `const` verwenden**, wenn der Operator das Objekt nicht verändert.
**`operator==` und `operator!=` sollten konsistent sein.**
**Globale `operator<<` für `std::ostream` nutzen.**
**`explicit operator T()` verwenden, um unbeabsichtigte Konvertierungen zu vermeiden.**


