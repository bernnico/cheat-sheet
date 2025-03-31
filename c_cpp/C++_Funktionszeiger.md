## C++ Funktionszeiger

### 1. Basis-Schema
```cpp
<Rueckgabetyp> (*<Name>)(<Parameter>);
```
- Von **Bezeichner (Name) nach außen** lesen
- Klammern sind wichtig: `(*name)` bindet `*` an den Namen, nicht an den Rueckgabetyp

Beispiel:
```cpp
int (*f)(double);  // f ist ein Zeiger auf Funktion: double -> int
```

---

### 2. Array von Funktionszeigern
```cpp
<Rueckgabetyp> (*<Name>[N])(<Parameter>);
```
Beispiel:
```cpp
void (*handlers[3])();
// Array mit 3 Zeigern auf Funktionen ohne Parameter, die void zurueckgeben
```

---

### 3. Funktionszeiger mit Rueckgabe: Zeiger auf C-Array
```cpp
<Elementtyp> (*(*<Name>)(<Parameter>))[Arraygroesse];
```
Beispiel:
```cpp
int (*(*f)())[3];  // f ist ein Zeiger auf Funktion, die Zeiger auf int[3] zurueckgibt
```

---

### 4. Funktionszeiger mit Rueckgabe: Referenz auf C-Array
```cpp
<Elementtyp> (&(*<Name>)(<Parameter>))[Arraygroesse];
```
Beispiel:
```cpp
int (&(*f)())[3];  // f ist ein Zeiger auf Funktion, die Referenz auf int[3] zurueckgibt
```

---

### 5. Verschachtelte Funktionszeiger
```cpp
<Rueckgabetyp> (*(*<Name>)(<P1>))(P2);
```
Beispiel:
```cpp
int (*(*f)(double))(int);  // f nimmt double, gibt Funktionszeiger auf int(int) zurueck
```

#### Theoretische Tiefe
> Funktionszeiger koennen theoretisch beliebig geschachtelt werden:
```cpp
int (*(*(*f)())())();  // 3 Ebenen tief
```
Praktisch aber unlesbar – besser: `using`, `typedef` oder `std::function` verwenden.

---

### 6. Zeiger- und Referenz-Kombinationen (Parameter)

| Deklaration                 | Bedeutung                                      |
|----------------------------|------------------------------------------------|
| `int*& rp`                 | Referenz auf Zeiger auf int (const int/*const)|

---

### 7. typedef vs. using
```cpp
// using (C++11+)
using funcPtr = void(*)();

// typedef (C & C++)
typedef void (*funcPtr)();
```

> Hinweis: `typedef void(*)() funcPtr;` ist **ungueltig**, weil der Name an falscher Stelle steht.

---

