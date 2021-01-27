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

	cout << text << endl;
	

	vector<pair<string,string>> codes= HuffmanCompression(StringToArrayOfCharsString(text));

	for(int i=0; i<codes.size();i++){
		cout<<codes[i].first<<" : "<<codes[i].second<<endl;
	}

	cin.ignore();

	return 0;
}
