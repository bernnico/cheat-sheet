# Variadic-Funktionen in C++

## 1. Was sind Variadic-Funktionen?
Variadic-Funktionen sind **Funktionen mit einer variablen Anzahl an Argumenten**.
Die Anzahl der Parameter ist zur Compile-Zeit nicht festgelegt.

### Beispiel: `printf()` ist eine Variadic-Funktion
```cpp
printf("Wert: %d, Zahl: %f\n", 42, 3.14);
```
Hier nimmt `printf` eine variable Anzahl von Argumenten an.

---

## 2. Syntax einer Variadic-Funktion in C++
```cpp
#include <cstdarg>
#include <iostream>

void variadicExample(int count, ...) {
    va_list args;           // Argument-Liste
    va_start(args, count);  // Initialisierung

    for (int i = 0; i < count; ++i) {
        int value = va_arg(args, int);  // Hole das nächste Argument
        std::cout << "Argument " << i << ": " << value << std::endl;
    }

    va_end(args);  // Beenden
}

int main() {
    variadicExample(3, 10, 20, 30);
}
```
Hier nimmt `variadicExample()` eine variable Anzahl an `int`-Werten entgegen.

---

## 3. Argument-Übergabe in x86-64 System V Calling Convention
### Register für Argumente
| **Argument-Typ** | **Register (1. Argument)** | **Weitere Argumente** |
|----------------|----------------|----------------|
| Integer (`int`, `long`) | `rdi` | `rsi, rdx, rcx, r8, r9, dann Stack` |
| Floating-Point (`double`, `float`) | `xmm0` | `xmm1 - xmm7, dann Stack` |

### Besonderheit bei Variadic-Funktionen
1. Alle **Integer-Argumente** werden in `rdi, rsi, rdx, rcx, r8, r9` gespeichert.
2. **Floating-Point-Argumente werden zusätzlich im Stack gespeichert!**
3. Das **erste nicht-Variadic-Argument** bestimmt, ab welcher Stelle `va_list` anfängt.

#### Beispiel für Funktionsaufruf:
```cpp
void test(int a, double b, ...);
test(42, 3.14, 10, 20, 30);
```
#### Assembler (GCC -O2, x86-64)
```assembly
mov    edi, 42       # 1. Argument (int) → rdi
movsd  xmm0, [b]     # 2. Argument (double) → xmm0
lea    rdx, [rsp+32] # Variadic-Argumente liegen auf dem Stack ab `rsp+32`
call   test
```
Hier werden Variadic-Argumente nicht direkt in Registern gespeichert, sondern im Stack.

---

## 4. Alternative: Variadic Templates (C++11+)
Seit C++11 gibt es **Variadic Templates**, die `va_list` ersetzen können.
```cpp
#include <iostream>

template <typename T, typename... Args>
void printArgs(T first, Args... rest) {
    std::cout << first << std::endl;
    if constexpr (sizeof...(rest) > 0) {
        printArgs(rest...);
    }
}

int main() {
    printArgs(1, 2.5, "Hello", 'A');  // Variadic Template mit verschiedenen Typen
}
```
### Vorteile gegenüber `va_list`
✅ **Statische Typsicherheit**
✅ **Unterstützt beliebige Typen**
✅ **Compiler kann es optimieren (kein Stack-Overhead)**

---

