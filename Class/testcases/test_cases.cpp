#include "splay_tree.h"
#include <iostream>
#include <string>
#include <fstream>


int main(){

    STree tree;

    //Testing basic operations
    tree.insert("apple");
    tree.insert("banana");
    tree.insert("orange");

    //Test splaying behavior
    tree.splaySearch("banana");

    //Testing preorder
    tree.preOrder();

    tree.dot_gen("splay_tree.dot");

    //Generation of json string to console
    std::ostringstream jsonStream;
    std::string jsonString = tree.toJson();
    std::cout << jsonString << std::endl;


}
