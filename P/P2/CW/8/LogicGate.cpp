#pragma once
#include "Transistor.cpp"
#include <iostream>



class LogicGate : virtual public Transistor{
protected:
	int (*func)();
	std::string gateType;
public:
	LogicGate( std::string type, int (*f)() = [](){ return 25; } ) : Transistor( "LogicGateTransistor"), gateType( type ), func( f ) {}
	
	int Calc(){
		return isOn * func();
	}
	
	void Display(){
		std::cout << type << std::endl;
		std::cout << gateType << std::endl;
	}
};
