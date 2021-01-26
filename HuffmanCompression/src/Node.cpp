#include "Node.h"
using namespace std;
Node::Node(pair<string,int> _p){
    p=_p;
    left=NULL;
    right=NULL;
}

void Node::setRight(Node* _right){
    right=_right;
}

void Node::setLeft(Node* _left){
    left=_left;
}

void Node::setPair(pair<string,int> _p){
    p=_p;
}