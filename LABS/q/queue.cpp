#include "queue.h"
#include <iostream>

// O(1)
queue::queue(){
    this->head = nullptr;
    this->size = 0;
}

// O(1)
queue::queue(int data){
    this->head = new Node(data);
    this->size = 1;
}

// O(n)
queue::queue(std::vector<int> vec){
    if(vec.size() == 0){
        this->head = nullptr;
        this->size = 0;
    }else{
        this->head = new Node(vec[0]);
        Node* temp = this->head;

        for(int i = 1; i < vec.size(); i++){
            temp->next = new Node(vec[i]);
            temp = temp->next;
            // ->    de-reference + dot operator
            //temp = (*temp).next;
        }
    }
    this->size = vec.size();
}

queue::~queue(){
    // Use this instead of just deleting the head if the `Node` destructor does not delete its `next`
    /*
    Node* curr = this->head;
    Node* prev = nullptr;

    while(curr != nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    */

   // If the `node` destructor destroys the Node it points to, you do not need the code above this line
   // Note: Be sure all of your `queue` operations set a Node's `next` to `nullptr` before deleting it!
    delete this->head;

    this->head = nullptr;
}

// O(1)
// void queue::push_front(int data){
//     if(this->head == nullptr){
//         this->head = new Node(data);
//         // Assign tail
//     }else{
//         Node* tmp = new Node(data, this->head);
//         //tmp->next = this->head;
//         this->head = tmp;
//     }
//     this->size++;
// }

// O(n)
// O(1) with a tail pointer
//This is the enqueue
// void queue::push_back(int data){
//     if(this->head == nullptr){
//         this->head = new Node(data);
//         // Assign tail
//     }else{
//         Node* tmp = this->head;

//         while(tmp->next != nullptr){
//             tmp = tmp->next;
//         }

//         tmp->next = new Node(data);
//     }

//     this->size++;
// }


// O(n)
std::string queue::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}

void queue::enqueue(int data){
    
    //Same as push_back function
    if(this->head == nullptr){
        this->head = new Node(data);
        // Assign tail
    }else{
        Node* tmp = this->head;

        while(tmp->next != nullptr){
            tmp = tmp->next;
        }

        tmp->next = new Node(data);
    }

    this->size++;
}

void queue::dequeue(){

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

int  queue::peak(){

    //So long as there are elements return the first node's data 
    if(this->head != nullptr){
        return head->data;
    }
  
    return 0;
}