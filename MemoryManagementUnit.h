#include <stdio.h>
#include <iostream>
#include <string>
#include <bitset>
#include "RAM.h"
#include "BackingStore.h"
using namespace std;


class MemoryManagementUnit {

public:

//stores page number and frame number
  struct PageFrame {
    int pageNum;
    int frameNum;
  };

  void searchTLB();
  void populateTLB();
  void populatePageTable();
  void searchPageTable();

  int physicalAddress();

  //void insertIntoTLB(pageNumber, frameNumber);

  void translateAddress(int);

  void pageAccessCountM();
  void pageInFaultCountM();

  void tlbAccessCountM();
  void tlbFaultCountM();

  void translatedAddressesM();

  void getAllCounts();


  MemoryManagementUnit();
  ~MemoryManagementUnit();

private:
  int pageAccessCount, pageInFaultCount, tlbAccessCount,
      tlbFaultCount, translatedAddresses;

  int pageNumber, offset, frameNumber;
  int *freeFrameIndex, *freePageIndex;
  BackingStore bkingstr;
  RAM ram;
  PageFrame TLB[TLB_SIZE];
  PageFrame PageTable[NUM_FRAMES];

};
