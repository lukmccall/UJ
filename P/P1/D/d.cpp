#include <iostream>

using namespace std;

int strlen( char input[] ){
	int indeks = 0;
	while( input[ indeks ] != 0 || input[ indeks ] != '\0' )
		indeks++;
	return indeks;
	}

int find( char input[], char pattern[] ){
	int inputSize = strlen( input );
	int patternSize = strlen( pattern );
	bool find = true;
	for( int i = 0; i <= inputSize - patternSize; i++ ){
		find = true;		
		for( int j = 0; j < patternSize; j++ ){
			if( input[ i + j ] != pattern[ j ])
				find = false;	
			}
		if( find )
			return i;
		}	
		
	return -1; 
	}

void shift( char input[], char output[], int pos, int n ){
	int size = strlen( input );
	if( n >= 0 ){
		for( int i = 0; i < pos; i++ )
			output[i] = input[i];
		for( int i = 0; i < n; i++ )
			output[ pos + i ] = '_';
		for( int i = pos; i <= size; i++ )
			output[ i + n ] = input[ i ]; 
		}
	else{
		for( int i = 0; i < pos; i++ )
			output[i] = input[i];
		for( int i = 0; i <= size; i++)
			if( i + pos + n >= 0)
				output[ i + pos + n ] = input[ pos + i ];	
			else{
				input[ size + i + pos + n  ] = input[ pos + i ];
			}
		}
	}
	
void replace( char input[], char output[], int start, int stop, char replace[] ){
	int iSize = strlen( input );
	int rSize = strlen( replace );
	for( int i = 0; i < start; i++ )
		output[ i ] = input[ i ];
	for( int i = 0; i < rSize; i++ )
		output[ start + i ] = replace[ i ];
	for( int i = 0; i <= iSize - stop; i++ )
		output[ start + rSize + i ] = input[ stop + i ];
	
	}
	

void transform( char input[], char output[], char mode, char pattern[], char param[] ){
	int iSize = strlen( input );
	int f = find( input, pattern );
	int fPattern = f+strlen(pattern);
	if( f != -1 ){
		if( mode == 'R' )
			replace( input, output, f, fPattern, param );
		else 
			if( mode == 'E' ){
				for( int i = 0; i < f; i++)
					output[ i ] = input[ i ];
				for(int i = 0; i <= iSize - fPattern; i++ )
					output[ i + f ] = input[ fPattern + i ];	
				}
			else
				if( mode == 'D' ){
					for( int i = 0; i < fPattern; i++)
						output[ i ] = input[ i ];
					for( int i = 0; i < strlen(pattern); i++ )
						output[ i + fPattern ] = input[ f + i];
				
					for(int i = 0; i <= iSize - fPattern; i++)
						output[ i + fPattern + strlen(pattern) ] = input[ fPattern + i];
					}
				else
					for( int i = 0; i <= iSize; i++)
						output[i] = input[i];
	}
	else
		for( int i = 0; i <= iSize; i++)
				output[i] = input[i];
	}		
