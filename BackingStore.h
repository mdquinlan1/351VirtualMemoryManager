//temp
#include <iostream>
#include <stdio.h>
#include <sys/stat.h>
#include <fstream>
#include "definitions.h"
using namespace std;

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
