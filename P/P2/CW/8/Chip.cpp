#pragma once
#include "Processor.cpp"
#include "LogicGate.cpp"

class Chip : public Processor, public LogicGate{
protected:
	std::string chipType;
	std::string chipSet;
public:
	Chip( std::string type ) : chipType( type ), Processor( "ProcessorSimpleType" ), LogicGate( "LogicGateSimpleType" ), Transistor("ChipTransistor") {	}
	
	void Display(){
		std::cout << type << std::endl;
		std::cout << cpuType << std::endl;
		std::cout << gateType << std::endl;
		std::cout << chipType << std::endl;
	}
	
	int Calc(){
		return func() * power;
	}
};
