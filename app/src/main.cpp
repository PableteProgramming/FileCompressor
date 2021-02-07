#include "main.h"
using namespace std;

int main(){

	/*cout<<"Reading input file bytes..."<<endl;

	ifstream file;
	file.open("hello.exe",ios_base::binary);

	file.seekg(0, std::ios_base::end);
	size_t length = file.tellg();
	file.seekg(0, std::ios_base::beg);

	std::vector<char> buffer;
	buffer.reserve(length);
	std::copy( std::istreambuf_iterator<char>(file),
           std::istreambuf_iterator<char>(),
           std::back_inserter(buffer) );

	file.close();

	//Now I have read all the input file bytes and store them in the buffer variable

	cout<<"\nGenerating bytes code..."<<endl;

	vector<pair<string,string>> codes= HuffmanCompression(
		StringToArrayOfCharsString(CharArrayToString(buffer)
	));

	//I get the huffman compression code for every file byte and store them in codes variable

	string compressedText = CodesToString(codes, CharArrayToString(buffer));

	//I convert it to string so that I can print it out

	cout<<"Compressed bytes: "<<compressedText<<endl;

	//I convert it to a int array

	vector<int> compTextInt= CompressedTextToVectorOfInt(compressedText);

	//I push back a -1 to symbolise the end of the array

	compTextInt.push_back(-1);

	cout<<"\nWriting to output file..."<<endl;

	//create the output file

	ofstream file1;
	file1.open("hello.exe.huff",ios_base::binary);

	//Write bytes to file

	WriteFile filewriter(file1);

	filewriter.Write(compTextInt);

	file1.close();

	cout<<"\nFinished !"<<endl;

	//Finished compressing !

	cout<<"Decompressing file..."<<endl;

	string inputfilecontent="";

	
	ifstream file2;
	file2.open("hello.exe.huff",ios_base::binary);

	file2.seekg(0, std::ios_base::end);
	size_t length1 = file2.tellg();
	file2.seekg(0, std::ios_base::beg);

	std::vector<char> buffer1;
	buffer1.reserve(length1);
	std::copy( std::istreambuf_iterator<char>(file2),
           std::istreambuf_iterator<char>(),
           std::back_inserter(buffer1) );

	file2.close();

	string inputfilecontentnew= CharArrayToString(buffer1);

	vector<int> inputfilecontentdecompressed=DecompressCompressedText(inputfilecontentnew);

	string decompressednewfilecontent= HuffmanDecompression(codes,VectorIntToString(inputfilecontentdecompressed));

	ofstream file3;
	file3.open("hellod.exe",ios_base::binary);

	file3<<decompressednewfilecontent;

	file3.close();*/

	/*Huffman::Text textcompressor;

	pair<string,vector<pair<string, string>>> textcompressorcontent= textcompressor.Compress("banana");

	cout<<"compressed banana: "<<textcompressorcontent.first<<endl;

	cout<<"decompressed banana: "<<textcompressor.Decompress(textcompressorcontent.second,textcompressorcontent.first)<<endl;*/

	Huffman::File filecompressor;

	vector<pair<string,string>> codes= filecompressor.Compress("hello.exe","hello.exe.huff");

	filecompressor.Decompress(codes,"hello.exe.huff","hellod.exe");

	cout<<"\nPress something to exit...";

	cin.ignore();

	return 0;
}
