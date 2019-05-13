#include <stdio.h>
#include "PageReplacementAlgorithm.h"
using namespace std;

struct FirstInFirstOutAlgorithm : PageReplacementAlgorithm
{
    public:
        FirstInFirstOutAlgorithm();
        Word findVictim() // We don't need to include word. Its already included in PageReplacementAlgorithm.h
        {
            return front;
        }
    private:
        Word front;
};
