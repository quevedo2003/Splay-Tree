// Animal.h
#pragma once
#include <iostream>

class Animal{
    private:
    	float hunger;
		float thirst;

    public:
	//Constructor function - making my Animal object, with set parameters
      Animal(float initial_hunger, float initial_thirst);
    //
		void Eat(float sustenance);
    	float GetHunger();
    	virtual void Speak() = 0;
		
		void Drink(float quenched);
		float GetThirst();
		
};