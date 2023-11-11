#include "priority_node.h"

// Default constructor
priority_node::priority_node(){
    this->data = 0;
    this->priority_value = 0;
    this->next = nullptr;
}

priority_node::priority_node(int data, int priority_value){
    this->data = data;
    this->priority_value = priority_value;
    this->next = nullptr;
}

priority_node::priority_node(int data, int priority_value, priority_node* next){
    this->data = data;
    this->priority_value = priority_value;
    this->next = next;
}

priority_node::~priority_node(){
    if(this->next != nullptr){
        delete this->next;
    }
}