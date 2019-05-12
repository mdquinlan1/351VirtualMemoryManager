//temp
#include "RAM.h"
/*
int RAM::frameAvailable() {
  for (int i = 0; i < NUM_FRAMES; i++) {
    if (ramArray[i] < 0) {
      ramArray[i] = i;
      return i;
    }
  }
  return -999; //no empty frame was found
}
*/
int RAM::loadProcess(char buffer[], int *freeFrameIndex) {
  cout << "Entering loadProcess method." << endl;
  for (int i = 0; i < READ_SIZE; i++) {
    ramArray[*freeFrameIndex][i] = buffer[i];
  }
  (*freeFrameIndex)++;
  cout << "For loop completed." << endl;
  return 1;
}

void RAM::removeProcess() {

}

RAM::RAM() {
  //ramArray[NUM_FRAMES][FRAME_SIZE] = {0};
}

RAM::~RAM() {

}
