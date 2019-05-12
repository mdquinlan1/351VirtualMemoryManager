#include <stdio.h>
#include <iostream>

using namespace std;

struct PageTableEntry
{
    unsigned frameNumber;
    bool valid;
};