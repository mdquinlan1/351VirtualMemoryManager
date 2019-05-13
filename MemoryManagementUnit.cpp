#include "MemoryManagementUnit.h"
#include "definitions.h"


MemoryManagementUnit::MemoryManagementUnit() {
  populateTLB();
  populatePageTable();
  frameNumber = -999; //this is just to assume it's not valid frame at start
  freeFrameIndex = 0;
  freePageIndex = 0;
  translatedAddresses = 0;
  pageAccessCount = 0;
  pageInFaultCount = 0;
  tlbAccessCount = 0;
  tlbFaultCount = 0;

}

MemoryManagementUnit::~MemoryManagementUnit() {
  //
}

void MemoryManagementUnit::populateTLB() {
  for (int i = 0; i < TLB_SIZE; i++) {
    TLB[i].pageNum = i;
    TLB[i].frameNum = i;
  }
}

void MemoryManagementUnit::populatePageTable() {
  for (int i = 0; i < NUM_FRAMES; i++) {
    PageTable[i].pageNum = i;
    PageTable[i].frameNum = i;
  }
}

void MemoryManagementUnit::translateAddress(int givenAddy) {
  pageNumber = ((givenAddy & PAGE_MASK)>>8); //masks then shift
  offset = (givenAddy & OFFSET_MASK);
}

void MemoryManagementUnit::searchTLB() {
  for (int i = 0; i < TLB_SIZE; i++) {
    if (TLB[i].pageNum == pageNumber) {
      frameNumber = TLB[i].frameNum;
      tlbAccessCountM();
      return;
    }
  }
  if (frameNumber == -999) {
    searchPageTable();
  }
}

void MemoryManagementUnit::searchPageTable() {  //do this if TLB didnt hit

  cout << "Entered searchPageTable method." << endl;

  for (int i = 0; i < PAGE_TABLE_SIZE; i++) {  //num_frames OK for NOW
    if (PageTable[i].pageNum == pageNumber) {
      frameNumber = PageTable[i].frameNum;
      return;
    }
  }
  cout << "Attempting to go to backing store." << endl;

  if (frameNumber == -999) {    //didn't find page in PageTable
                                //now must access the BackingStore
    char temp[READ_SIZE];
    temp[READ_SIZE] = bkingstr.readStore(pageNumber);
    frameNumber = ram.loadProcess(temp, freeFrameIndex);
    //frameNumber = bkingstr.readStore(pageNumber);
    pageInFaultCountM();
  }
  
}


void MemoryManagementUnit::pageAccessCountM(){
  pageAccessCount++;
}

void MemoryManagementUnit::pageInFaultCountM() {
  pageInFaultCount++;
}


void MemoryManagementUnit::tlbAccessCountM() {
  tlbAccessCount++;
}

void MemoryManagementUnit::tlbFaultCountM() {
  tlbFaultCount++;
}

void MemoryManagementUnit::translatedAddressesM() {
  translatedAddresses++;
}

void MemoryManagementUnit::getAllCounts() {
  cout << "Page Access Count : " << pageAccessCount << endl;
  cout << "Page Fault Count : " << pageInFaultCount << endl;
  cout << "TLB Access Count : " << tlbAccessCount << endl;
  cout << "TLB Fault Count : " << tlbFaultCount << endl;
  cout << "Total translated addresses : " << translatedAddresses << endl;
}
