#include "MapSorter.h"

MapSorter::MapSorter(vector<pair<string,int>> _m){
    m=_m;
}

void MapSorter::Sort(bool o){
    for(int i=0; i<m.size();i++){
        for(int j=i+1; j<m.size();j++){
            if(m[i].second< m[j].second && o){
                pair<string,int> temp= m[i];
                m[i]=m[j];
                m[j]=temp;
            }
            else if(m[i].second> m[j].second && !o){
                pair<string,int> temp= m[j];
                m[j]=m[i];
                m[i]=temp;
            }
        }
    }
}

void MapSorter::PrintContent(){
	vector<pair<string,int>>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		cout<<it->first<<" : "<<it->second<<endl;
	}
}