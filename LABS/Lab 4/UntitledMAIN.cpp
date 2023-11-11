#include "linked_list.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]) {
   
   int value;
   std::vector<int> temp_int;

   std::string temp_string;
   std::string line;
   
   //Defining Input file, opening it, and reading it as a string
   std::ifstream file(argv[1]);

   

    LinkedList* singly_linked_list;
    
    
    std::stringstream ss(line);
    std::getline(file,line);

    while(ss >> value){
        temp_int.push_back(value);
    }   

    if(temp_int.size() == 0){
        singly_linked_list = new LinkedList();
    }
    else if(temp_int.size() == 1){
        singly_linked_list = new LinkedList(temp_int[0]);
    }
    else{
        singly_linked_list = new LinkedList(temp_int);
    }

        std::vector<std::string> string_vector;   
    
    while(std::getline(ss, line)){
        std::stringstream ss(line);
        std::string input_string;
        
        while(ss >> input_string){
         string_vector.push_back(input_string);
        }

        if(string_vector.size() == 1){
            int converter;
            if(input_string[0] == '-'){
                converter = std::stoi(input_string) * -1;
                singly_linked_list->remove(converter);
                std::cout << singly_linked_list->to_string()<<std::endl;
            }
            else if(input_string[input_string.size() - 1] == '?'){
                input_string.pop_back();
                converter = std::stoi(input_string); 
            }
            else{
                converter = std::stoi(input_string);
                if(converter % 2 == 0){
                    singly_linked_list->push_back(converter);
                    std::cout << singly_linked_list->to_string()<<std::endl;
                }
                else{
                    singly_linked_list->push_front(converter);
                    std::cout << singly_linked_list->to_string()<<std::endl;
                }
            }
            string_vector.clear();         
        }
        else{
            int converter_data, converter_idx;
            converter_data  = std::stoi(string_vector[0]);
            converter_idx = std::stoi(string_vector[1]);
            
            if(converter_idx < singly_linked_list->get_size()){
            singly_linked_list->insert(converter_data, converter_idx);
            std::cout << singly_linked_list->to_string()<<std::endl;
            }
            else{
                singly_linked_list->push_back(converter_data);
                std::cout << singly_linked_list->to_string()<<std::endl;
            } 
            string_vector.clear();
        }

    }
     
    // file.close();    

    
}
