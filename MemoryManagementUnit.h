#include <stdio.h>
#include <iostream>
#include <string>
#include <bitset>
#include "RAM.h"
#include "BackingStore.h"
using namespace std;

#define FRAME_SIZE 256 //256 bytes
#define NUM_FRAMES 256
#define TLB_SIZE 16
#define PAGE_SIZE 256
#define PAGE_TABLE_SIZE 256
#define VM_SIZE 256
#define RAM_SIZE (FRAME_SIZE * NUM_FRAMES)
#define PAGE_MASK 0xFFFF
#define OFFSET_MASK 0xFF


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
