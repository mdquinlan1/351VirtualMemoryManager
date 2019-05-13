#include <stdio.h>

using namespace std;

class MemoryManager{
private:
    MemoryManager();
public:
    MemoryManager();
    ~MemoryManager();
    MemoryManager& instance();
    MemoryManager& operator = (MemoryManager& otherM);
    void pageIn();
};