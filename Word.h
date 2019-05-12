#include <stdio.h>
#include <stdint.h>
using namespace std;

#define FRAME_SIZE 256 //256 bytes
#define NUM_FRAMES 256
#define TLB_SIZE 16
#define PAGE_SIZE 256
#define VM_SIZE 256
#define RAM_SIZE (FRAME_SIZE * NUM_FRAMES)


struct Word {

  int value;

};
