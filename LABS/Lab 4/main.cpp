#include "linked_list.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
   
    int value;
    std::vector<int> temp_int;
    std::vector<std::string> string_vector;

    std::string temp_string;
    std::string line;
   
    //Input will be CLA 1     
    std::ifstream file(argv[1]);

    //Calling my linked list class by type pointer
    LinkedList* singly_linked_list;
    
    //Read in the input file into a line
    // std::getline(file,line);
    // std::stringstream ss(line);
    
    //While there are values in the first row, push it into an int vector
     if(std::getline(file, line)){
        std::stringstream ss(line);
        while(ss >> value) {
            temp_int.push_back(value);
        }

        if(temp_int.size() == 0) {
            singly_linked_list = new LinkedList();
        } 
        else if(temp_int.size() == 1) {
            singly_linked_list = new LinkedList(temp_int[0]);
        } 
        else{
            singly_linked_list = new LinkedList(temp_int);
        }
        std::cout << singly_linked_list->to_string() << std::endl;
    }
      
    //Parse everything after first line as a string
    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string input_string;
        // std::cout << line << "\n";
        //Push the line into a string vector
        while(ss >> input_string){
         string_vector.push_back(input_string);
        //  std::cout<< "test" << std::endl;
        }
        //If there is only one string, it is not a pair thus i check for "?" and "-"
        if(string_vector.size() == 1){
            int converter;
            //Checks for -
            // std::cout<< "input size = " << input_string.size() <<std::endl;
            // std::cout<< "test" << std::endl;
            if(input_string[0] == '-'){
                int reverse;
                converter = std::stoi(input_string) *-1;
                // std::cout << "converter = " << converter << std::endl;
                singly_linked_list->remove(converter);
                std::cout << singly_linked_list->to_string()<<std::endl;
            }  // Checks for ?
            else if(input_string[input_string.size() - 1] == '?'){
                input_string.pop_back();
                converter = std::stoi(input_string); 
                std::cout << singly_linked_list->contains(converter)<< std::endl;
            }
            else{// If there are no ? or - then it must be a single digit
                converter = std::stoi(input_string);
                //Check if it is positive
                if(converter % 2 == 0){
                    // std::cout << "converter = " << converter << std::endl;
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
            // std::cout << "test 1" << std::endl;
            int converter_data, converter_idx;
            converter_data  = std::stoi(string_vector[0]);
            converter_idx = std::stoi(string_vector[1]);
            
            if(converter_idx < singly_linked_list->get_size()){
            // std::cout << "test 2" << std::endl;  
            singly_linked_list->insert(converter_data, converter_idx);
            // std::cout<< "test 2.1"<< std::endl;
            std::cout << singly_linked_list->to_string()<<std::endl;
            
            }
            else{
                // std::cout << "test 3" << std::endl;
                singly_linked_list->push_back(converter_data);
                std::cout << singly_linked_list->to_string()<<std::endl;
            } 
            string_vector.clear();
        }

    }
     
    file.close();    

    
}
