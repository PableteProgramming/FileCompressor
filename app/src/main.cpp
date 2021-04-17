#include "main.h"
using namespace std;

int main(){
	
	Huffman::File filecompressor;

	vector<pair<string,string>> codes= filecompressor.Compress("hello.exe","hello.exe.huff");

	//filecompressor.Decompress(codes,"hello.exe.huff","hellod.exe");

	cout<<"\nPress something to exit...";

	cin.ignore();

	return 0;
}
