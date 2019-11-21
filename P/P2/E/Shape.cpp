#pragma once
#include "GeometricObject.cpp"

class Shape : public GeometricObject{
public:
	virtual int area() = 0;
};
