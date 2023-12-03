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
    tree.toJson(jsonStream);
    std::cout << jsonStream.str() << std::endl;


}
