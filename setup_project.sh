#!/bin/bash

# create folders
mkdir -p src include

# create empty .c source files
touch src/main.c
touch src/filelist.c
touch src/siglist.c
touch src/scan.c
touch src/cleanup.c

# create empty .h header files
touch include/filelist.h
touch include/siglist.h
touch include/scan.h
touch include/cleanup.h

# create Makefile and README if not already there
touch Makefile README.md

echo "✅ All project files and folders created."

