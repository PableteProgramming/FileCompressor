#include "Huffman.h"


vector<pair<string,string>> Huffman::Utilities::GetCodes(vector<string> word){
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

string Huffman::Utilities::UtilityDecompress(vector<pair<string, string>> codes,string comptext){
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


vector<string> Huffman::Text::StringToStringArray(string s){
    vector<string> r;
    r.clear();
    
    for(int i=0; i<s.size();i++){
        string c(1,s[i]);
        r.push_back(c);
    }

    return r;
}

vector<Node*> Huffman::Utilities::VectorPairToVectorNode(vector<pair<string,int>> v){
    vector<Node*> r;
    r.clear();

    for(int i=0; i<v.size();i++){
        r.push_back(new Node(v[i]));
    }

    return r;
}

int Huffman::Utilities::GetIndexToPos(vector<Node*> v,Node* n){
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

vector<Node*> Huffman::Utilities::DeleteVectorElemTo(vector<Node*> v,int index){
    vector<Node*> r;
    r.clear();
    for(int i=index;i<v.size();i++){
        r.push_back(v[i]);
    }
    return r;
}

Tree Huffman::Utilities::CreateTree(vector<Node*> v){
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

bool Huffman::Utilities::CharInString(string s, string c){
    string temp="";
    for(int i=0; i<s.size();i++){
        temp=s[i];
        if(c== temp){
            return true;
        }
    }
    return false;
}

string Huffman::Utilities::GetLetterCode(Tree tree,string letter,string code){

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

int Huffman::Utilities::GetLetterCodeIndex(vector<pair<string, string>> v, string letter)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == letter)
            return i;
    }
    return -1;
}

string Huffman::Utilities::CodesToString(vector<pair<string, string>> v, string s)
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
    vector<pair<string,string>> codes=GetCodes(StringToStringArray(word));

	comptext=CodesToString(codes,word);

    return make_pair(comptext,codes);
}


bool Huffman::Utilities::CodeExists(vector<pair<string,string>> v, string code){
    for(int i=0; i<v.size();i++){
        if(v[i].second==code){
            return true;
        }
    }
    return false;
}

string Huffman::Utilities::GetCharWithCode(vector<pair<string,string>> v, string code){
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
    return UtilityDecompress(codes,comptext);
}

vector<string> Huffman::File::StringToArrayOfCharsString(string s){
    vector<string> r;
    r.clear();
    
    for(int i=0; i<s.size();i++){
        string c(1,s[i]);
        r.push_back(c);
    }

    return r;
}

string Huffman::File::CharArrayToString(vector<char> v){
    string r="";
    for(int i=0; i< v.size();i++){
        r+=string(1,v[i]);
    }
    return r;
}

vector<int> Huffman::File::CompressedTextToVectorOfInt(string comptext){
    vector<int> r;
    r.clear();
    for(int i=0; i<comptext.size();i++){
        r.push_back(stoi(string(1,comptext[i])));
    }
    return r;
}

vector<pair<string, string>> Huffman::File::Compress(string i, string o){

    vector<pair<string,string>> codes;
    codes.clear();

	ifstream file;
	file.open(i,ios_base::binary);

    if(!file){
        cout<<"Error while opening: "<<i<<endl;
        return codes;
    }

	file.seekg(0, std::ios_base::end);
	size_t length = file.tellg();
	file.seekg(0, std::ios_base::beg);

	std::vector<char> buffer;
	buffer.reserve(length);
	std::copy( std::istreambuf_iterator<char>(file),
           std::istreambuf_iterator<char>(),
           std::back_inserter(buffer) );

	file.close();

    codes= GetCodes(
		StringToArrayOfCharsString(CharArrayToString(buffer)
	));

    string compressedText = CodesToString(codes, CharArrayToString(buffer));

    vector<int> compTextInt= CompressedTextToVectorOfInt(compressedText);

    compTextInt.push_back(-1);

    ofstream file1;
	file1.open(o,ios_base::binary);

    if(!file1){
        cout<<"Error while opening: "<<o<<endl;
        return codes;
    }

    WriteFile filewriter(file1);

	filewriter.Write(compTextInt);

	file1.close();

    return codes;

}

pair<int,string> Huffman::File::GetHeaderOfCompressedString(string s, char delimiter){
    pair<int,string> r;
    string header;
    string content;
    for(int i=0; i<s.size();i++){
        if(s[i]!=delimiter){
            header+=s[i];
        }
        else{
            for(int j=i+1;j<s.size();j++){
                content+= s[j];
            }
            break;
        }
    }
    r= make_pair(stoi(header),content);
    return r;
}

vector<int> Huffman::File::DecompressCompressedText(string str){
    pair<int,string> content= GetHeaderOfCompressedString(str,'\n');
    int endcharsTodelete= content.first-1;
    string s= content.second;
    vector<int> r;
    r.clear();
    char c;
    for(int i=0; i<s.size();i++){
        c=s[i];
        for(int i=7;i>=0;i--){
            r.push_back((c >> i) & 1);
        }
    }

    for(int i=0; i<(8-endcharsTodelete);i++){
        r.pop_back();
    }

    return r;
}

string Huffman::File::VectorIntToString(vector<int> content){
    string r="";
    for(int i=0; i<content.size();i++){
        r+= to_string(content[i]);
    }
    return r;
}

void Huffman::File::Decompress(vector<pair<string, string>> codes,string i,string o){

    ifstream file;
	file.open(i,ios_base::binary);

    if(!file){
        cout<<"Error while opening: "<<i<<endl;
        return;
    }    

	file.seekg(0, std::ios_base::end);
	size_t length1 = file.tellg();
	file.seekg(0, std::ios_base::beg);

	std::vector<char> buffer;
	buffer.reserve(length1);
	std::copy( std::istreambuf_iterator<char>(file),
           std::istreambuf_iterator<char>(),
           std::back_inserter(buffer) );

	file.close();

    string inputfilecontentnew= CharArrayToString(buffer);

	vector<int> inputfilecontentdecompressed=DecompressCompressedText(inputfilecontentnew);

    string decompressednewfilecontent= UtilityDecompress(codes,VectorIntToString(inputfilecontentdecompressed));

    ofstream file3;
    if(!file3){
        cout<<"Error while opening: "<<o<<endl;
        return;
    } 

	file3.open(o,ios_base::binary);

	file3<<decompressednewfilecontent;

	file3.close();
}