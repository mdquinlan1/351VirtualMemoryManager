#include <stdio.h>
#include <iostream>
using namespace std;
#define FRAME_SIZE 256 //256 bytes
#define NUM_FRAMES 256
#define TLB_SIZE 16
#define PAGE_SIZE 256
#define READ_SIZE 256
#define VM_SIZE 256
#define RAM_SIZE (FRAME_SIZE * NUM_FRAMES)

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
