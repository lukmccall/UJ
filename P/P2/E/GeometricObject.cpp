#pragma once
#include <iostream>

class GeometricObject{
public:
	virtual bool Draw(int,int) = 0;
	
	virtual void GetType(){
		std::cout << "unknown" << std::endl;
	}
	
};
