#include "WriteFile.h"

void WriteFile::clear(){
    outfile.put(buffer);
    outfile.flush();
    buffer=0;
    bufferSize=0;
}

void WriteFile::Write(int bit){
    if(bit==-1){
        clear();
    }
    if(bufferSize==8){
        clear();
    }

    unsigned char mask=1;
    if(bit==1){
        mask= mask<<(7-bufferSize);
        buffer= buffer | mask;
    }
    else if(bit==0){
        mask= mask<<(7-bufferSize);
        mask=~mask;
        buffer= buffer & mask;
    }
    bufferSize++;
}