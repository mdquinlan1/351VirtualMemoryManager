#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "definitions.h"
#include "MemoryManagementUnit.h"
#include "Address.h"

using namespace std;


int main(int argc, char *argv[]) {
  
  if(argc != 2){
    cout << "Please provide an input file. \nUsage: ./351FinalExec <inputfilepath>.txt" << endl;
    return -1;
  }
  string filename = argv[1];

  string logicalAddress;
  int logicalAddy, physicalAddy;
  Address myword, offset, frameNumber, pageNumber;

  ifstream myfile(filename);
  
  if (myfile.is_open()) {
    MemoryManagementUnit mmu;
    
    while (getline(myfile, logicalAddress)) {
      //PERFORM THE PROGRAM ON EACH ADDRESS ONE BY ONE
      logicalAddy = stoi(logicalAddress);
      
      mmu.translateAddress(logicalAddy);

      //increment the counter for # of translated addresses
      mmu.translatedAddressesM();
      

      mmu.searchTLB();

    }
    myfile.close();
    mmu.getAllCounts();
  } 
  else{
    cout << "Error opening file. Exiting now." << endl << endl;
  } 
  return 0;
}
