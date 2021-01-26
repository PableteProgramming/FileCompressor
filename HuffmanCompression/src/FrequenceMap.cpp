#include <iostream>
#include "FrequenceMap.h"

FrequenceMap::FrequenceMap(string s){
	dict.clear();
	word=s;
}

bool FrequenceMap::ExistInMap(string c){
	vector<pair<string,int>>::iterator it;
	for(it=dict.begin();it!=dict.end();it++){
		if(it->first==c){
			return true;
		}
	}
	return false;
}

int FrequenceMap::GetIndexOfElem(string c){
	vector<pair<string,int>>::iterator it;
	int index=0;
	for(it=dict.begin();it!=dict.end();it++){
		if(it->first==c){
			return index;
		}
		index++;
	}
	return -1;

}

void FrequenceMap::GetFrequence(){
	for(int i=0; i<word.size();i++){
		string c(1,word[i]);
		if(!ExistInMap(c)){
			//dict.insert(pair<char,int>(c,1));
			dict.push_back(pair<string,int>(c,1));
		}
		else{
			int index=GetIndexOfElem(c);
			if(index!=-1){
				dict[index].second++;
			}	
		}
	}
}

void FrequenceMap::PrintContent(){
	vector<pair<string,int>>::iterator it;
	for(it=dict.begin();it!=dict.end();it++){
		cout<<it->first<<" : "<<it->second<<endl;
	}
}
