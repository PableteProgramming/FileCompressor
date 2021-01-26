#include <vector>
#include <string>
using namespace std;


class FrequenceMap{
private:
	vector<pair<string,int>> dict;
	string word;
	bool ExistInMap(string);
	int GetIndexOfElem(string);
public:
	FrequenceMap(string);
	vector<pair<string,int>> GetDict(){ return dict;};	
	void GetFrequence();
	void PrintContent();
};
