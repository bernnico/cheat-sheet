### 'pkg-config'

- **Versionsinformationen**: `pkg-config --modversion <package-name>`
  - Gibt die Version des angegebenen Pakets zurück.

- **Compiler-Flags**: `pkg-config --cflags <package-name>`
  - Gibt die Compiler-Flags zurück, die zum Kompilieren eines Programms erforderlich sind, das das angegebene Paket verwendet (z.B. Include-Pfade).

- **Linker-Flags**: `pkg-config --libs <package-name>`
  - Gibt die Linker-Flags zurück, die erforderlich sind, um ein Programm mit der angegebenen Bibliothek zu verlinken (z.B. Bibliothekspfade und -namen).

- **Alle Flags**: `pkg-config --cflags --libs <package-name>`
  - Gibt sowohl die Compiler- als auch die Linker-Flags zurück, die für die Verwendung des Pakets erforderlich sind.

- **Verfügbare Variablen**: `pkg-config --print-variables <package-name>`
  - Listet alle Variablen auf, die für das angegebene Paket definiert sind.

- **Spezifische Variable**: `pkg-config --variable=<variable-name> <package-name>`
  - Gibt den Wert einer bestimmten Variable für das angegebene Paket zurück (z.B. `prefix`, `libdir`, `includedir`).

- **Abhängigkeiten**: `pkg-config --print-requires <package-name>`
  - Zeigt die Abhängigkeiten des angegebenen Pakets an, d.h. welche anderen Pakete ebenfalls installiert sein müssen.

- **Suchpfade für `.pc`-Dateien**: `pkg-config --variable pc_path pkg-config`
  - Zeigt die Verzeichnisse an, in denen `pkg-config` nach `.pc`-Dateien sucht. Dies hilft zu verstehen, wo `pkg-config` nach Paketkonfigurationsdateien sucht.

- **Setzen des Suchpfades mit `PKG_CONFIG_PATH`**: 
  - `PKG_CONFIG_PATH=/path/to/dir1:/path/to/dir2 pkg-config --cflags --libs <package-name>`
  - Mit `PKG_CONFIG_PATH` können Sie zusätzliche Verzeichnisse angeben, in denen `pkg-config` nach `.pc`-Dateien sucht. Dies ist nützlich, wenn Sie Pakete an nicht-standardmäßigen Orten installiert haben.

- **Debugging mit `PKG_CONFIG_DEBUG_SPEW`**: 
  - `export PKG_CONFIG_DEBUG_SPEW=1`
  - `pkg-config --cflags --libs <package-name>`
  - Sie können die Ausführung von `pkg-config` debuggen, um zu sehen, welche Dateien geladen werden und welche Pfade durchsucht werden.


### weiter ...
## ...
