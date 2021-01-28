#include "main.h"
using namespace std;



int main(){

	cout<<"Reading input file bytes..."<<endl;

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

	cout<<"\nGenerating bytes code..."<<endl;

	vector<pair<string,string>> codes= HuffmanCompression(
		StringToArrayOfCharsString(CharArrayToString(buffer)
	));

	string compressedText = CodesToString(codes, CharArrayToString(buffer));

	cout<<"\nWriting in output file..."<<endl;

	ofstream file1;
	file1.open("hello.exe.huff");

	file1 << compressedText;

	file1.close();

	cout<<"\nFinished !"<<endl;

	cout<<"\nPress something to exit...";

	cin.ignore();

	return 0;
}
