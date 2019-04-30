#include <stdlib.h>
#include <stack>
template <typename data>

class Node{
public:
    
    
    Node(data newdata, Node* myleft = NULL, Node* myright = NULL):nodeData(newdata),left(myleft),right(myright){}
    //getters and setters
    void setLeft(Node* myleft){left = myleft;}
    void setRight(Node* myright){right = myright;}
    Node* getLeft(){return left;}
    Node* getRight(){return right;}
    data getData(){
        return nodeData;
    }
    
    //definition of a "node pair," an integer and a stack of nodes
    typedef std::stack<Node*> path;
    //compares a pair and returns whichever has the greatest integer value.
    path max(path a, path b){
        return(a.size() >= b.size())? a:b;
    }
    //return the maximum height.*
    path height(){
        path leftheight;
        path rightheight;
        if(left!=NULL){leftheight = left->height();}
        if(right!=NULL){rightheight = right->height();}
        path value = max(leftheight,rightheight);
        //increments its count by one, adds the current node to the stack.
        value.push(this);
        //returns the pair.
        return value;
    
    }

    
private:
    data nodeData;
    Node* left = NULL;
    Node* right = NULL;

};
