#include <stdio.h>
#include "Word.h"

using namespace std;

class PageReplacementAlgorithm{
    public:
        PageReplacementAlgorithm();
        ~PageReplacementAlgorithm();
        Word findVictim();
        PageReplacementAlgorithm& getPRA();
        void updateUsage();
};