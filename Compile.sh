#!/bin/bash
echo "Compiling"
g++ -std=c++17 -g -o0 -Wall -Wold-style-cast -Wextra -Woverloaded-virtual -I./ -o 351FinalExec Main.cpp MemoryManagementUnit.cpp BackingStore.cpp RAM.cpp
echo "Finished"
