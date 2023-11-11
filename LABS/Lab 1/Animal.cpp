// Animal.cpp
#include "Animal.h"

//Class name :: method name
Animal::Animal(float initial_hunger, float initial_thirst){
    
    this->hunger = initial_hunger;
	this->thirst = initial_thirst;
}
//data type - class name :: method name
float Animal::GetHunger(){
    return this->hunger;
}

float Animal::GetThirst(){
	return this->thirst;
}


void Animal::Eat(float sustenance){
    this->hunger += sustenance;
}

void Animal::Drink(float quenched){
	this->thirst += quenched;
}

