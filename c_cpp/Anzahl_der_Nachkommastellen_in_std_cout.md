# Anzahl der Nachkommastellen in `std::cout` konfigurieren

## 1. Einfache Nutzung von `std::setprecision`
Die Anzahl der Nachkommastellen kann mit `std::setprecision` aus der `<iomanip>`-Bibliothek konfiguriert werden.

### Beispielcode:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double value = 3.14159265358979;
    
    std::cout << "Standardausgabe: " << value << std::endl;
    std::cout << "Mit 2 Nachkommastellen: " << std::fixed << std::setprecision(2) << value << std::endl;
    std::cout << "Mit 5 Nachkommastellen: " << std::fixed << std::setprecision(5) << value << std::endl;
    
    std::cout.unsetf(std::ios::fixed); // Zurücksetzen auf System-Default
    std::cout << "Zurück auf Standard: " << value << std::endl;
    
    return 0;
}
```

## 2. Erklärung
- `std::fixed` stellt sicher, dass die Nachkommastellen genau beibehalten werden.
- `std::setprecision(n)` setzt die Anzahl der Nachkommastellen auf `n`.
- Ohne `std::fixed` gibt `std::setprecision` die Gesamtanzahl der signifikanten Stellen an.
- `std::cout.unsetf(std::ios::fixed);` setzt die Ausgabe wieder auf den System-Standard zurück.

## 3. Beispielausgabe
```
Standardausgabe: 3.14159
Mit 2 Nachkommastellen: 3.14
Mit 5 Nachkommastellen: 3.14159
Zurück auf Standard: 3.14159
```

---
