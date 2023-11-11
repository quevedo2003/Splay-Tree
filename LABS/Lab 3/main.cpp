#include "DynamicArray.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

//ChatGPT link 
// https://chat.openai.com/share/59a9855d-b1b2-49b1-b109-1c54a42024a9
//Chat helped with the header file.

int main(int argc, char* argv[]){
    //argument count - Number of command line arguments (CLA) always atleast one as program name is the first argument
    //argument vector - pointers to the memory addresses of the command line arguments

    //  if I run ./prog input.txt 2.5 10 then I will create a DynamicArray with scaling_factor of 2.5 and an initial capacity of 10.
    //  However, if I run it with no additional CLAs other than the input file then it will use the default constructor.

    int value;

    //Read an unknown number of integers from a file (it is fine to use the vector class to hold these temporarily)
    std::vector<int> temp;
    std::string new_file;  

    std::string input_file_name = argv[1];
    std::ifstream inputFile(input_file_name);
    
    //Collects all elements from input file and puts it into the temp vector
    while(inputFile >> value){
        temp.push_back(value);
    }

    inputFile.close();

    //I must call my three of the dynamicArray constuctors  based on CLAs
    //DynamicArray() - Default
    //DynamicArray(double scaling_factor, unsigned int capacity) - With scaling factor and capacity
    //DynamicArray(double scaling_factor, unsigned int length, int default_value) - With scaling factor, length, and value 
   
   double scalingFactor = 2.0;
   unsigned int initialCapacity = 1;

    //Must be a pointer so it can live within the scope of main
    DynamicArray *dynamicArray;

    if(argc == 2){
       dynamicArray = new DynamicArray(); 
    }
    else if(argc == 4){
       double scalingFactor = std::stod(argv[2]);
      unsigned int initialCapacity = std::stoul(argv[3]);
        dynamicArray = new DynamicArray(scalingFactor, initialCapacity);

    }
    else if(argc == 5){
        double scalingFactor = std::stod(argv[2]);
        unsigned int length = std::stoul(argv[3]);
        int defaultValue = std::stoi(argv[4]);
        dynamicArray = new DynamicArray(scalingFactor, length, defaultValue);

    }
     
   
    unsigned int size = temp.size();
    unsigned int half = size/2;
    unsigned int third = size/3;
    unsigned int index;

    
    
    
    //dynamicArray.to_string() = print current array

    //Iterates through first half    
    for (unsigned int i = 0; i < half; i++) {
        dynamicArray->append(temp[i]);
    } 
    std::cout << dynamicArray->to_string() << std::endl;


    //Iterates through second half  
    //Dont do extra steps if you have a variable (**Note to self: 2*half != size**)  
    for (unsigned int i = half; i < size; i++) {
        dynamicArray->prepend(temp[i]);
    
    }
    std::cout << dynamicArray->to_string() << std::endl;

    //Prints only if true, tab, index
    bool found = true;
    found = dynamicArray->find_first_of(temp[third], &index);
    if(found){
        std::cout << found << "\t" << index << std::endl; 
    } 
        
    found = dynamicArray->find_last_of(temp[third], &index);
    if(found){
        std::cout << found << "\t" << index << std::endl;
    }



    dynamicArray->remove_last();
    std::cout << dynamicArray->to_string() << std::endl;

    dynamicArray->remove_first();
    std::cout << dynamicArray->to_string() << std::endl;

    dynamicArray->clear();
    std::cout << dynamicArray->to_string() << std::endl;

    delete dynamicArray;

}