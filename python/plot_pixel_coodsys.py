import matplotlib.pyplot as plt
import numpy as np

# Constants
FOURIER_STARS = 3
FOURIER_NUM_MID_POINTS = 5
MID_POINTS_INV = 1.0 / FOURIER_NUM_MID_POINTS

# Initialize pixels array
pixels = np.zeros((FOURIER_STARS * FOURIER_NUM_MID_POINTS, 2))
pixels[:FOURIER_STARS] = [
    [1840.0, 1228.0],  # Hauptpunkt
    [1755.18, 1254.85],  # Nachbarpunkte
    [1835.92, 1378.26],  # Nachbarpunkte
]

# Compute intermediate points
for i in range(FOURIER_STARS):
    for n in range(1, FOURIER_NUM_MID_POINTS):
        index = FOURIER_STARS + i * (FOURIER_NUM_MID_POINTS - 1) + (n - 1)
        pixels[index] = (
            pixels[i] * n
            + pixels[(i + 1) % FOURIER_STARS] * (FOURIER_NUM_MID_POINTS - n)
        ) * MID_POINTS_INV

# Assign colors based on point type
colors = ["blue"]  # Hauptpunkt
colors += ["orange"] * (FOURIER_STARS - 1)  # Nachbarpunkte
colors += ["yellow"] * (len(pixels) - FOURIER_STARS)  # Interpolierte Punkte

# Split x and y coordinates
x_coords, y_coords = pixels[:, 0], pixels[:, 1]

# Plot erstellen
plt.figure(figsize=(10, 8))  # Größeres Fenster
for i in range(len(pixels)):
    plt.scatter(x_coords[i], y_coords[i], color=colors[i])

# Dummy-Punkte für die Legende hinzufügen
plt.scatter([], [], color="blue", label="Hauptpunkt")
plt.scatter([], [], color="orange", label="Nachbarpunkte")
plt.scatter([], [], color="yellow", label="Interpolierte Punkte")

# Achsen invertieren, um Pixel-KS zu simulieren
plt.gca().invert_yaxis()  # Y-Achse umdrehen
plt.gca().xaxis.tick_top()  # X-Achse oben platzieren
plt.gca().xaxis.set_label_position("top")  # X-Achsenbeschriftung oben

# Titel und Achsenbeschriftungen
plt.title("Pixel-Koordinatensystem mit Punkttypen")
plt.xlabel("x (nach rechts)")
plt.ylabel("y (nach unten)")
plt.legend()
plt.grid(True)

# Plot anzeigen
plt.show()
