#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <HuffmanCompression.h>
#include <fstream>
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