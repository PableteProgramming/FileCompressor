#include <string>
#include <vector>
#include <iostream>
#include <map>
//#include <HuffmanCompression.h>
#include <Huffman.h>
#include <fstream>
//#include "WriteFile.h"
using namespace std;

vector<string> StringToArrayOfCharsString(string s){
    vector<string> r;
    r.clear();
    
    for(int i=0; i<s.size();i++){
        string c(1,s[i]);
        r.push_back(c);
    }

    return r;
}

int GetLetterCodeIndex(vector<pair<string, string>> v, string letter)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == letter)
            return i;
    }
    return -1;
}

string CodesToString(vector<pair<string, string>> v, string s)
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

string CharArrayToString(vector<char> v){
    string r="";
    for(int i=0; i< v.size();i++){
        r+=string(1,v[i]);
    }
    return r;
}

vector<int> CompressedTextToVectorOfInt(string comptext){
    vector<int> r;
    r.clear();
    for(int i=0; i<comptext.size();i++){
        r.push_back(stoi(string(1,comptext[i])));
    }
    return r;
}

pair<int,string> GetHeaderOfCompressedString(string s, char delimiter){
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

vector<int> DecompressCompressedText(string str){
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

bool CodeExists(vector<pair<string,string>> v, string code){
    for(int i=0; i<v.size();i++){
        if(v[i].second==code){
            return true;
        }
    }
    return false;
}

string GetCharWithCode(vector<pair<string,string>> v, string code){
    string r="";
    for(int i=0; i<v.size();i++){
        if(v[i].second==code){
            r=v[i].first;
            break;
        }
    }
    return r;
}


string HuffmanDecompression(vector<pair<string,string>> v, string comptext){
    string code="";
    string r="";
    for(int i=0; i<comptext.size();i++){
        if(CodeExists(v,code)){
            r+=GetCharWithCode(v,code);
            code="";
            code+=comptext[i];
        }
        else{
            code+=comptext[i];
        }
    }

    if(CodeExists(v,code)){
        r+=GetCharWithCode(v,code);
    }

    return r;
}


string VectorIntToString(vector<int> content){
    string r="";
    for(int i=0; i<content.size();i++){
        r+= to_string(content[i]);
    }
    return r;
}