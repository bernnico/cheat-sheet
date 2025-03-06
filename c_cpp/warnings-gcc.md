## Wichtige GCC-Warnungen für C++17

Diese Liste enthält einige der wichtigsten GCC-Warnungen, die oft auf potenziell problematisches Verhalten hinweisen. Viele dieser Warnungen können durch das Flag `-Werror` (oder einzeln z.B. `-Werror=narrowing` / oder definiere eine Ausnahme mit z.B `-Wno-deprecated`) in Fehler umgewandelt werden, um die strikte Einhaltung der C++17-Standards zu gewährleisten. Um **die meisten Warnungen zu aktivieren**, kannst du das Flag `-Wall -Wextra` verwenden. Beachte, dass einige zusätzliche Warnungen (z. B. `-Wconversion`) möglicherweise explizit hinzugefügt werden müssen.

### 0. `-pedantic`
   - **Beschreibung**: Aktiviert strenge Standardkonformitätsprüfungen und warnt vor nicht standardkonformen Erweiterungen, die GCC erlaubt. Diese Option stellt sicher, dass der Code so nah wie möglich am C++-Standard bleibt.

### 1. `-Wnarrowing`
   - **Beschreibung**: Warnt bei einer Verengung (Narrowing Conversion), wenn ein Wert in einen kleineren oder inkompatiblen Typ konvertiert wird, z. B. `double` zu `float` oder `int` zu `short`.
   - **Beispiel**:
     ```cpp
     float f = {3.14159}; // führt zu einer Verengung, weil `3.14159` ein `double` ist
     ```

### 2. `-Wreturn-type`
   - **Beschreibung**: Warnt, wenn eine Funktion, die einen Rückgabewert erwartet, keinen `return`-Wert besitzt. In C++ ist dies undefiniertes Verhalten, wenn die Funktion aufgerufen wird.
   - **Beispiel**:
     ```cpp
     int foo() {
         // keine `return`-Anweisung in einer Funktion, die `int` zurückgeben soll
     } 
     ```

### 3. `-Wunused-variable`
   - **Beschreibung**: Warnt, wenn eine Variable deklariert, aber nicht verwendet wird.
   - **Beispiel**:
     ```cpp
     int x = 42; // in einer Funktion ohne Verwendungszweck.
     ```

### 4. `-Wsign-compare`
   - **Beschreibung**: Warnt bei Vergleichen zwischen signed und unsigned Werten, was zu unerwartetem Verhalten führen kann, wenn der signed-Wert negativ ist.
   - **Beispiel**:
     ```cpp
     int x = -1;
     unsigned int y = 0;
     if (x < y) { 
         // führt zu unerwartetem Verhalten, da `x` in `unsigned` konvertiert wird
     }
     ```

### 5. `-Wshadow`
   - **Beschreibung**: Warnt, wenn eine lokale Variable einen Namen hat, der eine Variable im äußeren Scope überschattet. Dies kann zu Verwirrung und Fehlern führen.
   - **Beispiel**:
     ```cpp
     int x = 10;
     void foo() {
         int x = 5;  // überschattet die äußere Variable `x`
     }
     ```

### 6. `-Wconversion`
   - **Beschreibung**: Warnt bei impliziten Konvertierungen, die zu einem Verlust von Informationen oder einem unerwarteten Verhalten führen könnten, wie z. B. bei der Konvertierung von `int` zu `float`.
   - **Beispiel**:
     ```cpp
     int x = 1000;
     short y = x; // könnte zu einem Datenverlust führen, wenn `x` zu groß ist
     ```

### 7. `-Wreorder`
   - **Beschreibung**: Warnt, wenn die Reihenfolge der Initialisierung in der Initialisierungsliste eines Konstruktors nicht der Deklarationsreihenfolge der Member-Variablen entspricht.
   - **Beispiel**:
     ```cpp
     class MyClass {
         int a;
         int b;
         MyClass() : b(1), a(2) {}  // `a` wird vor `b` initialisiert, obwohl es nach `b` in der Liste steht
     };
     ```

### 8. `-Wmaybe-uninitialized`
   - **Beschreibung**: Warnt, wenn eine Variable verwendet wird, bevor sie initialisiert wurde. Dies ist in C++ Standard-konform verboten, kann aber vom Compiler unter bestimmten Bedingungen nicht erkannt werden.
   - **Beispiel**:
     ```cpp
     int x;
     if (y > 0) x = 42;
     cout << x;  // `x` könnte nicht initialisiert sein, wenn `y <= 0`
     ```

### 9. `-Wdelete-non-virtual-dtor`
   - **Beschreibung**: Warnt, wenn ein Zeiger auf eine Basisklasse ohne virtuellen Destruktor gelöscht wird. Dies ist riskant, da der Destruktor der abgeleiteten Klasse nicht aufgerufen wird, was zu Speicherlecks führt.
   - **Beispiel**:
     ```cpp
     class Base {};
     class Derived : public Base {};
     Base *ptr = new Derived;
     delete ptr;  // Basisklasse hat keinen virtuellen Destruktor
     ```

### 10. `-Wstrict-aliasing`
   - **Beschreibung**: Warnt bei einer Verletzung der Strict-Aliasing-Regeln, die zu undefiniertem Verhalten führen kann. Diese Regeln besagen, dass Zeiger nur auf Objekte ihres eigenen Typs oder auf `char`-Typen zeigen dürfen.
   - **Beispiel**:
     ```cpp
     int i = 10;
     float *f = (float *)&i;  // Verstoß gegen Strict-Aliasing
     ```

### 11. `-Wuninitialized`
   - **Beschreibung**: Warnt, wenn eine nicht initialisierte Variable verwendet wird. Diese Warnung wird oft durch Datenflussanalyse erkannt, kann aber manchmal übersehen werden.
   - **Beispiel**:
     ```cpp
     int x;
     int y = x + 1;  // x ist nicht initialisiert
     ```

### 12. `-Wold-style-cast`
   - **Beschreibung**: Warnt bei der Verwendung von alten C-Style-Casts wie `(int)`, die in C++ als unsicher gelten. Stattdessen sollten C++-Style-Casts wie `static_cast<int>` verwendet werden.
   - **Beispiel**:
     ```cpp
     int x = (int)3.5;  // alte C-Style-Cast-Syntax
     ```
     
### 13. `-Wvla`
   - **Beschreibung**: Warnt, wenn variable-length arrays (VLAs) verwendet werden, die in C++ nicht standardkonform sind, aber von GCC als Erweiterung unterstützt werden.
   - **Beispiel**:
     ```cpp
     size_t foo(size_t size) {
         int arr[size];
         return sizeof(arr);
     }
     ```

---
