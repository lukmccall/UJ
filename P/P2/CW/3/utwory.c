#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define STRING_LEN 64

typedef struct SONG{
	char name[ STRING_LEN ];
	char author[ STRING_LEN ];
	char album[ STRING_LEN ];
	unsigned int albumNumber;
	float duration;
} SONG;

void CreatSong( SONG* song,const char* _name,const char* _author , const char* _album,
				unsigned int _albumNumber, float _duration ){
	strcpy( song->name, _name);
	strcpy( song->author, _author);
	strcpy( song->album, _album);
	
	song->albumNumber = _albumNumber;
	song->duration = _duration;					
}

void DisplaySong( SONG* const song, FILE* out ){
	fprintf(out, "Utwor: %s\n", song->name);
	fprintf(out, "Wykonawca: %s\n", song->author);
	fprintf(out, "Numer albumu: %d\n", song->albumNumber);
	fprintf(out, "Album: %s\n", song->album);
	fprintf(out, "Dlugosc: %.2f", song->duration);
}  

void GetSong( SONG* song, FILE* in ){
	fscanf(in, " Utwor: %[^\n]s", song->name);
	fscanf(in, " Wykonawca: %[^\n]s", song->author);
	fscanf(in, " Numer albumu: %d", &(song->albumNumber));
	fscanf(in, " Album: %[^\n]s", song->album);
	fscanf(in, " Dlugosc: %f", &(song->duration));
}


int main(){
	SONG song;
	FILE* in = fopen( "p1.txt", "r");
	FILE* out = fopen( "p1_out.txt", "w");
	
	GetSong( &song, in );
	DisplaySong( &song, out );
	printf("Wczytano:\n");
	DisplaySong( &song, stdout );
	fclose(in);
	fclose(out);
	printf("\n\n");
	
	in = fopen( "p2.txt", "r");
	out = fopen( "p2_out.txt", "w");
	
	GetSong( &song, in );
	DisplaySong( &song, out );
	printf("Wczytano:\n");
	DisplaySong( &song, stdout );
	fclose(in);
	fclose(out);
	printf("\n\n");
	
	in = fopen( "p3.txt", "r");
	out = fopen( "p3_out.txt", "w");
	
	GetSong( &song, in );
	DisplaySong( &song, out );
	printf("Wczytano:\n");
	DisplaySong( &song, stdout );
	fclose(in);
	fclose(out);
	printf("\n\n");
	
	out = fopen("p4_out.txt", "w");
	CreatSong( &song,"nowa piosenka", "jakis autor" , "jakis album", 45, 2.34f );
	DisplaySong( &song, out );
	printf("Stworzono:\n");
	DisplaySong( &song, stdout );
	fclose( out );	
	printf("\n\n");
	
	return 0;
}
