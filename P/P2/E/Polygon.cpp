#pragma once
#include "Shape.cpp"
class Polygon : public Shape{
public:
	void GetType(){
		std::cout << "Polygon" << std::endl;
	}
};
