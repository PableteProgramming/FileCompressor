#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <main.h>
using namespace std;


int main(){
	cout<<"Enter a sentence: ";
	string word;
	getline(cin,word);
	
	FrequenceMap freqmap(word);

	freqmap.GetFrequence();

	MapSorter ord(freqmap.GetDict());

	ord.Sort();

	//ord.PrintContent();


	vector<Node*> nodes;
	nodes.clear();

	vector<Node*> tempNodes;
	tempNodes= VectorPairToVectorNode(ord.GetDict());

	//PrintContent(tempNodes);

	//cout<<"\n\n\n\n"<<endl;

	Tree tree=CreateTree(tempNodes);

	//GetLettercode gives Char code

	//cout<<"\n\n\n\n\n\n"<<endl;

	//tree.printContent(tree.GetRoot(),"");

	//cout<<"\n\n\n\n\n\n"<<endl;

	vector<pair<string,string>> codes;
	codes.clear();

	vector<pair<string,int>> tempfreq= freqmap.GetDict();

	for(int i=0; i<tempfreq.size();i++){
		codes.push_back(make_pair(tempfreq[i].first,
			GetLetterCode(tree,tempfreq[i].first,"")
		));
	}

	for(int i=0; i<codes.size();i++){
		cout<<codes[i].first<<" : "<<codes[i].second<<endl;
	}

	return 0;
}
