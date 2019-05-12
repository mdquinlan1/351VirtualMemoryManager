#include "MemoryManagementUnit.h"


MemoryManagementUnit::MemoryManagementUnit() {
  pageAccessCount = 0;
  pageInFaultCount = 0;
  tlbAccessCount = 0;
  tlbFaultCount = 0;
}

MemoryManagementUnit::~MemoryManagementUnit() {
  //
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

void MemoryManagementUnit::getAllCounts() {
  cout << "Page Access Count : " << pageAccessCount << endl;
  cout << "Page Fault Count : " << pageInFaultCount << endl;
  cout << "TLB Access Count : " << tlbAccessCount << endl;
  cout << "TLB Fault Count : " << tlbFaultCount << endl;
}



string MemoryManagementUnit::convertToBinary(string tempAddress) {
  int temp = stoi(tempAddress);

  //string binAddress = bitset<32>(temp);
  string binAddress = bitset<32>(temp).to_string();

  return binAddress;

}
