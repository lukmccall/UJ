#pragma once

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>
#include <cmath>

class Circle : public Shape {
private:
	int r;
public:
	Circle( int _r ) : r(_r) {}
	
	int area(){
		return (int)(M_PI * r * r);
	}
	
	bool Draw( int x, int y ){
		return x * x + y * y == r * r;
	}
	
	void GetType(){
		std::cout << "Circle" << std::endl;
	}
};
