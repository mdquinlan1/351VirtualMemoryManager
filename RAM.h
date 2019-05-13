#include <stdio.h>
#include <iostream>
#include "definitions.h"
using namespace std;


class RAM {

public:
  //int frameAvailable(); //returns the index of the available frame
                        //returns -1 otherwise

  int loadProcess(char [], int*);
  void removeProcess();

  RAM();
  ~RAM();


private:
  int ramArray[NUM_FRAMES][FRAME_SIZE];

};
