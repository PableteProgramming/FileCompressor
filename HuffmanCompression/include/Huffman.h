#include <vector>
#include <string>
#include <fstream>
#include "FrequenceMap.h"
#include "MapSorter.h"
#include "Tree.h"
#include "WriteFile.h"
using namespace std;

namespace Huffman{
    class Utilities{
    protected:
        string UtilityDecompress(vector<pair<string, string>>,string);
        vector<pair<string,string>> GetCodes(vector<string>);
        string CodesToString(vector<pair<string, string>>, string);
    private:
        vector<Node*> VectorPairToVectorNode(vector<pair<string,int>>);
        Tree CreateTree(vector<Node*>);
        string GetLetterCode(Tree,string,string);
        vector<Node*> DeleteVectorElemTo(vector<Node*>,int);
        bool CharInString(string, string);
        int GetIndexToPos(vector<Node*>,Node*);
        int GetLetterCodeIndex(vector<pair<string, string>>, string);
        bool CodeExists(vector<pair<string,string>>, string);
        string GetCharWithCode(vector<pair<string,string>>, string);
    };

    class Text : Utilities{
    private:
        vector<string> StringToStringArray(string);
    public:
        pair<string,vector<pair<string, string>>> Compress(string);
        string Decompress(vector<pair<string, string>>,string);
    };

    class File : Utilities{
    private:
        vector<string> StringToArrayOfCharsString(string);
        string CharArrayToString(vector<char>);
        vector<int> CompressedTextToVectorOfInt(string);
        vector<int> DecompressCompressedText(string);
        pair<int,string> GetHeaderOfCompressedString(string, char);
        string VectorIntToString(vector<int>);
    public:
        vector<pair<string, string>> Compress(string,string);
        void Decompress(vector<pair<string, string>>,string,string);
    };
};