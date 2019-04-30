#include <iostream>
#include "node.cpp"
int main(int argc, char **argv) {
    
    typedef  std::stack<Node<int>*> path;
    std::cout << "Hello, world!" << std::endl;
    Node<int> one = Node<int>(1);
    Node<int> two = Node<int>(2);
    Node<int> three = Node<int>(3);
    Node<int> four = Node<int>(4);
    Node<int> five = Node<int>(5);
    one.setLeft(&two);
    one.setRight(&three);
    two.setLeft(&four);
    three.setRight(&five);
    path height = one.height();
    while(!height.empty()){
        std::cout << height.top()->getData();
        height.pop();
    }
    return 0;
}
