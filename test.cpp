#include <iostream>


int main(){

    int array[3] = {1,2,3};

    int* pointer;

   

    int number;

    std::cin >> number;

    std::cout<<"The ["<< number << "] index in the array is = " << array[number] << std::endl;
    pointer = &array[number];
    std::cout << "The element lives in memory address " << pointer << std::endl;

}