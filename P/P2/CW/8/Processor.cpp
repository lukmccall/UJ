#pragma once
#include "Transistor.cpp"
#include <string>
#include <iostream>

class Processor : virtual public Transistor{
protected:
	std::string cpuType;
	unsigned int power;
public:
	Processor( std::string type ) : Transistor( "ProcessorTransistor" ), cpuType( type ), power( 1000 ){}
	
	void Display(){
		std::cout << Transistor::type << std::endl;
		std::cout << cpuType << std::endl;
	}
	
	int Calc(){
		return isOn * power;
	}
	
	void IncreasePower(){
		power += 100;
	} 
	
	void DecreasePower(){
		power -= 100;
	} 	
	
};
