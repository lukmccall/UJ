#pragma once

class pointXY{
private:
	int x;
	int y;
public:
	pointXY(){
		x = 0;
		y = 0;
	}
	pointXY( pointXY& p ){
		x = p.x;
		y = p.y;
	}
	pointXY( int _x, int _y ){
		x = _x;
		y = _y;
	}
	int GetX(){
		return x;
	}
	int GetY(){
		return y;
	}
};
