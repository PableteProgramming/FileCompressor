#include <stdlib.h>
#include <utility>
#include <string>
using namespace std;
class Node{
private:
    Node* right;
    Node* left;
    pair<string,int> p;
public:
    Node(pair<string,int>);
    void setRight(Node*);
    void setLeft(Node*);
    void setPair(pair<string,int>);
    Node* GetRight(){return right;};
    pair<string,int> GetPair(){return p;};
    Node* GetLeft(){return left;};
};