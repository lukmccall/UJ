#pragma once
#include "FuncObj.cpp"
#include "GeometricObject.cpp"

class Func : public GeometricObject{
private:
	FuncObj* F;
public:
	Func( FuncObj* function ) : F( function ) {} 
	void GetType(){
		std::cout << "Func" << std::endl;
	}
	
	bool Draw( int x, int y ){
		return F->GetVal( x ) == y;
	}
	
	int Integral( int x, int y ){
		int ret = 0;
		for( int i = x; i <= y; i++ )
			ret += F->GetVal( i );
		return ret;
	}
	
	friend void funcSwicher( Func& );
	friend void funcSwicher(const Func&);
};
