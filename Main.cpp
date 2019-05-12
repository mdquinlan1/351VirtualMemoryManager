#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "MemoryManagementUnit.h"
#include "Address.h"
//#include "Word.h"

using namespace std;


int main() {

  string logicalAddress;
  string tempBinAdd;
  Address myword, offset, frameNumber, pageNumber;

  ifstream myfile("addresses.txt");

  if (myfile.is_open()) {
    MemoryManagementUnit mmu;

    while (getline(myfile, logicalAddress)) {
      //PERFORM THE PROGRAM ON EACH ADDRESS ONE BY ONE

      tempBinAdd = mmu.convertToBinary(logicalAddress);


      //myword.value = stoi(logicalAddress);
      offset.value = myword.displacement(tempBinAdd);
      cout << "Offset number is: " << offset.value << endl;
      
      pageNumber.value = myword.page(tempBinAdd);
      cout << "Page Number of this Address: " << pageNumber.value << endl;
      //doSomethingPageNumber(pageNumber.value);


      //cout << "Binary :  " << mmu.convertToBinary(logicalAddress) << endl;

    }

    myfile.close();

  } else {
    cout << "Error opening file. Exiting now." << endl << endl;
  }





  return 0;
}
