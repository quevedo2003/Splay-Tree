#include "priority_queue.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

int main(int argc, char* argv[]){
   
    int value;
    std::vector<int> temp_int;
    std::vector<std::string> string_vector;

    std::string temp_string;
    std::string line;
   
    //Input will be CLA 1     
    std::ifstream file(argv[1]);

    //Calling my linked list class by type pointer
    priority_queue* singly_linked_list;
    
    //Read in the input file into a line
    // std::getline(file,line);
    // std::stringstream ss(line);
    
    //While there are values in the first row, push it into an int vector
     if(std::getline(file, line)){
        std::stringstream ss(line);
        while(ss >> value){
            temp_int.push_back(value);
        }

        if(temp_int.size() == 0){
            singly_linked_list = new priority_queue();
        } 
        else if(temp_int.size() == 1){
            singly_linked_list = new priority_queue(temp_int[0]);
        } 
        else{
            singly_linked_list = new priority_queue(temp_int);
        }
        std::cout << singly_linked_list->to_string() << std::endl;
    }
      
    //Parse everything after first line as a string
    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string input_string;
       
        //Push the line into a string vector
        while(ss >> input_string){
         string_vector.push_back(input_string);
        }
        
        //If there is only one string, it is not a pair thus i check for "?" and "-"
        if(string_vector.size() == 1){
            int converter;            
                //Checks for -
            if(input_string[input_string.size() - 1] == '-'){
               singly_linked_list->dequeue();
               std::cout << singly_linked_list->to_string()<<std::endl;
            }  
                // Checks for ?
            else if(input_string[input_string.size() - 1] == '?'){
                std::pair<int, int> result = singly_linked_list->peak();
                input_string.pop_back();
                std::cout << "(" << result.first << "," << result.second << ")" << std::endl;
            }
            string_vector.clear();         
        }
        //If there string size != 1, then it must be a number
        else{
            int converter_data, converter_idx;
            converter_data  = std::stoi(string_vector[0]);
            converter_idx = std::stoi(string_vector[1]);
            
            singly_linked_list->enqueue(converter_data, converter_idx);
            
            std::cout << singly_linked_list->to_string()<<std::endl;
            string_vector.clear();
        }

            
    }

       
    
     
    file.close();    

    
}