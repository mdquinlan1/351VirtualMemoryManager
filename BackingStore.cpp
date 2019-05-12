#include "RAM.h"
#include "BackingStore.h"

char BackingStore::readStore(int pageNumber) {
  ifstream file("BACKING_STORE.bin", ios::in | ios::binary);

  if (file.is_open()) {
    cout << "File Opened, now reading file." << endl;

    file.seekg(READ_SIZE * pageNumber, ios::beg);

    //file.read(buffer, READ_SIZE);
    file.read(buffer, READ_SIZE);
    file.close();
    cout << "File closed, now returning buffer to caller." << endl;

    return buffer[READ_SIZE];

  } else {
    cout << "Error opening file." << endl;
    //return;
  }
  file.close();
}

char BackingStore::getBuffer() {
  return buffer[READ_SIZE];
}

BackingStore::BackingStore() {
  //ifstream file("BACKING_STORE.bin", ios::in | ios::binary);
}

BackingStore::~BackingStore() {
  //file.close();
}
