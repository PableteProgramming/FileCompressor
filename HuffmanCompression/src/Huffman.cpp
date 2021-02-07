#include "Huffman.h"

vector<string> Huffman::Text::StringToStringArray(string s){
    vector<string> r;
    r.clear();
    
    for(int i=0; i<s.size();i++){
        string c(1,s[i]);
        r.push_back(c);
    }

    return r;
}

vector<Node*> Huffman::Text::VectorPairToVectorNode(vector<pair<string,int>> v){
    vector<Node*> r;
    r.clear();

    for(int i=0; i<v.size();i++){
        r.push_back(new Node(v[i]));
    }

    return r;
}

int Huffman::Text::GetIndexToPos(vector<Node*> v,Node* n){
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

vector<Node*> Huffman::Text::DeleteVectorElemTo(vector<Node*> v,int index){
    vector<Node*> r;
    r.clear();
    for(int i=index;i<v.size();i++){
        r.push_back(v[i]);
    }
    return r;
}

Tree Huffman::Text::CreateTree(vector<Node*> v){
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

bool Huffman::Text::CharInString(string s, string c){
    string temp="";
    for(int i=0; i<s.size();i++){
        temp=s[i];
        if(c== temp){
            return true;
        }
    }
    return false;
}

string Huffman::Text::GetLetterCode(Tree tree,string letter,string code){

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

int Huffman::Text::GetLetterCodeIndex(vector<pair<string, string>> v, string letter)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == letter)
            return i;
    }
    return -1;
}

string Huffman::Text::CodesToString(vector<pair<string, string>> v, string s)
{
    string r;
    r.clear();

    for (int i = 0; i < s.size(); i++)
    {
        int index = GetLetterCodeIndex(v, string(1, s[i]));
        if (index != -1)
        {
            r += v[index].second;
        }
    }
    return r;
}

pair<string,vector<pair<string, string>>> Huffman::Text::Compress(string word){
    string comptext="";
    FrequenceMap freqmap(StringToStringArray(word));

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

	comptext=CodesToString(codes,word);

    return make_pair(comptext,codes);
}


bool Huffman::Text::CodeExists(vector<pair<string,string>> v, string code){
    for(int i=0; i<v.size();i++){
        if(v[i].second==code){
            return true;
        }
    }
    return false;
}

string Huffman::Text::GetCharWithCode(vector<pair<string,string>> v, string code){
    string r="";
    for(int i=0; i<v.size();i++){
        if(v[i].second==code){
            r=v[i].first;
            break;
        }
    }
    return r;
}


string Huffman::Text::Decompress(vector<pair<string, string>> codes,string comptext){
    string code="";
    string r="";
    for(int i=0; i<comptext.size();i++){
        if(CodeExists(codes,code)){
            r+=GetCharWithCode(codes,code);
            code="";
            code+=comptext[i];
        }
        else{
            code+=comptext[i];
        }
    }

    if(CodeExists(codes,code)){
        r+=GetCharWithCode(codes,code);
    }

    return r;
}

void Huffman::File::Compress(){

}

void Huffman::File::Decompress(){

}