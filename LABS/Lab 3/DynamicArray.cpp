#include "DynamicArray.h"
#include <cstring>

//ChatGPT link 
// https://chat.openai.com/share/59a9855d-b1b2-49b1-b109-1c54a42024a9
//Chat helped with the creations of the constructors/methods
//I added interpretations to show that I understand the code and material
//The implementation in my main.cpp will be on my own

// "Fancy" way to write a default constructor.
// Note: The other constructors can *NOT* be written this way!
DynamicArray::DynamicArray()
    : m_length(0), m_capacity(1), m_scaling_factor(2.0), m_data(new int[1]) {
}

// default constructor with a scaling factor, creates an array with capacity = capacity
DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    //..............
    // TODO

    //Sets my member variables as the functions arguments and allocates new memory on heap 
    //Note:length = 0 because I am creating an empty array
    m_length = 0;
    m_scaling_factor = scaling_factor;
    m_capacity = capacity;
    m_data = new int[m_capacity];

    
    
    //..............
}

// fill constructor, creates an array of capacity = length, and set all values to `default_value`
DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    //..............
    // TODO
    
    //This one initializes all elements in array to default value
    //capacity = length
    
    //Similar as above with the addition of length's member variable having a value
    m_length = length;
    m_scaling_factor = scaling_factor;
    m_capacity = length; 
    m_data = new int[m_capacity];
    
    for(unsigned int i = 0; i < m_capacity; i++){
        m_data[i] = default_value;
    }
   
    //

    //..............
}

//This one is fine
DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other; 
}

// Destructor: destroys the dynamically allocated array on the heap
DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::get_length() {
    return m_length;
}

unsigned int DynamicArray::get_capacity() {
    return m_capacity;
}

double DynamicArray::get_scaling_factor() {
    return m_scaling_factor;
}

void DynamicArray::set_scaling_factor(double value) {
    m_scaling_factor = value;
}


// convert the vector into a printable string 
std::string DynamicArray::to_string() {
	// Initialize an empty string
    std::string str("");
	for(unsigned int i = 0; i < m_length; i++){
        str += std::to_string(m_data[i]); 
        //Ensuring I don't have any extra spaces at the end
        if(i <m_length - 1){
            str += " ";
        }
    }
	//..............
    // TODO
    //..............
    //Converts array elements into strings to be able to print elements

    return str;
}

// find the first occurrence of "value" in the array. Return false if the value is not found
bool DynamicArray::find_first_of(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //Finds first index of desireved value
    //It should return true and the index

    for(unsigned int i = 0; i < m_length; i++){
        if(m_data[i] == value){
            *index = i;
            found = true;
            return found;
        }
    }

    //..............
    return found;
}

// find the last occurrence of "value" in the array. Return false if the value is not found
bool DynamicArray::find_last_of(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //Finds last index of desired value
    //It should return the index 
    for(int i = m_length - 1; i >= 0; i--){
        if(m_data[i] == value){
            *index = i;
            found = true;
            return found;
        }
    }

    //..............
    return found;
}

// add a value to the end of the array (resize if necessary)
void DynamicArray::append(int value) {
    //..............
    // TODO
    //Pushes back value into the end of the array
    //if full 
    if(m_length == m_capacity){

        //static_cast<unsigned int> = Multiplies two data types and converts it into an unsigned int
        unsigned int new_capacity = static_cast<unsigned int>(m_capacity * m_scaling_factor);
        int* new_data = new int[new_capacity];
        //memcpy = Copies contents of old array into new array
        std::memcpy(new_data, m_data, sizeof(int) * m_length);
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }

    m_data[m_length++] = value;

    //..............
}

// add a value to the beginning of the array (resize if necessary)
void DynamicArray::prepend(int value) {
    //..............
    // TODO
    //Puts value into the beginning of the array and shifts all other elements
    
    if(m_length == m_capacity){
       unsigned int new_capacity = static_cast<unsigned int>(m_capacity * m_scaling_factor);
       int* new_data = new int[new_capacity];
       std::memcpy(new_data, m_data, sizeof(int) * m_length);
       delete[] m_data;
       m_data = new_data;
       m_capacity = new_capacity;
    }

    for(int i = m_length - 1; i >= 0; i--){
        m_data[i+1] = m_data[i];
    }

    m_data[0] = value;
    m_length++;

    //..............
}

// remove the last value from the array
void DynamicArray::remove_last() {
    //..............
    // TODO
    //Pops last element in array 
    if(m_length > 0){
        m_length--;
    }

    //..............
}

// remove the first value from the array
void DynamicArray::remove_first() {
    //..............
    // TODO
    //Pops first element in array
    if(m_length > 0){
        for(unsigned int i = 1; i < m_length; i++){
            m_data[i-1] = m_data[i];
        }

        m_length--;
    }

}

// remove all elements from the array 
// allocated memory should be deleted and the array pointer should now point to NULL
// capacity and length should be reset to zero
void DynamicArray::clear() {
    //..............
    // TODO
    // remove all elements from the array 
    // allocated memory should be deleted and the array pointer should now point to NULL
    // capacity and length should be reset to zero
    
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
    m_capacity = 0;

    //..............
}

// Examples of "operator overloading"
int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this); 
} 

