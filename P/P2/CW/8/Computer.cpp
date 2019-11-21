#pragma once 
#include "Chip.cpp"
#include <string>

class Computer : public Chip {
private:
	std::string system;
	std::string computerType;
public:
	
	Computer( std::string type, std::string sys = "Linux" ) : Chip( "ComputerChip" ), computerType( type ), Transistor( "ComputerTransistor"), system( sys ){} 
	
	int Calc(){
		return Chip::Calc() * 100;
	}
	
	void Display(){
		Chip::Display();
		std::cout << computerType << " " << system << std::endl;
	}
};
