#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define LINE_SIZE 1025

typedef struct DEFINE_LIST{
	struct DEFINE_LIST* next;
	char* definition;	
} DEFINE_LIST;

typedef struct LIST{
	struct LIST* next;
	unsigned int inputNumber;
	DEFINE_LIST* defList;
} LIST;

int main(){
	LIST* first = NULL;
	LIST* last = NULL;
	FILE* project;
	char line[ LINE_SIZE ];
	char temp[ LINE_SIZE ];
	char mode;
	scanf("%[^\n]s", temp);

	project = fopen( temp, "r");
	if( project == NULL ){
		return 0;	
	}
			
	while ( fscanf(project, " %c ", &mode) != -1 ){
		fscanf( project, " %s \n", temp );
		
		if( mode == 'D' ){
			FILE* def = fopen( temp, "r");
			if( def == NULL )
				continue;
			
			LIST* newNode = (LIST*)malloc( sizeof(LIST));
			newNode->next = NULL; 	
			newNode->defList = NULL;
		    fscanf( def, "%i", &(newNode->inputNumber));
			
			while( !feof( def ) ){
				DEFINE_LIST* newDef = (DEFINE_LIST*)malloc( sizeof(DEFINE_LIST ));
				newDef->definition = (char *)malloc( newNode->inputNumber + 1 );
				newDef->next = newNode->defList;
				newNode->defList = newDef;
				
				for( int i = 0; i <= newNode->inputNumber; i++ ){
					char t;
					fscanf(def, " %c ", &t);
					newDef->definition[ i ] = t;
				}
				
			//	fgets( temp, LINE_SIZE, def);
			}
			if( last == NULL ){
				first = newNode;
				last = first;
			}
			else{
				last->next = newNode;
				last = newNode;
			}
			
			fclose( def );
		}
		else{
			FILE* sim = fopen( temp, "r" );
			char endOfFile = 0;
			if( sim == NULL )
				continue;
			while( !feof( sim ) ){	
				LIST* walker = first;
				while( walker != NULL ){
					char* input = (char*)malloc( first->inputNumber );
					
					for( int i = 0; i < walker->inputNumber; i++ ){
						char t;
						fscanf(sim, " %c ", &t);
						if( feof( sim ))
							endOfFile = 1;
						
						input[ i ] = t;
					}
//					for( int i =0; i< walker->inputNumber; printf("%c",input[i]),i++);
//					printf("\n");
					DEFINE_LIST* innerWalker = walker->defList;
					
					while( innerWalker != NULL ){
						char good = 1;
						for( int i = 0; i < walker->inputNumber; i++ )
							if( innerWalker->definition[ i ] != '*' && innerWalker->definition[ i ] != input[ i ]){
								good = 0;
								break;
							}
						if( good ){
							printf("%c\n", innerWalker->definition[ walker->inputNumber ]);
							break;
						}
						innerWalker = innerWalker->next;		
					}	
				
					walker = walker->next;
				}
			
				//fgets(temp, LINE_SIZE, sim);
			}
			
			fclose( sim );
		}
	}
	/*
	LIST* walker = first;
	while( walker != NULL ){
		DEFINE_LIST* innerWalker = walker->defList;
		while( innerWalker != NULL ){
			DEFINE_LIST* freeInnerList = innerWalker;
			innerWalker = innerWalker->next;
			free( freeInnerList->definition);
			free( freeInnerList );
			}
		LIST* freeList = walker;
		walker = walker->next;
		free( freeList );		
	}
		*/	
	fclose( project );
	return 0;
}
