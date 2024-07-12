#!/bin/bash

# ((...)) or 'let'

a=5
b=3

# Addition
# ((...))
(( sum = a + b ))
echo "Summe: $sum"

# let
let "sumLet = a + b"
echo "Summe: $sumLet"

# And so roth with -, *, /, %.
