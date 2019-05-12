#include <stdio.h>
#include "Word.h"

using namespace std;

class PageReplacementAlgorithm{
    public:
        ~PageReplacementAlgorithm();
        Word findVictim();
        PageReplacementAlgorithm& getPRA();
        void updateUsage();
    
    protected:
        PageReplacementAlgorithm();
};