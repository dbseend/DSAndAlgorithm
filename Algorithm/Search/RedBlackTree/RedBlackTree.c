#include "RedBlackTree.h"

void RBT_RotateLeft( RBTNode** Root, RBTNode* Parent ){
    RBTNode* LeftChild = Parent->Left;

    Parent->Left = LeftChild->Right;

    if(LeftChild->Right != Nil){
        LeftChild->Right->Parent = Parent;
    }

    LeftChild->Parent = Parent->Parent;

    if(Parent->Parent == NULL){
        (*Root) = LeftChild;
    } else {
        if(Parent == Parent->Parent->Left){
            Parent->Parent->Left = LeftChild;
        } else{
            Parent->Parent->Right = LeftChild;
        }
    }

    LeftChild->Right = Parent;
    Parent->Parent = LeftChild;W

}

void RBT_RotateRight( RBTNode** Root, RBTNode* Parent ){

}
