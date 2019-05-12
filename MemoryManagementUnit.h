#include <stdio.h>
#include <iostream>
#include <string>
#include <bitset>
//#include "Word.h"
using namespace std;


class MemoryManagementUnit {

public:

  struct PageFault {
    //Word pageNumber;

  };

  void clearTLB();

  void pageAccessCountM();
  void pageInFaultCountM();

  void tlbAccessCountM();
  void tlbFaultCountM();

  void getAllCounts();


  string convertToBinary(string);

  MemoryManagementUnit();
  ~MemoryManagementUnit();

private:
  int pageAccessCount, pageInFaultCount, tlbAccessCount,
      tlbFaultCount;

};
