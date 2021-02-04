#include <fstream>
#include <vector>
using namespace std;

class WriteFile{
private:
    char buffer;
    int bufferSize;
    ostream &outfile;
public:
    WriteFile(ostream& _outfile):outfile(_outfile), buffer(0),bufferSize(0){};
    void Write(vector<int>);
};