#pragma once
#include <string>
#include <iostream>
class Transistor{
protected:
	std::string type;
	bool isOn;
public:
	Transistor( std::string t ) : type( t ), isOn( true ){}
	
	virtual void Display(){
		std::cout << type << std::endl;
	}
	
	void Switch(){
		isOn != isOn;
	}
		
	virtual int Calc(){
		return (int)isOn;
	}
};
