#include <vector>
#include <iostream>
using namespace std;
class MapSorter{
private:
    vector<pair<string,int>> m;

public:
    MapSorter(vector<pair<string,int>>);
    void Sort(bool o=false);
    vector<pair<string,int>> GetDict(){return m;};
    void PrintContent();
};