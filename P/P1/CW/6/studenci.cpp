// Studenci
#include <iostream>

using namespace std;

/* Struktura daty */
struct DATE_STRUCT{
	int year;
	int month;
	int day;
};

/* Struktura studentow */
struct STUDENT_STRUCT{
	string name;
	string surname;
	float stypendium;
	DATE_STRUCT birth;
	DATE_STRUCT start;
};

/* Struktura grupy */
struct GROUP_STRUCT{
	int lenght;
	STUDENT_STRUCT arrayOfStudent[ 16 ];
	string name; 
};

/* Struktura przedmiotu */
struct SUBJECT_STRUCT{
	int lenght;
	GROUP_STRUCT arrayOfGroup[ 10 ];
	string name;
	STUDENT_STRUCT teacher;
};

/* Ilosc cyfr w liczbie naturalnej */
int DigitalNumber( int num ){
	int i = 0; 
	if( num == 0 )
		return 1;
		
	while( num > 0 ){
		i++;
		num /= 10;
	}
	
	return i;
}

/* Wyswietla linie o danej wielkosci */
void RowLine( int size ){
	for( int i = 0; i < size ; i++ )
			cout << "-";
		cout << endl;	
}

/* Wyswietlenie studentow */
void ShowStudents( STUDENT_STRUCT students[], int length ,int nameSize, int surnameSize, int birthSize = 18, int startSize = 27 ){
	int rowSize = nameSize + surnameSize + birthSize + startSize + 12; // dlugosc lini
	RowLine( rowSize );
	
	cout << "|Imie ";
	for( int i = 5; i <= nameSize; i++)
		cout << " ";
	cout << "|Nazwisko ";
	for( int i = 9; i <= surnameSize; i++)
		cout << " ";
	cout << "|Stypendium ";
	cout << "|Data Urodzenia ";
	cout << "|Data Rozpoczecia Nauki |";
	cout << endl;
	
	RowLine( rowSize );
	
	for( int i = 0; i < length; i++ ){
		cout << "|";
		cout << students[ i ].name;
		for( int j = students[ i ].name.size(); j <= nameSize; j++) // wyrownianie kolumny
			cout << " ";
		cout << "|";
		cout << students[ i ].surname;
		for( int j = students[ i ].surname.size(); j <= surnameSize; j++) // wyrownanie kolumny
			cout << " ";
		cout << "|";
		
		// poprawne wyswietlenie floata
		cout << (int)(students[ i ].stypendium * 100.0)/100 << "." << (int)( ( students[ i ].stypendium  - (int)(students[ i ].stypendium) ) * 100);
		for( int j = DigitalNumber( (int)(students[ i ].stypendium * 100.0)/100 ) + DigitalNumber(  (int)( ( students[ i ].stypendium  - (int)(students[ i ].stypendium) ) * 100) ); j < 10; j++)
			cout << " ";
		cout << "|";
		
		cout << students[ i ].start.year <<"-";
		if( DigitalNumber( students[ i ].start.month ) == 1) // wyrownanie kolumny
			cout << "0";
		cout << students[ i ].start.month <<"-";
		if( DigitalNumber( students[ i ].start.day ) == 1) // wyrownanie kolumny
			cout << "0";
		cout << students[ i ].start.day << "     |";
		
		cout << students[ i ].start.year <<"-";
		if( DigitalNumber( students[ i ].start.month ) == 1) // wyrownanie kolumny
			cout << "0";
		cout << students[ i ].start.month <<"-";
		if( DigitalNumber( students[ i ].start.day ) == 1) // wyrownanie kolumny
			cout << "0";
		cout << students[ i ].start.day << "             |";
	
		cout << endl;
	}
	RowLine( rowSize );
	
}

