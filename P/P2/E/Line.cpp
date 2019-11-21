#pragma once
#include "GeometricObject.cpp"
#include "pointXY.cpp"

class Line : public GeometricObject{
public:
	pointXY p0;
	pointXY p1;
	
	int min( int a, int b ){
		return a < b ? a : b;
	}
	int max( int a, int b ){
		return a > b ? a : b;
	}
	
public:
	Line() : p0(), p1() {}
	~Line() {}
	Line(pointXY& _p0, pointXY& _p1) : p0(_p0), p1(_p1) {}
	bool Draw( int x, int y ){
		if( p0.GetX() == p1.GetX() && p0.GetY() == p1.GetY() ) 
			if( p0.GetX() == x && p0.GetY() == y )
				return true;
			else
				return false;
		
		int wec = ( y - p0.GetY() ) * ( p1.GetX() - p0.GetX() ) - ( x - p0.GetX() ) * ( p1.GetY() - p0.GetY() );
		if( wec != 0 )
			return false;
		return 	min( p0.GetX(), p1.GetX() ) <= x && x <= max( p0.GetX(), p1.GetX() ) &&
				min( p0.GetY(), p1.GetY() ) <= y && y <= max( p0.GetY(), p1.GetY() );
 	}
	
	void GetType(){
		std::cout << "Line" << std::endl;
	}
};
