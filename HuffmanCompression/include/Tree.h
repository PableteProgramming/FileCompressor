#include "Node.h"
class Tree{
private:
    Node* root;
public:
    Tree(Node*);
    Node* GetRoot(){return root;};
    void printContent(Node*,string tab);
};