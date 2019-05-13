#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "MemoryManagementUnit.h"
#include "Address.h"
#include "PageTableEntry.h"

using namespace std;

#define FRAME_SIZE 256 //256 bytes
#define NUM_FRAMES 256
#define TLB_SIZE 16
#define PAGE_SIZE 256
#define VM_SIZE 256
#define RAME_SIZE (FRAME_SIZE * NUM_FRAMES)



int main() {
  
  string logicalAddress;
  string tempBinAdd;
  int logicalAddy, physicalAddy;
  Address myword, offset, frameNumber, pageNumber;

  ifstream myfile("addresses.txt");
  
  if (myfile.is_open()) {
    MemoryManagementUnit mmu;
    //BackingStore bkingstr;
    //RAM ram;

    while (getline(myfile, logicalAddress)) {
      //PERFORM THE PROGRAM ON EACH ADDRESS ONE BY ONE

      //tempBinAdd = mmu.convertToBinary(logicalAddress);
      cout << "Getting logical addy." << endl;
      logicalAddy = stoi(logicalAddress);

      cout << "Attempting translation now: " << endl;
      mmu.translateAddress(logicalAddy);
      mmu.translatedAddressesM();   //increment the counter
                                    //for # of translated addresses

      mmu.searchTLB();



      /*
      offset.value = myword.displacement(tempBinAdd);
      cout << "Offset number is: " << offset.value << endl;

      pageNumber.value = myword.page(tempBinAdd);
      cout << "Page Number of this Address: " << pageNumber.value << endl;

      bkingstr.readStore(pageNumber.value);
      cout << "Buffer value: " << bkingstr.getBuffer() << endl;

      if (ram.frameAvailable() >= 0) {
        //frame is available
        cout << "VALID FRAME FOUND" << endl;
        ram.loadProcess(bkingstr.getBuffer());



      } else if (ram.frameAvailable() == -999) {
        //frame is unavailable
        //page replacement here | offer which algorithm?
        cout << "INVALID FRAME FOUND" << endl;
      }
      */
      //doSomethingPageNumber(pageNumber.value);


      //cout << "Binary :  " << mmu.convertToBinary(logicalAddress) << endl;

    }

    myfile.close();

  } else {
    cout << "Error opening file. Exiting now." << endl << endl;
  } 
  return 0;
}
