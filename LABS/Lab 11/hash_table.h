#include <iostream>
#include <vector>


class HashTable{
   
    private:

        std::vector<int> table;
        int size;
        int collisions;
        int num;
        
        //Privaree helper for hash calculatiobns
        int hash(int key, int attempt);
        //Private helper for hash table resizing 
        void checkResize();

    public:
        //Constructors
        HashTable();
        HashTable(int mode);

        //Member functions
        void print_table();
        void insert(int key);
        int get_num_collisions();


};