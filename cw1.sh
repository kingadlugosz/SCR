#!/bin/bash

LC_ALL=C
if [ $(date +%u) -gt 5 ]; then
echo "dzien wolny";
else
echo "dzien pracujacy";
fi
