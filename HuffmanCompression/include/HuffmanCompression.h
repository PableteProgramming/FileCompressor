#include "FrequenceMap.h"
#include "MapSorter.h"
#include <vector>
#include "Tree.h"

bool CharInString(string,string);
Node* AddNode(pair<string,int>);
vector<Node*> VectorPairToVectorNode(vector<pair<string,int>>);
void PrintContent(vector<Node*>);
vector<Node*> DeleteVectorElemTo(vector<Node*>,int);
int GetIndexToPos(vector<Node*>,Node*);
Tree CreateTree(vector<Node*>);
string GetLetterCode(Tree,string,string);
vector<pair<string,string>> HuffmanCompression(vector<string>);