#include <iostream>
#include <string>

class Dyplom{
private:
	const std::string name;
	const std::string surname;
	const std::string course;
	const unsigned year;
	double average;
	static const std::string university;
	static double allAverage;	
	static unsigned numberOfAbsolvents;
public:
	
	Dyplom( std::string name, std::string surname, std::string course, unsigned year, double average ) 
			:name(name), surname(surname), course(course), year(year){
		Dyplom::numberOfAbsolvents++;
		Dyplom::allAverage = ( Dyplom::allAverage*(Dyplom::numberOfAbsolvents-1)+average ) / Dyplom::numberOfAbsolvents;
		this->average = average;
	}	
	
	void changeAverage( double newAverage ){
		Dyplom::allAverage = ( ( Dyplom::allAverage*Dyplom::numberOfAbsolvents ) - average + newAverage ) / Dyplom::numberOfAbsolvents;
		this->average = newAverage;
	}
	
	void print(){
		std::cout << "---    Dyplom    ---" << std::endl;
		std::cout << "Imie: " << name << std::endl;
		std::cout << "Nazwisko: " << surname << std::endl;
		std::cout << "Kierunek: " << course << std::endl;
		std::cout << "Rocznik: " << year << std::endl;
		std::cout << "Uczelnia: " << university << std::endl;
		std::cout << "Liczba absolwentow: " << numberOfAbsolvents << std::endl;
		std::cout << "Srednia ocen: " << average << std::endl;
		std::cout << "Srednia ocen wszystkich absolwentow: " << allAverage << std::endl;
		std::cout << std::endl;
	}
	
};

unsigned Dyplom::numberOfAbsolvents = 0;
double Dyplom::allAverage = 0.0;
const std::string Dyplom::university = "UJ";

int main(){
	Dyplom jan("Jan", "Kowalski", "Informatyka", 1995, 4.3);
	Dyplom jacek("Jacek", "Malinowski", "Matematyka", 1989, 4.25);
	Dyplom michal("Michal", "Grzyb", "Jezykoznawstwo", 2000, 4.5);
	Dyplom marek("Marek", "Migdal", "Medycyna", 1889, 3.0);
	
	jan.print();
	jan.changeAverage(5.0);
	jan.print();
	return 0;
}
