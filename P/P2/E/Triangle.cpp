#pragma once
#include "Polygon.cpp"
#include "pointXY.cpp"
#include "Line.cpp"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>
#include <cmath>

class Triangle : public Polygon{
private:
	pointXY p0;
	pointXY p1;
	pointXY p2;
	Line** lines;
public: 
	Triangle( pointXY _p0, pointXY _p1, pointXY _p2 ) : p0(_p0), p1(_p1), p2(_p2) {
		lines = new Line*[ 3 ];
		lines[ 0 ] = new Line( p0, p1 );
		lines[ 1 ] = new Line( p1, p2 );
		lines[ 2 ] = new Line( p2, p0 );
	}
	
	~Triangle(){
		for( int i = 0; i < 3; i++ )
			delete lines[ i ];
		delete[] lines;
	}
	
	bool Draw( int x, int y ){
		for( int i = 0; i < 3; i++ )
			if( lines[ i ]->Draw( x, y ) )
				return true;
		return false; 
	}
	
	void GetType(){
		std::cout << "Triangle" << std::endl;
	}
	
	int area(){
		double a = std::fabs( p0.GetX() * p1.GetY() + 
   				   	p1.GetX() * p2.GetY() + 
					p2.GetX() * p0.GetY() - 
					p0.GetY() * p1.GetX() - 
					p1.GetY() * p2.GetX() - 
					p2.GetY() * p0.GetX() ) / 2;
		return (int)a;
	}
};
