#include <iostream>
#include <string>


class Procesor{
private:
	std::string name;
	int benchmark;	
public:
	
	Procesor(){
		std::cout << "[PROCESOR]Konstruktor domyslny" << std::endl;
		name = "";
		benchmark = 0;
	}
	Procesor( std::string n ){
		std::cout << "[PROCESOR]Konstruktor z jednym parametrem" << std::endl;
		name = n;
		benchmark = 0;
	}
	Procesor( std::string n, int b ){
		std::cout << "[PROCESOR]Konstruktor z dwoma parametrami" << std::endl;
		name = n;
		benchmark = b;
	}
		
	void Licz(){
		std::cout << "[PROCESOR]Dokonuje obliczen..." << std::endl;
	}
	void Wymien( std::string n, int b ){
		std::cout << "[PROCESOR]Wymiana" << std::endl;
		name = n;
		benchmark = b;
	}
	void Wyswietl(){
		std::cout << "[PROCESOR]" << name << " Benchmark: " << benchmark << std::endl;
	}
};

class KartaGraficzna{
private:
	std::string name;
	int benchmark;	
public:
	KartaGraficzna(std::string n = "",int b = 0 ){
		std::cout << "[KartaGraficzna]Konstruktor z parametrami domyslnymi" << std::endl;
		name = n;
		benchmark = b;
	}
	
	void RenderujObraz(){
		std::cout << "[KartaGraficzna]Renderuje obraz..." << std::endl;
	}
	void Wymien( std::string n, int b ){
		std::cout << "[KartaGraficzna]Wymiana" << std::endl;
		name = n;
		benchmark = b;
	}
	void Wyswietl(){
		std::cout << "[KartaGraficzna]" << name << " Benchmark: " << benchmark << std::endl;
	}	
};

class PamiecRAM{
private:
	std::string name;
	int mb;
	int benchmark;	
public:
	PamiecRAM(std::string n = "", int m = 0, int b = 0 ){
		std::cout << "[PamiecRAM]Konstruktor z parametrami domyslnymi" << std::endl;
		name = n;
		mb = m;
		benchmark = b;
	}
	
	void Zapisz(){
		std::cout << "[PamiecRAM]Zapis..." << std::endl;
	}
	void Wymien( std::string n, int m , int b ){
		std::cout << "[PamiecRAM]Wymiana" << std::endl;
		name = n;
		mb = m;
		benchmark = b;
	}
	void Wyswietl(){
		std::cout << "[PamiecRAM]" << name << " " << mb << "MB"<< " Benchmark: " << benchmark << std::endl;
	}	
};

class DyskTwardy{
private:
	std::string name;
	int mb;
	int benchmark;	
public:
	
	DyskTwardy(){
		std::cout << "[DyskTwardy]Konstruktor domyslny" << std::endl;
		name = "";
		mb = 0;
		benchmark = 0;
	}
	DyskTwardy( std::string n ){
		std::cout << "[DyskTwardy]Konstruktor z jednym parametrem" << std::endl;
		name = n;
		benchmark = 0;
	}
	DyskTwardy( std::string n, int m ){
		std::cout << "[DyskTwardy]Konstruktor z dwoma prametrami" << std::endl;
		name = n;
		mb = m;
		benchmark = 0;
	}
	DyskTwardy( std::string n, int m, int b ){
		std::cout << "[DyskTwardy]Konstruktor z trzema prametrami" << std::endl;
		name = n;
		mb = m;
		benchmark = b;
	}
		
	void Odczyt(){
		std::cout << "[DyskTwardy]Odczytuje..." << std::endl;
	}
	void Wymien( std::string n,int m, int b = 0){
		std::cout << "[DyskTwardy]Wymiana" << std::endl;
		name = n;
		mb = m;
		benchmark = b;
	}
	void Wyswietl(){
		std::cout << "[DyskTwardy]" << name << " " << mb << "MB" << " Benchmark: " << benchmark << std::endl;
	}
};

class KontrolerUSB{
private:
	std::string name;
	bool isValid;
public:
	KontrolerUSB(std::string n = "", bool v = false ){
		std::cout << "[KontrolerUSB]Konstruktor z parametrami domyslnymi" << std::endl;
		name = n;
		isValid = v;
	}
	
	void Polacz(){
		std::cout << "[KontrolerUSB]Laczenie..." << std::endl;
	}
	void Wymien( std::string n, bool v ){
		std::cout << "[KontrolerUSB]Wymiana" << std::endl;
		name = n;
		isValid = v;
	}
	void Wyswietl(){
		std::cout << std::boolalpha << "[KontrolerUSB]" << name << " Stan: " << isValid << std::endl;
	}	
};

class Komputer{
private:
 	Procesor procesor;
 	KartaGraficzna kartagraficzna;
 	PamiecRAM pamiecram;
 	DyskTwardy dysktwardy;
	KontrolerUSB kontrolerusb; 
public:	
	Komputer( ){
		std::cout<< "[KOMPUTER]Tworzenie pustego komputeru" << std::endl;
	}
	
	Komputer(std::string pN, int pB, 
		     std::string kN, int kB,
		     std::string ramN, int ramM, int ramB,
		     std::string dN, int dM, int dB,
		     std::string usbN, bool usbV )
			 :procesor(pN, pB), kartagraficzna(kN,kB),
			  pamiecram(ramN, ramM, ramB), dysktwardy(dN,dM,dB),
			  kontrolerusb(usbN,usbV)
			 {
		std::cout<< "[KOMPUTER]Tworzenie komputera z wszystkim" << std::endl;
	}
	
	void Wyswietl(){
		std::cout << std::endl << "[KOMPUTER]Twoj komputer: " << std::endl;

		procesor.Wyswietl();
		kartagraficzna.Wyswietl();
		pamiecram.Wyswietl();
		dysktwardy.Wyswietl();
		kontrolerusb.Wyswietl();
		
		std::cout << std::endl;
	}
	
	void Pracuj(){
		std::cout << std::endl << "[KOMPUTER]Twoj komputer pracuje: " << std::endl;
	
		kontrolerusb.Polacz();
		dysktwardy.Odczyt();
		procesor.Licz();
		pamiecram.Zapisz();
		kartagraficzna.RenderujObraz();
		
		std::cout << std::endl;
	}
	
	void WymienWszystko(std::string pN, int pB, 
				     std::string kN, int kB,
				     std::string ramN, int ramM, int ramB,
				     std::string dN, int dM, int dB,
				     std::string usbN, bool usbV ){
				     	
		std::cout << std::endl << "[KOMPUTER]Trwa wymiana twojego komputera: " << std::endl;
	
		procesor.Wymien(pN, pB);
		kartagraficzna.Wymien(kN,kB);
		pamiecram.Wymien(ramN,ramM,ramB);
		dysktwardy.Wymien(dN,dM,dB);
		kontrolerusb.Wymien(usbN,usbV);
		
		std::cout << std::endl;
	}
};

int main(){
	
	Komputer komputer1;
	komputer1.Wyswietl();
	
	Komputer komputer2( "Core 10", 1000, "Kaloryfer", 8745, "Dobry RAM", 8000, 5994, "Niebieski", 1000000, 2434, "Skaner USB" , true);
	komputer2.Wyswietl();
	komputer2.Pracuj();
	komputer2.WymienWszystko( "Core 20", 56000, "Podreczne Ogrzewanie Centralne", 99999, "Lepszy RAM", 16210, 10000, "Jeszcze bardziej niebieski", 1000000, 6002, "Radar USB" , true);
	komputer2.Wyswietl();
	return 0;
}
