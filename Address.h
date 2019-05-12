#include <string>
#include <stdio.h>
#include <iostream>
#include "Word.h"
using namespace std;

#define FRAME_SIZE 256 //256 bytes
#define NUM_FRAMES 256
#define TLB_SIZE 16
#define PAGE_SIZE 256
#define VM_SIZE 256
#define RAM_SIZE (FRAME_SIZE * NUM_FRAMES)


struct Address : Word {

  Word addy, offset, frameNum, pageNum;
/*
  Word address() {

    return addy;
  }
*/

  int displacement(string temp) {

    string substring = temp.substr(24, 8);
    int another = stoul(substring, nullptr, 2);

    offset.value = another;

    return offset.value;
  }


  int frame(string temp) {




    return frameNum.value;
  }


  int page(string temp) {

    string substring = temp.substr(16, 8);
    int another = stoul(substring, nullptr, 2);

    pageNum.value = another;

    return pageNum.value;
  }



};
