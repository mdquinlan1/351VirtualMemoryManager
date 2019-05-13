#include <stdio.h>
#include "PageTableEntry.h"
using namespace std;

struct ProcessControlBlock
{
    public:
        PageTableEntry myPageTable;
};
