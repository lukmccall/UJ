#include <iostream>
#include "Computer.cpp"

void Space(){
	std::cout << std::endl << std::endl;
}
int main(){
	Computer computer("CalcComputer");
	computer.Display();
	std::cout << computer.Calc() << std::endl;
	
	Space();
	
	Chip chip( "SimpleChip" );
	chip.Display();
	std::cout << chip.Calc() << std::endl;
	
	Space();
		
	LogicGate gate( "SimpleGate" );
	gate.Display();
	std::cout << gate.Calc() << std::endl;

	Space();
	
	Processor proc( "SimpleProcessor" );
	proc.Display();
	std::cout << proc.Calc() << std::endl;
	
	Space();

	Transistor *pointer;
	
	pointer = &computer;
	pointer->Display();
	
	Space();
	
	pointer = &chip;
	pointer->Display();
	
	Space();
	
	pointer = &gate;
	pointer->Display();
	
	Space();
	
	pointer = &proc;
	pointer->Display();
	
	return 0;
}
