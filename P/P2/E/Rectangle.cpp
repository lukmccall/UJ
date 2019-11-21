#pragma once
#include "Polygon.cpp"
#include "pointXY.cpp"
#include "Line.cpp"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>
#include <cmath>

class Rectangle : public Polygon{
private:
	pointXY p0;
	pointXY p1;
	pointXY p2;
	pointXY p3;
	Line** lines;

public: 
	static int IsO(pointXY a, pointXY b, pointXY c){
	    return (b.GetX() - a.GetX()) * (b.GetX() - c.GetX()) + (b.GetY() - a.GetY()) * (b.GetY() - c.GetY()) == 0;
	}
	
	Rectangle( pointXY _p0, pointXY _p1, pointXY _p2, pointXY _p3 )
		: p0(_p0), p1(_p1), p2(_p2), p3(_p3) {
		if( !IsO(p0, p1, p2) || !IsO(p1, p2, p3) || !IsO(p2, p3, p0) ) 
			std::cout << "NOT RECTANGLE" << std::endl;
			
		lines = new Line*[ 4 ];
		lines[ 0 ] = new Line( p0, p1 );
		lines[ 1 ] = new Line( p1, p2 );
		lines[ 2 ] = new Line( p2, p3 );
		lines[ 3 ] = new Line( p3, p0 );
	}
	
	~Rectangle(){
		for( int i = 0; i < 4; i++ )
			delete lines[ i ];  
		delete[] lines;
	}
	
	bool Draw( int x, int y ){
		for( int i = 0; i < 4; i++ )
			if( lines[ i ]->Draw( x, y ) )
				return true;
		return false; 
	}
	
	void GetType(){
		std::cout << "Rectangle" << std::endl;
	}
	
	int area(){
		double a = std::fabs( p0.GetX() * p1.GetY() - 
					      p0.GetY() * p1.GetX() +
						  p1.GetX() * p2.GetY() -
						  p1.GetY() * p2.GetX() +
						  p2.GetX() * p3.GetY() -
						  p2.GetY() * p3.GetX() +
						  p3.GetX() * p0.GetY() -
						  p3.GetY() * p0.GetX()) / 2;
		return (int)a;
	}
};
