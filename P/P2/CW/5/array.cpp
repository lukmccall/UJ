#include <iostream>

class Array2D{
private:
	int** _pointer;
	int _width;
	int _height;
public:
	Array2D( int width, int height ){
		_width = width;
		_height = height;
		
		_pointer = new int*[ _width ];
		for( int i = 0; i < _width; i++ )
			_pointer[ i ] = new int[ _height ];
		
		for( int i = 0; i < _width; i++ )
			for( int j = 0; j < _height; j++ )
				_pointer[ i ][ j ] = 0;			
 	}
 	
	~Array2D(){
		std::cout << "Sprzatanie pamieci" << std::endl;
		for( int i = 0; i < _width; i++ )
			delete[] _pointer[ i ];
		delete[] _pointer;	
	}
	
	Array2D( const Array2D& array ){
		_width = array._width;
		_height = array._height;
		
		_pointer = new int*[ _width ];
		for( int i = 0; i < _width; i++ )
			_pointer[ i ] = new int[ _height ];
		
		for( int i = 0; i < _width; i++ )
			for( int j = 0; j < _height; j++ )
				_pointer[ i ][ j ] = array._pointer[i][j];
		
	}
 	
 	void print(){
 		for( int i = 0; i < _width; i++ ){
			for( int j = 0; j < _height; j++ )
				std::cout << _pointer[ i ][ j ] << " ";	
			std::cout << std::endl;
		}	
	}
	
	void insert(int val, int x, int y ){
		if( x >= 0 && x < _width && y >= 0 && y < _height )
			_pointer[ x ][ y ] = val;
	}
	
	/*
	int getWidth(){ return _width; }
	int getHeight(){ return _height; }
	int getElement( int x, int y ){ return _pointer[x][y]; }
	*/
};

int main(){
	int w = 10;
	int h = 10;
	
	{
		Array2D a( w, h );
		a.insert(1,0,0);
		a.insert(2,0,1);
		a.insert(3,0,2);
		a.insert(4,0,3);
		Array2D copy( a );
		copy.insert(7,0,0);
		std::cout << "Orginalna Tablica " << std::endl;
		a.print();
		std::cout << "Kopia(ze zmiennionym pierwszym elementem)" << std::endl;
		copy.print(); 
		std::cout << std::endl << std::endl; 
		for( int i = 0; i < w; i++)
			for( int j = 0; j < h; j++ ){
				if( i == 0 || j == 0 || i == w-1 || j == h-1 || i == j )
					a.insert( (i+j)%10, i, j);
			}
		a.print();
		
	}
	return 0;
}
