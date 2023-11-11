#include "node.h"
#include <vector>
#include <string>

class queue{
    private:
        Node* head;
        unsigned int size;
        Node* start;
        Node* end;

    public:
        queue(); // this->head = nullptr;
        queue(int data);
        queue(std::vector<int> vec);
        ~queue();

        // void push_front(int data);
        // void push_back(int data);
        // void insert(int data, int idx);
        // void remove(int data);
        // bool contains(int data);
        // int get_size();
        std::string to_string();
        
        void enqueue(int data);
        void dequeue();
        int  peak();
};