#include <iostream>

using namespace std;

struct INNER_LIST{
	long long num;
	INNER_LIST* next;
	INNER_LIST* prev;
};

struct LIST{
	char a;
	char b;
	char c;
	char mode;
	INNER_LIST* innerFirst;
	INNER_LIST* innerLast; 
	LIST* next;
	LIST* prev;
};

INNER_LIST* NextInnerElement( INNER_LIST* active, char mode ){
	if( active == NULL )
		return NULL;
	if( mode == 'S' )
		return active->next;	
	return active->prev;
}

LIST* NextListElement( LIST* active, char mode ){
	if( active == NULL )
		return NULL;
	if( mode == 'S' )
		return active->next;
	return active->prev;	
}

LIST* Find( LIST* f, char a, char b, char c, char mode ){
	LIST* walker = f;
	while( walker != NULL ){
		if( walker->a == a 
		 && walker->b == b
		 && walker->c == c )
		 	return walker;
		walker = NextListElement(walker, mode);
		}
	return NULL;
}

bool IsBigger( LIST* f, LIST* s ){
	if( f->a > s->a )
		return true;
	else if( f->a == s->a )
		if( f->b > s->b )
			return true;
		else if( f->b == s->b )
			if( f->c > s->c )
				return true;
	
	return false;
}

void ShowList( LIST* firstList ){
	LIST* walker = firstList;
	while( walker != NULL ){
		cout << walker->a << walker->b << walker->c ;
		INNER_LIST* innerWalker;
		if( walker->mode == 'S' )
			innerWalker = walker->innerFirst;
		else
			innerWalker = walker->innerLast;
	
		while( innerWalker != NULL ){
			cout << " " << innerWalker->num;
			innerWalker = NextInnerElement( innerWalker, walker->mode );		
			}
		walker = walker->next;
		cout << endl;
		}
	}


void DeleteList( LIST* firstList ){
	LIST* walker = firstList;
	while( walker != NULL ){
		INNER_LIST* innerWalker = walker->innerFirst;
		while( innerWalker != NULL ){
			INNER_LIST* innerNext = innerWalker->next;
			innerWalker->next = NULL;
			innerWalker->prev = NULL;
			delete innerWalker;
			innerWalker = innerNext;
			}
		LIST* next = walker->next;
		walker->innerFirst = NULL;
		walker->innerLast = NULL;
		walker->next = NULL;
		walker->prev = NULL;
		delete walker;
		walker = next;	
		}
	}
	
int main(){
	int n;
	cin >> n;
	for( int i = 0; i < n; i++){
		LIST* firstList = NULL;
		LIST* lastList = NULL;
		LIST* activeList = NULL;
		LIST* newElement = NULL;
		
		char buff;
		cin >> buff;
		while( buff != '$' ){
			newElement = new LIST;
			newElement->next = NULL;
			newElement->a = buff;
			cin >> buff;
			newElement->b = buff;
			cin >> buff;
			newElement->c = buff;
			
			INNER_LIST* firstInner = NULL;
			INNER_LIST* lastInner = NULL;
			INNER_LIST* newInnerElement;
			long long num;
			char mode;
			cin >> num;	
			while( !cin.fail() ){
				newInnerElement = new INNER_LIST;
				newInnerElement->num = num;
				newInnerElement->next = NULL;
				newInnerElement->prev = NULL;
			
				if( firstInner == NULL ){ 
					firstInner = newInnerElement;
					firstInner->prev = NULL;
						}
						
				if( lastInner != NULL ){ 
					newInnerElement->prev = lastInner;
					lastInner->next = newInnerElement;
					}
				lastInner = newInnerElement; 	

				cin >> num;
				}
			cin.clear();
			cin >> mode;
			newElement->mode = mode;
			newElement->innerFirst = firstInner;
			newElement->innerLast = lastInner;
			
			if( firstList == NULL ){ 
				firstList = newElement;
				firstList->prev = NULL;
				lastList = newElement;
				}
			else{
				activeList = firstList;
		
				while( activeList != NULL && IsBigger(newElement, activeList ))
					activeList = activeList->next;
				if( activeList != NULL)	
					activeList = activeList->prev;
				else 
					activeList = lastList;
					
				if( activeList == NULL ){
					newElement->prev = NULL;
					newElement->next = firstList;
					firstList->prev = newElement;
					firstList = newElement;
					}
				else{
					if( activeList->next == NULL ){
						newElement->prev = activeList;
						lastList = newElement;
						activeList->next = newElement;
						}
					else{
						newElement->prev = activeList;
						activeList->next->prev = newElement;
						newElement->next = activeList->next;
						activeList->next = newElement;
						}
				
					}			
				}
			
			cin >> buff;	
			}
			
		ShowList( firstList );
		unsigned int o;
		cin >> o;
		for( int j = 0; j < o; j++ ){
			char a,b,c;
			char which, start, dir;
			cin >> a >> b >> c;
			cin >> which >> start >> dir;
				
			LIST* active = NULL;		
			active = Find( firstList, a, b, c, 'S');
			if( active != NULL && active->innerFirst != NULL ){
				INNER_LIST* walker;
				char mode;
				
				int step = ( which == 'D' ) ? 2 : 3;
				
				if( dir == 'B'){
					if( active->mode == 'S'){
						walker = active->innerFirst;
						mode = 'S';
						}
					else if( active->mode == 'R'){
						walker = active->innerLast;
						mode = 'R';
						}				 		
					}
				else{
					if( active->mode == 'S'){
						walker = active->innerLast;
						mode = 'R';
						}
					else if( active->mode == 'R'){
						walker = active->innerFirst;
						mode = 'S';
						}
					}	
		
				if( walker == NULL ){
					continue;
					}
				
				if( start == 'S' )
					walker = NextInnerElement( walker, mode );
				if( start == 'T'){
					walker = NextInnerElement( walker, mode );
					if( NextInnerElement( walker, mode ) == NULL )
						continue;
					walker = NextInnerElement( walker, mode );
					}
			
				while( walker != NULL ){
					INNER_LIST* n;
					INNER_LIST* p;
					
					INNER_LIST temp;
					temp.next = walker->next; 
					temp.prev = walker->prev;
										
					n = walker->next;
					p = walker->prev;
					
					delete walker;
					if( n == NULL && p == NULL ){
						active->innerFirst = NULL;
						active->innerLast = NULL;
						}
					else if( n == NULL ){
						p->next = NULL;
						active->innerLast = p;
						}
					else if( p == NULL ){
						n->prev = NULL;
						active->innerFirst = n;
					}
					else{
						p->next = n;
						n->prev = p;
						}
					walker = &temp;
					for( int k = 0; k < step; k++ ){
						walker = NextInnerElement( walker, mode );
						if( walker == NULL)
							break;
						}

					}	
				}
		
			}	
		ShowList( firstList );
		DeleteList( firstList );
		}
	return 0;
	}
