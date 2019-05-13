//temp
#include <iostream>
#include <stdio.h>
#include <sys/stat.h>
#include <fstream>
#include "definitions.h"
using namespace std;

class BackingStore {

public:
  unsigned char * readStore(int);

  unsigned char * getBuffer();

  BackingStore();
  ~BackingStore();

private:
  unsigned char * buffer;
  ifstream file;

};
