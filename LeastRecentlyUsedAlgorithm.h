#include <stdio.h>
#include "PageReplacementAlgorithm.h"

using namespace std;

class LeastRecentlyUsedAlgorithm : PageReplacementAlgorithm {
private:
    /* Data */
public:
    LeastRecentlyUsedAlgorithm();
    ~LeastRecentlyUsedAlgorithm();
    Word findVictim();
    void updateUsage();
};