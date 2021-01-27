#include <string>
#include <vector>
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