/*
	Fukcja wyswietlajaca nauczyciela
*/
void ShowTeacher( STUDENT_STRUCT teacher){
	int rowSize = 11;
	// okreslenie dlugosc lini
	if( teacher.name.size() > rowSize)
		rowSize = teacher.name.size();
	if( teacher.surname.size() > rowSize)
		rowSize = teacher.surname.size();	
	if( DigitalNumber( ((int)(teacher.stypendium * 100.0))/100.0) > rowSize)
		rowSize = DigitalNumber( ((int)(teacher.stypendium * 100.0))/100.0);	
	
	rowSize += 24;
	
	cout << "Prowadzacy" << endl;
	RowLine( rowSize );
	cout << "Imie:                    " << teacher.name << endl;
	RowLine( rowSize );
	cout << "Nazwisko:                " << teacher.surname << endl;
	RowLine( rowSize );
	cout << "Pensja:                  " << teacher.stypendium << endl;
	RowLine( rowSize );
	cout << "Data Urodzenia:          " << teacher.birth.year << "-" << teacher.birth.month << "-" << teacher.birth.day << endl;
	RowLine( rowSize );
	cout << "Data Rozpoczecia Nauki:  " << teacher.start.year << "-" << teacher.start.month << "-" << teacher.start.day << endl;
	RowLine( rowSize );
}

int main(){
	SUBJECT_STRUCT subject;
	
	int maksStudentName = 5;
	int maksStudentSurname = 9;
	
	cin >> subject.lenght;
	cin >> subject.name;
	cin >> subject.teacher.name >> subject.teacher.surname >> subject.teacher.stypendium;
	cin >> subject.teacher.birth.day >> subject.teacher.birth.month >> subject.teacher.birth.year;
	cin >> subject.teacher.start.day >> subject.teacher.start.month >> subject.teacher.start.year;
	
	for( int i = 0; i < subject.lenght; i++){ // wczytywanie grupy
		cin >> subject.arrayOfGroup[ i ].name;
		
		cin >> subject.arrayOfGroup[ i ].lenght;
		for( int j = 0; j < subject.arrayOfGroup[ i ].lenght ; j++){ // wczytywanie studentow
			cin >> subject.arrayOfGroup[ i ].arrayOfStudent[ j ].name;
			
			if( subject.arrayOfGroup[ i ].arrayOfStudent[ j ].name.size() > maksStudentName ) // maksymalna dlugosc
				maksStudentName = subject.arrayOfGroup[ i ].arrayOfStudent[ j ].name.size();
			
			cin >> subject.arrayOfGroup[ i ].arrayOfStudent[ j ].surname;
			
			if( subject.arrayOfGroup[ i ].arrayOfStudent[ j ].surname.size() > maksStudentSurname ) // maksymalna dlugosc
				maksStudentSurname = subject.arrayOfGroup[ i ].arrayOfStudent[ j ].surname.size();
			
			cin >> subject.arrayOfGroup[ i ].arrayOfStudent[ j ].stypendium;
			
			cin >> subject.arrayOfGroup[ i ].arrayOfStudent[ j ].birth.day;
			cin >> subject.arrayOfGroup[ i ].arrayOfStudent[ j ].birth.month;
			cin >> subject.arrayOfGroup[ i ].arrayOfStudent[ j ].birth.year;
			
			cin >> subject.arrayOfGroup[ i ].arrayOfStudent[ j ].start.day;
			cin >> subject.arrayOfGroup[ i ].arrayOfStudent[ j ].start.month;
			cin >> subject.arrayOfGroup[ i ].arrayOfStudent[ j ].start.year;
			}
		}
	
	// wyswietlania
	cout << "Nazwa przedmiotu: " <<  subject.name << "(liczba grup: " << subject.lenght << ")"<< endl;
	ShowTeacher( subject.teacher );
	cout << endl;
	
	for( int i = 0; i < subject.lenght; i++ ){
		cout << "Grupa: " << subject.arrayOfGroup[i].name << endl;
		ShowStudents( subject.arrayOfGroup[ i ].arrayOfStudent , subject.arrayOfGroup[ i ].lenght,  maksStudentName, maksStudentSurname );
		
		}

	return 0;
	}
