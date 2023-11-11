#include "linked_list.h"
#include <iostream>


LinkedList::LinkedList(){
    this->head = nullptr; // Initialize an empty list
    this->size = 0;  
}

LinkedList::LinkedList(int data){
 this-> head = new Node(data); 
 this-> size = 1;

}

LinkedList::LinkedList(std::vector<int> vec){
    this->head = new Node(vec[0]);
    this->size = 1;
    for(unsigned int i = 1 ; i < vec.size() ; i++){
        push_back(vec[i]);
    }
    
    
}

LinkedList::~LinkedList(){
while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


void LinkedList::push_front(int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    size++;
}

void LinkedList::push_back(int data){
 Node* newNode = new Node(data);

    if (head == nullptr) {
        // If the list is empty, the new node becomes the head.
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    size++; // Increase the size of the list.
}

void LinkedList::insert(int data, int idx){
if (idx <= 0) {
        push_front(data); // Insert at the front
    } else if (idx >= size) {
        push_back(data); // Insert at the end
    } else {
        Node* newNode = new Node(data);
        Node* current = head;
        for (int i = 0; i < idx - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
}

void LinkedList::remove(int data){
 if (head == nullptr) {
        return; // List is empty, nothing to remove
    }

    if (head->data == data) {
        //Node* temp = head;
        head = head->next;
        //delete temp;
        size--;
        return; // Value found and removed
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == data) {

            Node *test = current->next->next;
            //delete current->next;
            current->next = test;
            
            return;
        }
        current = current->next; // Move to the next node
    }
}


bool LinkedList::contains(int data){
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;  
}


int LinkedList::get_size(){
    return this->size;
}

// O(n)
std::string LinkedList::to_string(){
    std::string stringified;
    Node* tmp = this->head;
        while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}
