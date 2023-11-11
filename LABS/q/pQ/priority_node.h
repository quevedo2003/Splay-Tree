#pragma once

class priority_node{
    private:
        int data;
        int priority_value; 
        priority_node* next;

        friend class priority_queue;
    public:
        priority_node();
        // Overloading
        priority_node(int data, int priority_value);
        priority_node(int data, int priority_value, priority_node* next);
        ~priority_node();
};