#include <stdio.h>
using namespace std;
#define FRAME_SIZE 256
#define NUM_FRAMES 256
#define SIZE_OF_RAM (FRAME_SIZE * NUM_FRAMES)

class RAM {

public:
  bool isFrameAvailable();


private:
  int ramArray[NUM_FRAMES];

};
