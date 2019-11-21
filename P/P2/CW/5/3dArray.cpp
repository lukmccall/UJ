#include <iostream>
#include <stdlib.h> 

class Array3D{
private:
	int width;
	int height; 
	int	deep;
	int*** pointer;

public:
	Array3D( int w = 0, int h = 0, int d = 0 ){
		width = w;
		height = h;
		deep = d;
		pointer = new int**[ width ];
		for( int i = 0; i < width; i++ ){
			pointer[ i ] = new int*[ height ];
			for( int j = 0; j < height; j++ ){
				pointer[i][j] = new int[ deep ];
				for( int t = 0; t < deep; t++ )
					pointer[i][j][t] = 0;
			}
		}	
	}
	
	Array3D( const Array3D& array ){
		width = array.width;
		height = array.height;
		deep = array.deep;
		pointer = new int**[ width ];
		for( int i = 0; i < width; i++ ){
			pointer[ i ] = new int*[ height ];
			for( int j = 0; j < height; j++ ){
				pointer[i][j] = new int[ deep ];
				for( int t = 0; t < deep; t++ )
					pointer[i][j][t] = array.pointer[i][j][t] ;
			}
		}	
	}
	
	~Array3D(){
		std::cout << "Sprzatanie pamieci" << std::endl;
		for( int i = 0; i < width; i++ ){
			for( int j = 0; j < height; j++ )
				delete[] pointer[i][j];
			delete[] pointer[i];
		}
		delete[] pointer;	
	}
	
	void print(){
		for( int i = 0; i < width; i++ ){
			std::cout << "W: " << i << std::endl;
			for( int j = 0; j < height; j++ ){
				for( int t = 0; t < deep; t++ ){
					std::cout << pointer[i][j][t] << " ";
				}
			std::cout << std::endl;
			}
		}
	}
	
	void insert( int val, int w, int h, int d ){
		if( w >= 0 && w < width && h >= 0 && h < height && d >= 0 && d < deep )
			pointer[ w ][ h ][ d ] = val;
	}
	
	void resize( int w, int h, int d ){
		
		int*** newPointer = new int**[ w ];
		for( int i = 0; i < w; i++ ){
			newPointer[ i ] = new int*[ h ];
			for( int j = 0; j < h; j++ ){
				newPointer[i][j] = new int[ d ];
				for( int t = 0; t < d; t++ )
					if( i >= 0 && i < width && j >= 0 && j < height && t >= 0 && t < deep )
						newPointer[i][j][t] = pointer[i][j][t];
					else
						newPointer[i][j][t] = 0;
			}
		}
		
		for( int i = 0; i < width; i++ ){
			for( int j = 0; j < height; j++ )
				delete[] pointer[i][j];
			delete[] pointer[i];
		}
		delete[] pointer;		
		
		pointer = newPointer;
		width = w;
		height = h;
		deep = d;		
		/*
		if( w != width ){
			std::cout << "cos";
			width = w;
			pointer = (int***)realloc(pointer, sizeof(int**) * width );
		}
		
		if( h != height ){
			
			std::cout << "cos2";
			height = h;
			for( int i = 0; i < width; i++ )
				pointer[ i ] = (int**)realloc(pointer[ i ], sizeof(int*) * height);
		}
		
		if( d != deep){
			
			std::cout << "cos3";
			deep = d;
			for( int i = 0; i < width; i++ )
				for( int j = 0; j < height; j++ )
					pointer[i][j] = (int*)realloc(pointer[i][j], sizeof(int) * deep);
		}
		*/
	}
	
};	

int main(){
	Array3D array(5,5,5);	
	array.print();
	std::cout << std::endl;
	for( int i = 0; i < 5; i++ )
		for( int j = 0; j < 5; j++ )
			for( int t = 0; t < 5; t++ )
				array.insert(i*100+j*10+t,i,j,t);
	array.print();
	std::cout << std::endl;
	array.resize(3,3,3);
	array.print();
	std::cout << std::endl;
	Array3D copy( array );
	copy.print();
	copy.resize( 6,6,6);
	array.print();
	std::cout << std::endl;
	copy.print(); 
	
	return 0;
}
