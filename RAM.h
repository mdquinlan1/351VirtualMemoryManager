#include <stdio.h>
#include <iostream>
#include "definitions.h"
using namespace std;


class RAM {

public:
  //int frameAvailable(); //returns the index of the available frame
                        //returns -1 otherwise

  int loadProcess(unsigned char *, int*);
  void removeProcess();

  RAM();
  ~RAM();


private:
  unsigned char ramArray[NUM_FRAMES][FRAME_SIZE];

};
