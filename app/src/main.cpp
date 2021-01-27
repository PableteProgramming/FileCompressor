#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <HuffmanCompression.h>
#include "main.h"
using namespace std;


int main(){
	cout<<"Enter a sentence: ";
	string word;
	getline(cin,word);

	vector<pair<string,string>> codes= HuffmanCompression(StringToArrayOfCharsString(word));

	for(int i=0; i<codes.size();i++){
		cout<<codes[i].first<<" : "<<codes[i].second<<endl;
	}

	return 0;
}
