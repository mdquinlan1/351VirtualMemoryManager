//temp
#include <iostream>
#include <stdio.h>
#include <sys/stat.h>
#include <fstream>
using namespace std;

#define FRAME_SIZE 256 //256 bytes
#define NUM_FRAMES 256
#define TLB_SIZE 16
#define PAGE_SIZE 256
#define VM_SIZE 256
#define READ_SIZE 256
#define RAM_SIZE (FRAME_SIZE * NUM_FRAMES)

class BackingStore {

public:
  char readStore(int);

  char getBuffer();

  BackingStore();
  ~BackingStore();

private:
  char buffer[READ_SIZE];
  ifstream file;

};
