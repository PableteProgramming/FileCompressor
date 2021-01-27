#include "main.h"
using namespace std;



int main(){
	ifstream file;
	file.open("test.txt");
	string text;
	string line;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			text += line + "\n";
		}
	}

	file.close();

	//cout << text << endl;

	vector<pair<string,string>> codes= HuffmanCompression(StringToArrayOfCharsString(text));

	// for(int i=0; i<codes.size();i++){
	// 	cout<<codes[i].first<<" : "<<codes[i].second<<endl;
	// }

	// cout << "[COMPRESSED TEXT] :" << endl;

	string compressedText = CodesToString(codes, text);

	//cout << compressedText << endl;

	ofstream file1;
	file1.open("compressedText.txt");

	file1 << compressedText;

	file1.close();

	cin.ignore();

	return 0;
}
