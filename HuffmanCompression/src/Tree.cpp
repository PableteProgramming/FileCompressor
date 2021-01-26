#include "Tree.h"
#include <stdlib.h>
#include <iostream>
Tree::Tree(Node* r){
    root=r;
}

void Tree::printContent(Node* _root,string tab){
    std::cout<<tab<<_root->GetPair().first<<" : "<<_root->GetPair().second<<std::endl;
    if(_root->GetLeft()!=NULL){
        printContent(_root->GetLeft(),tab+"    ");
    }
    if(_root->GetRight()!=NULL){
        printContent(_root->GetRight(),tab+"    ");
    }
}