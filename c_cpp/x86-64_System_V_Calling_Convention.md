# x86-64 System V Calling Convention

## 1. Argument-Register

<table>
<tr>
<td>

### Integer-Argumente
| Argument | Register |
|----------|---------|
| 1. | `rdi` |
| 2. | `rsi` |
| 3. | `rdx` |
| 4. | `rcx` |
| 5. | `r8` |
| 6. | `r9` |
| Mehr als 6 | Stack (ab `rsp+8`) |
|* |* |
|* |* |

</td>
<td>

### Floating-Point-Argumente
| Argument | Register |
|----------|---------|
| 1. | `xmm0` |
| 2. | `xmm1` |
| 3. | `xmm2` |
| 4. | `xmm3` |
| 5. | `xmm4` |
| 6. | `xmm5` |
| 7. | `xmm6` |
| 8. | `xmm7` |
| Mehr als 8 | Stack (ab `rsp+8`) |

</td>
</tr>
</table>

## 2. Rückgabewert-Register
| **Rückgabewert-Typ** | **Register** |
|-----------------|----------------|
| Integer, Pointer (`int`, `long`, `size_t`, `void*`) | `rax` |
| 64-Bit Integer (`int64_t`, `long long`) | `rax` |
| Floating-Point (`float`, `double`) | `xmm0` |
| `struct` ≤ 16 Byte (2 `longs`) | `rax`, `rdx` |
| `struct` > 16 Byte | Speicher (Zeiger in `rdi`) |

## 3. Stack-Alignment & Red Zone
- **Stack muss 16-Byte aligned sein** (vor `call` muss `rsp % 16 == 0` sein).
- **Red Zone**: Die unteren **128 Bytes unter `rsp`** können **ohne `push`/`pop` genutzt werden** (nicht in Windows!).

## 4. Beispiel: Integer- und Floating-Point-Argumente
```cpp
void func(int a, double b, int c, double d);
```
- `a` → `rdi`
- `b` → `xmm0`
- `c` → `rsi`
- `d` → `xmm1`

### Assembler (x86-64, GCC -O2):
```assembly
func:
    cvtsi2sd xmm2, edi  # `a` (int) → double in xmm2
    addsd xmm2, xmm0    # xmm2 = xmm2 + `b`
    cvtsi2sd xmm1, esi  # `c` (int) → double in xmm1
    addsd xmm1, xmm2    # xmm1 = xmm1 + xmm2
    addsd xmm1, xmm3    # xmm1 = xmm1 + `d`
    movapd xmm0, xmm1   # Rückgabe in xmm0
    ret
```

## 5. Vergleich: System V ABI vs. Windows x64 ABI
| **Feature** | **System V ABI (Linux/macOS)** | **Windows x64 ABI** |
|-------------|----------------|---------------|
| Integer-Register-Argumente | `rdi, rsi, rdx, rcx, r8, r9` | `rcx, rdx, r8, r9` |
| Floating-Point-Register-Argumente | `xmm0 - xmm7` | **Nur für Variadic-Funktionen!** (sonst Stack) |
| Stack-Alignment | **16-Byte aligned** | **32-Byte aligned** |
| Red Zone (128B unter `rsp`) | ✅ **Ja** | ❌ **Nein** |


