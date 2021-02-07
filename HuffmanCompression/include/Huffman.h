#include <vector>
#include <string>
#include "FrequenceMap.h"
#include "MapSorter.h"
#include "Tree.h"
using namespace std;

namespace Huffman{
    class Text{
    private:
        vector<string> StringToStringArray(string);
        vector<Node*> VectorPairToVectorNode(vector<pair<string,int>>);
        Tree CreateTree(vector<Node*>);
        string GetLetterCode(Tree,string,string);
        int GetIndexToPos(vector<Node*>,Node*);
        vector<Node*> DeleteVectorElemTo(vector<Node*>,int);
        bool CharInString(string, string);
        string CodesToString(vector<pair<string, string>>, string);
        int GetLetterCodeIndex(vector<pair<string, string>>, string);
        bool CodeExists(vector<pair<string,string>>, string);
        string GetCharWithCode(vector<pair<string,string>>, string);
    public:
        pair<string,vector<pair<string, string>>> Compress(string);
        string Decompress(vector<pair<string, string>>,string);
    };

    class File{
    private:
        vector<pair<string, string>> codes;
        string inputfilename;
        string outputfilename;
    public:
        File(string i,string o) : inputfilename(i), outputfilename(o){};
        void Compress();
        void Decompress();
    };
};