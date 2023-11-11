#include "linked_list.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]) {

    std::string file_name = argv[1];
    std::ifstream inputFile(file_name);
    std::vector<std::string> rows;
    std::string line;
    
    while (getline(inputFile, line)) {
        rows.push_back(line);
    }
    inputFile.close();
//////////////////////////////////////////////////
    LinkedList *list;
    if (rows[0].length() == 0){
    list = new LinkedList();
    
    }
    else if (rows[0].length()== 1){
     list = new LinkedList(stoi(rows[0]));
    }
    else{
        std::vector<int> first_line;
        std::istringstream iss(rows[0]);

        int num;

    while (iss >> num) {
        first_line.push_back(num);
    }
     list = new LinkedList(first_line);

    }
    std::cout << list->to_string() << std::endl;
    
    
    
    
    for(int i = 1 ; i < int(rows.size()); i++){
        if (rows[i].find('-') != std::string::npos){
            rows[i].erase(0,1);

            list->remove(stoi(rows[i]));
                std::string print;
                print = list->to_string();
            std::cout << print << std::endl;

        }
        else if (rows[i].find('?') != std::string::npos){
            
            rows[i].pop_back();
            int numbs = stoi(rows[i]);
            std::cout << int(list->contains(numbs)) << std::endl;
        }
        
        else if (rows[i].find(' ') != std::string::npos){
            std::vector<int> intpair;
            std::istringstream iss(rows[i]);

            int num;

            while (iss >> num) {
                intpair.push_back(num);
            }
            list->insert(intpair[0],intpair[1]);
            std::cout << list->to_string() << std::endl;
        }

        else {
            unsigned int num = stoi(rows[i]);
            if (num%2 == 0){
            list->push_back(num);                    //even
            }
            else{
            list->push_front(num);                     //odd
            }    
            std::cout << list->to_string() << std::endl;
        }
    }
    return 0;
}

//An integer
//odd integers get prepending to the list
//even integers get appended to the list

//A pair of integers
//val, idx to be inserted

//A negative integer
//the integer to be deleted from the list
//Note: You'll need to remove the '-' before passing the value to the function!

//An integer with a question mark
//the integer to search for in the list
//Note: Again, you'll need to remove the '?' before passing the value to your function!



