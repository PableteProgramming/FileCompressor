#include "HuffmanCompression.h"

Node* AddNode(pair<string,int> p){
    return new Node(p);
}

vector<Node*> VectorPairToVectorNode(vector<pair<string,int>> v){
    vector<Node*> r;
    r.clear();

    for(int i=0; i<v.size();i++){
        r.push_back(new Node(v[i]));
    }

    return r;
}

void PrintContent(vector<Node*> v){
    for(int i=0; i<v.size();i++){
        cout<<v[i]->GetPair().first<<" : "<<v[i]->GetPair().second<<endl;
    }
}

vector<Node*> DeleteVectorElemTo(vector<Node*> v,int index){
    vector<Node*> r;
    r.clear();
    for(int i=index;i<v.size();i++){
        r.push_back(v[i]);
    }
    return r;
}

int GetIndexToPos(vector<Node*> v,Node* n){
    if(v.size()>1){
        for(int i=0; i<v.size();i++){
            if(i>0){
                if(v[i]->GetPair().second>v[i-1]->GetPair().second){
                    if(v[i-1]->GetPair().second==n->GetPair().second){
                        return i;
                    }
                }
            }
            else if(v[i]->GetPair().second>n->GetPair().second){
                return i;
            }
        }
        return v.size()-1;
    }
    else{
        return 0;
    }
    
}

Tree CreateTree(vector<Node*> v){
    while(v.size()>1){
        Node* firstelem= v[0];
        Node* secondelem= v[1];

        v= DeleteVectorElemTo(v,2);

        Node* together(new Node(make_pair(
            (firstelem->GetPair().first+secondelem->GetPair().first),
            (firstelem->GetPair().second+secondelem->GetPair().second)
        )));

        together->setLeft(firstelem);
        together->setRight(secondelem);

        int index= GetIndexToPos(v,together);
        
        vector<Node*>::iterator it= v.begin()+index;

        v.insert(it,together);

    }

    return Tree(v[0]);
}

//string =char ; string= code
string GetLetterCode(Tree tree,string letter,string code){

    if(tree.GetRoot()->GetPair().first!=letter){
        //check left
        if(CharInString(tree.GetRoot()->GetLeft()->GetPair().first,letter)){
            code+="0";
            code= GetLetterCode(tree.GetRoot()->GetLeft(),letter,code);
        }
        else{
            //go right
            code+="1";
            code= GetLetterCode(tree.GetRoot()->GetRight(),letter,code);
        }
    }
    return code;
}

bool CharInString(string s, string c){
    string temp="";
    for(int i=0; i<s.size();i++){
        temp=s[i];
        if(c== temp){
            return true;
        }
    }
    return false;
}

vector<pair<string,string>> HuffmanCompression(vector<string> word){
	FrequenceMap freqmap(word);

	freqmap.GetFrequence();

	MapSorter ord(freqmap.GetDict());

	ord.Sort();

	vector<Node*> nodes;
	nodes.clear();

	vector<Node*> tempNodes;
	tempNodes= VectorPairToVectorNode(ord.GetDict());

	Tree tree=CreateTree(tempNodes);

	vector<pair<string,string>> codes;
	codes.clear();

	vector<pair<string,int>> tempfreq= freqmap.GetDict();

	for(int i=0; i<tempfreq.size();i++){
		codes.push_back(make_pair(tempfreq[i].first,
			GetLetterCode(tree,tempfreq[i].first,"")
		));
	}

	return codes;
}
