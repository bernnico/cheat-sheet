#!/bin/bash

OBJECT_FILE=$1

if [ -z "$OBJECT_FILE" ]; then
    echo "Usage: $0 <object-file>"
    exit 1
fi

# Symboltabelle
nm $OBJECT_FILE > ${OBJECT_FILE}_nm.txt

# Disassemblierung
objdump -d $OBJECT_FILE > ${OBJECT_FILE}_disassembly.txt
objdump -d -M intel $OBJECT_FILE > ${OBJECT_FILE}_disassembly_intel.txt

# Header-Informationen
objdump -h $OBJECT_FILE > ${OBJECT_FILE}_header.txt

# Symboltabelle mit objdump
objdump -t $OBJECT_FILE > ${OBJECT_FILE}_symbols.txt

# Alle Informationen mit readelf
readelf -a $OBJECT_FILE > ${OBJECT_FILE}_readelf.txt
# Anzeigen der Sektion-Header
#readelf -S $OBJECT_FILE > ${OBJECT_FILE}_readelf.txt
# Anzeigen der Symboltabelle
#readelf -s $OBJECT_FILE > ${OBJECT_FILE}_readelf.txt

echo "Analysis of $OBJECT_FILE is complete. Check the output files for details."
