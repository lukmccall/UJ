#include <iostream>
#include "functions.cpp"

using namespace std;

int NumberOfElements(const int* shape, int n_dims){
	int size = 1;
	for( int i = 0; i < n_dims; i++ )
		size *= shape[ i ];
	return size;
	}

void max_over_last_axis(int matrix[2][3][4], int result[2][3]){
	for( int i = 0; i < 2; i++ )
		for( int j = 0; j < 3; j++ )
			result[i][j] = maximum( matrix[i][j], 4);
	}

void apply(int* matrix, const int* shape, int n_dims, int func_id){
	int size = NumberOfElements(shape,n_dims);
	for(int i = 0; i < size; i++)
		if( func_id == SQUARE )
			matrix[ i ] = square( matrix[ i ] );	
		else
			if( func_id == CUBE )
				matrix[ i ] = cube( matrix[ i ] );	
		
	}		

void apply_along_last_axis(int* matrix, const int* shape, int n_dims, int func_id){
	int temp[ shape[ n_dims - 1 ]];		
	int size = NumberOfElements(shape,n_dims) / shape[ n_dims - 1 ];
	int lastIndex = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < shape[ n_dims - 1 ]; j++ )
			temp[ j ] = matrix[ lastIndex + j ]; 
		
		if( func_id == MODMIN )
			modulo_min( temp, shape[ n_dims - 1 ]);
		else
			if( func_id == SUBMIN )
				subtract_min( temp, shape[ n_dims - 1 ] );
		
		for(int j = 0; j < shape[ n_dims - 1 ]; j++ )
			matrix[ lastIndex + j ] = temp[ j ]; 
	
		lastIndex += shape[ n_dims - 1 ];	
		}
	
	}
	
void apply_over_last_axis(int* matrix, const int* shape, int n_dims, int func_id){
	int temp[ shape[ n_dims - 1 ]];	
	int result;	
	int size = NumberOfElements(shape,n_dims) / shape[ n_dims - 1 ];
	int lastIndex = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < shape[ n_dims - 1 ]; j++ )
			temp[ j ] = matrix[ lastIndex + j ]; 
		
		if( func_id == MAX )
			result = maximum( temp, shape[ n_dims - 1 ]);
		else
			if( func_id == MIN )
				result = minimum( temp, shape[ n_dims - 1 ] );
		
		for(int j = 0; j < shape[ n_dims - 1 ]; j++ )
			matrix[ i ] = result; 
		lastIndex += shape[ n_dims - 1 ];	
		}
	
	}

void print_matrix(const int* matrix, const int* shape, int n_dims){
	int size = NumberOfElements(shape,n_dims);
	int specialIndex[ size ];
	int start;
	int increment; 
	for( int i = 0; i < size; i++ ){
		specialIndex[ i ] = 0;
		}
	for( int i = n_dims - 1; i >= 0; i-- ){
		increment = 1;
		for(int j = i; j < n_dims; j++)
			increment *= shape[ j ];
		start = 0;
		do{
			specialIndex[ start ]++;
		
			start += increment;	
			} while( start + increment <= size );
		}
		
	for( int i = 0; i < size; i++){
		if( specialIndex[ i ] > 0 ){
			if( i != 0 ){
				for( int j = 0; j < specialIndex[ i ]; j++ )
					cout << "]";
				for( int j = 0; j < specialIndex[ i ]; j++ )
					cout << endl;
				for( int j = 0; j < n_dims - specialIndex[ i ]; j++ )
					cout << " ";
				}
			for( int j = 0; j < specialIndex[ i ]; j++ )
					cout << "[";
			cout << matrix[ i ];
			}
		else
			cout << ", " << matrix[ i ];
	}
	for(int i = 0; i < n_dims; i++ )
		cout << "]";
	cout << endl;
}
