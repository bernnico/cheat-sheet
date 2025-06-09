# STM32 Sensorfusion System Overview

## ✨ Sensors and Their Data

| Sensor        | Type         | Data (3D)                            | Purpose                        |
| ------------- | ------------ | ------------------------------------ | ------------------------------ |
| **LSM6DSO**   | Gyro + Accel | ω = \[gx, gy, gz], a = \[ax, ay, az] | Orientation, Tilt, Rotation    |
| **LIS2MDL**   | Magnetometer | m = \[mx, my, mz]                    | Compass (Heading)              |
| **LPS22HH**   | Barometer    | Pressure (hPa)                       | Relative altitude              |
| **GPS**       | GNSS         | Lat, Lon, Alt, Time                  | Absolute position and height   |
| **RTC/Clock** | Time source  | UTC time, seconds                    | Timestamp / Drift compensation |

---

## ✏️ Desired Outputs

| Output                                          | Sensors Used          | Method                          |
| ----------------------------------------------- | --------------------- | ------------------------------- |
| **Orientation** (Pitch, Roll, Yaw / Quaternion) | Gyro + Accel + Magnet | Madgwick / Mahony Filter        |
| **Heading (Compass)**                           | Magnet + Accel        | Tilt-compensated heading        |
| **Tilt (Pitch/Roll)**                           | Accel + Gyro          | Angle from a + drift correction |
| **Height (relative)**                           | Barometer             | Pressure-based ISA formula      |
| **Absolute Alt./Position**                      | GPS + Baro            | GPS correction / fusion         |

---

## 🔧 Fusion / Mathematical Flow

### 1. Gyroscope Integration

```math
\dot{q} = \frac{1}{2} q \otimes \omega
\Rightarrow q(t+dt) = q(t) + \dot{q} \cdot dt
```

* Use: `arm_math.h` (custom quaternion multiply may be needed)

### 2. Accel + Magnet → Reference Vectors

* Derive gravity and magnetic north vectors
* Use for correcting orientation
* Use: `math.h` (`atan2f`, `sqrtf`, etc.)

### 3. Sensor Fusion (Madgwick / Mahony)

* Use custom implementation
* Use `arm_math.h` for vector/matrix ops

### 4. Height from Barometer

```math
h = 44330 \cdot \left(1 - \left(\frac{P}{P_0}\right)^{1/5.255}\right)
```

* Use: `arm_pow_f32` or `powf` (performance dependent)

### 5. Tilt-Compensated Compass

```math
theta = \text{atan2}(m_y \cos(\phi) - m_z \sin(\phi), \dots)
```

* Use: `math.h::atan2f` preferred

---

## 💡 Recommendations

| Category       | Suggested Library                |
| -------------- | -------------------------------- |
| Linear Algebra | `arm_math.h` (matrices, vectors) |
| Trigonometry   | `math.h` (`atan2f`, `acosf`)     |
| Quaternions    | Own implementation (flexible)    |
| Filters        | Own (Madgwick, Mahony, Kalman)   |

---
### 6. References
[Cortex-M4 Technical Reference Manual r0p0](https://developer.arm.com/documentation/ddi0439/b)

