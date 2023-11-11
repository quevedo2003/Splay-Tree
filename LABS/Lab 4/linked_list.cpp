#include "linked_list.h"
#include <iostream>

// Default linked list constructor has 0 elements 
LinkedList::LinkedList(){
    this->head = nullptr; 
    this->size = 0;
}

//One argument constructor for linked list has head pointing to data and size 1 
LinkedList::LinkedList(int data){
    this->head = new Node(data);
    this->size = 1;
}

//Vector argument passed in will essentially convert vector list into linked list 
LinkedList::LinkedList(std::vector<int> vec){
    //Head will point to first element of vector
    this->head = new Node(vec[0]);
    //Size of linked list will match vector size
    this->size = vec.size();
    
    //Temp pointer will be used to traverse linked list
    Node* temp_ptr = head;
    

    //Traversing through linked list, 
    for(int i = 1; i < vec.size(); i++){
        //Head pointer will point to next node
        temp_ptr->next = new Node(vec[i]);
        temp_ptr = temp_ptr->next;
    }   

}

LinkedList::~LinkedList(){
       //Temp will hold head
       Node* new_head = head;
       
       //Deletes every pointer one by one until reaches end of linked list
       while(new_head != nullptr){
         Node* next = new_head->next;
         delete new_head;
         new_head = next;
       } 

}


void LinkedList::push_front(int data){
    //Pointer to a new node with given data
    Node* new_node = new Node(data);
    
    //Have the pointer to given node to what head currently is
    new_node->next = head;

    //Have the head point to the next node
    head = new_node;
            
    //Updating linked list size
    size++;

}

void LinkedList::push_back(int data){
    //Pointers for my new head and node
    // this->head = new Node(data);
    Node* new_head = head;
    Node*  new_node = new Node(data);

    //if linked list is empty, have the head point to the new node
    //This simply acts as "appending" to the linked list as there are no nodes that need to be pushed back
    if(head == nullptr){
        head = new_node;
    }
    else{ //If there are elements in list, traverse through list to find last node 
        while(new_head->next != nullptr){
            new_head = new_head->next;
        }

       //Once last node is reached, 
       //change the pointer from the last node to the appended new node
        new_head->next = new_node;
    }

    
    //Update size of linked list with pushed backe element
    size++;
}

void LinkedList::insert(int data, int idx){
    //Pointer to the new node that will be inserted
      Node* new_node = new Node(data);
      Node* new_head = head;
      Node* temp_ptr = nullptr;

    // If the index is 0, insert at the front of the list
    if(idx == 0){
        new_node->next = head;
        head = new_node;
    }
    else{
        
        //counter variable
        int i = 0;

        // Traverse the linked list until I reach target index
        while(new_head != nullptr && i < idx) {
            temp_ptr = new_head;
            new_head = new_head->next;
            i++;
        }

        // If I reach the target index or the end, insert the new node
        if(i == idx) {
            temp_ptr->next = new_node;
            new_node->next = new_head;
        } 
        else{
            // Index is out of bounds, append at the end of the list
            delete new_node; 
            push_back(data);
        }
    }
    //Update size of linked list
    size++;
} 


   


void LinkedList::remove(int data){
    Node* new_head = head;
    Node* temp_ptr = nullptr;

    // Traverse the linked list
    while (new_head != nullptr) {
        // Checks if the new_head node contains the data that should be removed
        if(new_head->data == data) {
            //If I am at the first element, then simply replace the head node to next node
            if (temp_ptr == nullptr) {
               
                head = new_head->next;
            } 
            else{// If it's not the head node, then I will update the temp_ptr node's next pointer 
                temp_ptr->next = new_head->next;
            }

            // Delete the new_head node
            delete new_head;

            // Update the size of linked list
            size--;
            
            //Once removed element, I can return from the function to halt the while loop
            return; 
        }

        // Move to the next node
        temp_ptr = new_head;
        new_head = new_head->next;
    }

    
}




bool LinkedList::contains(int data){
    //Since I am not modifying the head of the pointer I don't need to reclarify what the head will hold 
    
    //Temp pointer holding my head pointer
    Node* new_head = head; 

    //Will check for specified data in linked list until it reached its end
   while(new_head != nullptr){
        if(new_head->data == data){
            return true;
        }
        new_head = new_head->next;
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