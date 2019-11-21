#include <stdio.h>
#include <stdlib.h>
#include <strings.h>



int main(){
	FILE* in = fopen("eiffla.bmp", "rb");
	FILE* out = fopen("blue.bmp", "wb");
//	FILE* in = fopen("gosia.bmp", "rb");
//	FILE* out = fopen("gosia_blue.bmp", "wb");

	unsigned char header[ 54 ];
	int width;
	int height;
	
	fread( header, 1, 54, in );
	fwrite( header, 1, 54, out );
	width = *((int*)(&header[ 18 ]));
	height = *((int*)(&header[ 22 ]));
	printf( "%d x %d", width, height);
	unsigned int padding = width % 4;
	for( int i = 0; i < height; i++ ){
		for( int j = 0; j < width; j++ ){
			unsigned char pixel[ 3 ];
			fread( pixel, 1, 3, in );
			pixel[ 0 ] = 255;
			fwrite( pixel, 1, 3, out );
		}
		unsigned char byte[ 4 ]; 
		fread( byte, 1, padding, in );
		fwrite( byte, 1, padding, out );
	}
	while( !feof( in ) ){
		unsigned char pixel;
		fread( &pixel, 1, 1, in );
		fwrite( &pixel, 1, 1, out );
	}
	fclose( in );
	fclose( out );
	return 0;
}
