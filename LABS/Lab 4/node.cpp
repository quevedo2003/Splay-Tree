#include "node.h"

// Default constructor
Node::Node(){
    this->data = 0;     //Default Initializes data to be 0 
    this->next = nullptr; //Default has null pointer(reached its end)
}
//One argument, the data
Node::Node(int data){
    this->data = data; //Makes data's member equal to data, gets access to private member
    this->next = nullptr; //Pointer equals nullpointer(reached its end)
}
//Two Argument, 
Node::Node(int data, Node* next){
    this->data = data;//Makes data's member equal to data, gets access to private member
    this->next = next;//Makes the next pointer member equal to whatever it is set to
}

Node::~Node(){
    // if(this->next != nullptr){ //As long as the pointer has not reached end 
    //     delete this->next;  //Delete the pointer 
    // }
}