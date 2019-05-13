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
int RAM::loadProcess(unsigned char *thisBuffer, int *freeFrameIndex) {
  cout << "Entering loadProcess method." << endl;
  //ramArray[*freeFrameIndex][0] = buffer[READ_SIZE];
  //int temp = *freeFrameIndex;

  for (int i = 0; i < NUM_FRAMES; i++) {
    cout << "inside" << endl;

    //cout << buffer[i] << endl;
    ramArray[*freeFrameIndex][i] = thisBuffer[i];
    cout << "error" << endl;
  }

  (*freeFrameIndex)++;
  cout << "For loop completed." << endl;
  return (*freeFrameIndex - 1);
}

void RAM::removeProcess() {

}

RAM::RAM() {
  //ramArray = new unsigned char[NUM_FRAMES][FRAME_SIZE];
  //ramArray[NUM_FRAMES][FRAME_SIZE] = {0};
}

RAM::~RAM() {

}
