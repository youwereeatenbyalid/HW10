#include <stdlib.h>
#include <stack>
template <typename data>
class Node{
public:
    std::pair <int , std::stack<Node>> max(std::pair <int , std::stack<Node>> a, std::pair <int , std::stack<Node>> b){
        return(a.first >= b.first)? a:b;
    } 

    std::pair <int , std::stack<Node>> height(Node<data> mynode){
        if(mynode == NULL) 
            return (0,new std::stack<Node>);
        std::pair <int , std::stack<Node>> value = max(height(mynode.left),height(mynode.right));
        value.first+=1;
        value.second.push(mynode);
        return value;
    }
    std::pair <int , std::stack<Node>> diameter(Node<data>mynode){
        if(mynode == NULL)
            return (0,new std::stack<Node>);
        std::pair <int , std::stack<Node>> leftheight = height(mynode.left);
        std::pair <int , std::stack<Node>> rightheight = height(mynode.right);
        std::pair <int , std::stack<Node>> leftdiameter = diameter(mynode.left);
        std::pair <int , std::stack<Node>> rightdiameter = diameter(mynode.right);
        
        if (max(leftdiameter,rightdiameter).first > leftheight.first+rightheight.first+1){
            return max(leftdiameter,rightdiameter);
        }else{
            leftheight.push(mynode);
            for(int i = 0; i < rightheight.first;i++){
                leftheight.push(rightheight.pop());
            }
            return leftheight;
        }
    }
    
private:
    Node* left;
    Node* right;
    data nodeData;
};
