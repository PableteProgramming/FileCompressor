#include "WriteFile.h"

void WriteFile::Write(vector<int> compressedText){
    int buffersize=0;
    char buffer=0;
    int bit;
    string r="";

    for(int i=0;i<compressedText.size();i++){
        bit=compressedText[i];
        if(bit==-1){
            r+=buffer;
        }
        if(buffersize==8){
            r+=buffer;
            buffer=0;
            buffersize=0;
        }

        unsigned char mask=1;
        if(bit==1){
            mask= mask<<(7-buffersize);
            buffer= buffer | mask;
        }
        else if(bit==0){
            mask= mask<<(7-buffersize);
            mask=~mask;
            buffer= buffer & mask;
        }
        buffersize++;

    }
    r= to_string(buffersize)+"\n"+r;
    outfile<< r;
}