#include "priority_node.h"
#include <vector>
#include <string>

class priority_queue{
    private:
        priority_node* head;
        unsigned int size;
        priority_node* start;
        priority_node* end;

    public:
        priority_queue(); // this->head = nullptr;
        priority_queue(int data);
        priority_queue(std::vector<int> vec);
        ~priority_queue();

        std::string to_string();
        
        void enqueue(int data, int priority_value);
        void dequeue();
        std::pair<int,int>  peak();
};