#include "queue.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

// A real world example of a queue is a music playlist
//Whatever you put in first will be played first then rotated out.

int main(int argc, char* argv[]) {
   
    int value;
    std::vector<int> temp_int;
    std::vector<std::string> string_vector;

    std::string temp_string;
    std::string line;
   
    //Input will be CLA 1     
    std::ifstream file(argv[1]);

    //Calling my linked list class by type pointer
    queue* singly_linked_list;
    
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
            singly_linked_list = new queue();
        } 
        else if(temp_int.size() == 1) {
            singly_linked_list = new queue(temp_int[0]);
        } 
        else{
            singly_linked_list = new queue(temp_int);
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
            
        
        //call dequeue if the line is only a -
        if(input_string == '-'){
            singly_linked_list->dequeue();
            std::cout << singly_linked_list->to_string()<<std::endl;
        }  
        //Call peak method if there is a ?
        else if(input_string == '?'){
            input_string.pop_back();
            // converter = std::stoi(input_string); 
            std::cout << singly_linked_list->peak()<< std::endl;
        }
        else{// If there are no ? and - then it must be a single digit
            int converter;
            converter = std::stoi(input_string);
            singly_linked_list->enqueue(converter);
            std::cout << singly_linked_list->to_string()<<std::endl;
        }
        string_vector.clear();         

    }
     
    file.close();    

    
}
