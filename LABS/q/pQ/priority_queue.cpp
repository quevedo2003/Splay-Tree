#include "priority_queue.h"
#include <iostream>

// O(1)
priority_queue::priority_queue(){
    this->head = nullptr;
    this->size = 0;
}

// O(1)
priority_queue::priority_queue(int data){
    this->head = new priority_node(data, 0);
    this->size = 1;
}

// O(n)
priority_queue::priority_queue(std::vector<int> vec){
    
    this->head = nullptr;
    this->size = 0;

    // Assign priorities based on position
    for(int i = 0; i < vec.size(); i++){
        enqueue(vec[i], i); 
    }

}

priority_queue::~priority_queue(){
    // Use this instead of just deleting the head if the `priority_node` destructor does not delete its `next`
    /*
    priority_node* curr = this->head;
    priority_node* prev = nullptr;

    while(curr != nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    */

   // If the `priority_node` destructor destroys the priority_node it points to, you do not need the code above this line
   // Note: Be sure all of your `queue` operations set a priority_node's `next` to `nullptr` before deleting it!
    delete this->head;

    this->head = nullptr;
}


void priority_queue::enqueue(int data, int priority_value){
    
    priority_node* new_node = new priority_node(data, priority_value);

    //Same as push_back function
   if(this->head == nullptr){
        this->head = new_node;
    }
    else if(priority_value < this->head->priority_value){
        //If the new element has lower priority than the head, insert at the beginning
        new_node->next = this->head;
        this->head = new_node;
    }
    else{
        priority_node* prev = nullptr;
        priority_node* current = this->head;

        //Traverse the list to find the correct position
        while(current != nullptr && priority_value >= current->priority_value){
            prev = current;
            current = current->next;
        }

        //Insert the new node between prev and current
        prev->next = new_node;
        new_node->next = current;
    }

    this->size++;
}

void priority_queue::dequeue(){

    
     //Check if list is not empty before popping
    if(this->head != nullptr){
        //Replace what the first pointer is with the next
        this->head = head->next;
        size--;
    }
    else{
        return;
    }



}

std::pair<int,int>  priority_queue::peak(){
    int data = -100;
    int priority = -100;
    //So long as there are elements return the first priority_node's data 
    if(this->head != nullptr){
        data = this->head->data;
        priority = this->head->priority_value;
    }
  
    return std::make_pair(data, priority);
}


// O(n)
std::string priority_queue::to_string(){
    std::string stringified;
    priority_node* tmp = this->head;

    while(tmp != nullptr){
        stringified += "(" + std::to_string(tmp->data) + "," + std::to_string(tmp->priority_value) + ") ";
        tmp = tmp->next;
    }

    return stringified;
}