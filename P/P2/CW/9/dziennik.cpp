//jedna metoda abstrakcyjna - klasa abstrakcyjna
//same abstrakcyjne - interfejs

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Ocena {
public:
	enum Wartosc { NDST = 1, DOP, DST, DB, BDB };
	enum Waga { ODPOWIEDZ = 1, KARTKOWKA, SPRAWDZIAN };

	Wartosc wartosc;
	Waga waga;
	
	Ocena( Wartosc wartosc, Waga waga ) : wartosc( wartosc ), waga( waga ){}
};

class WierszDziennika : public vector<Ocena> {
private:
	string imie;
	string nazwisko;
public:
	WierszDziennika( string imie, string nazwisko ): imie( imie ), nazwisko( nazwisko ){}
	~WierszDziennika(){}
	
	string Imie() const { return imie; }
	string Nazwisko() const { return nazwisko; }
};

class ZasadaOceniania {
public:
	virtual int ocen(const WierszDziennika& wd) const = 0;
};

class ProstaSrednia : public ZasadaOceniania {
public:
	int ocen( const WierszDziennika& wd ) const {
		unsigned rozmiar = wd.size();
		double srednia = 0;
		for( unsigned i = 0; i < rozmiar; i++ )
			srednia +=  (double)wd[ i ].wartosc;
		if( srednia < 1.0 ) return 1;
		return (int)(srednia/(double)rozmiar);
	}
}; 

class SredniaWazona : public ZasadaOceniania {
public:
	int ocen( const WierszDziennika& wd ) const {
		unsigned rozmiar = wd.size();
		unsigned licznaOcen = 0;
		double srednia = 0;
		for( unsigned i = 0; i < rozmiar; i++ ){
			srednia +=  (double)wd[ i ].wartosc * (double)wd[ i ].waga;
			licznaOcen += wd[ i ].waga;
		}
		if( srednia < 1.0 ) return 1;
		return (int)(srednia/(double)licznaOcen);
	}
};

class SredniaWazonaWGore : public ZasadaOceniania {
public:
	int ocen( const WierszDziennika& wd ) const {
		unsigned rozmiar = wd.size();
		unsigned licznaOcen = 0;
		double srednia = 0;
		for( unsigned i = 0; i < rozmiar; i++ ){
			srednia +=  (double)wd[ i ].wartosc * (double)wd[ i ].waga;
			licznaOcen += wd[ i ].waga;
		}
		if( srednia < 1.0 ) return 1;
		return (int)ceil( srednia/(double)licznaOcen );
	}
};

class ProstaSredniaBezOdpowiedzi : public ZasadaOceniania {
public:
	int ocen( const WierszDziennika& wd ) const {
		unsigned rozmiar = wd.size();
		unsigned licznaOcen = 0;
		double srednia = 0;
		for( unsigned i = 0; i < rozmiar; i++ )
			if( wd[ i ].waga != Ocena::ODPOWIEDZ ){
				srednia +=  (double)wd[ i ].wartosc;
				licznaOcen++;
			}
		if( srednia < 1.0 ) return 1;
		return (int)(srednia/(double)licznaOcen);
	}
};

class Drukarz {
public:
	virtual string drukujNaglowek() const = 0;
	virtual string drukujWiersz(const WierszDziennika& wd) const = 0;
	virtual string drukujStopke() const = 0;

};

class ProsteWyswietlenie : public Drukarz {
public:
	string drukujNaglowek() const {
		return "---------- Oceny Prost Wyswietlanie ----------\n";	
	}
	string drukujWiersz(const WierszDziennika& wd) const {
		string wiersz = "";
		unsigned rozmiar = wd.size();
		
		wiersz += wd.Imie() + " " + wd.Nazwisko() + ": ";
		for( unsigned i = 0; i < rozmiar; i++ ){
			wiersz += to_string( wd[ i ].wartosc ) + " ";	
		}
		wiersz += "\n";
		return wiersz;
	};
	virtual string drukujStopke() const {
		return "---------- Koniec Oceny ----------\n";	
	}
};

class ZaawansowaneWyswietlanie : public Drukarz {
public:
	string drukujNaglowek() const {
		return "---------- Oceny Zaawansowane Wyswietlanie ----------\n";	
	}
	string drukujWiersz(const WierszDziennika& wd) const {
		string wiersz = "";
		unsigned rozmiar = wd.size();
		
		wiersz += wd.Imie() + " " + wd.Nazwisko() + ": ";
		for( unsigned i = 0; i < rozmiar; i++ ){
			switch( wd[ i ].waga ){
				case Ocena::SPRAWDZIAN:
					wiersz += "<sprawdzian>";
					break;
				case Ocena::KARTKOWKA:
					wiersz += "<kartkowa>";
					break;
				case Ocena::ODPOWIEDZ:
					wiersz += "<odpowiedz>";
					break;
				
			}
			wiersz += to_string( wd[ i ].wartosc ) + " ";	
		}
		wiersz += "\n";
		return wiersz;
	};
	virtual string drukujStopke() const {
		return "---------- Koniec Oceny ----------\n";	
	}
};

class SlowneWyswietlanie : public Drukarz {
public:
	string drukujNaglowek() const {
		return "---------- Oceny Slowne Wyswietlanie ----------\n";	
	}
	string drukujWiersz(const WierszDziennika& wd) const {
		string wiersz = "";
		unsigned rozmiar = wd.size();
		
		wiersz += wd.Imie() + " " + wd.Nazwisko() + ": ";
		for( unsigned i = 0; i < rozmiar; i++ ){
			switch( wd[ i ].waga ){
				case Ocena::SPRAWDZIAN:
					wiersz += "sprawdzian - ";
					break;
				case Ocena::KARTKOWKA:
					wiersz += "kartkowka - ";
					break;
				case Ocena::ODPOWIEDZ:
					wiersz += "odpowiedz - ";
					break;
				
			}
			
			switch( wd[ i ].wartosc ){
				case Ocena::BDB:
					wiersz += "BDB ";
					break;
				case Ocena::DB:
					wiersz += "DB ";
					break;
				case Ocena::DST:
					wiersz += "DST ";
					break;
				case Ocena::DOP:
					wiersz += "DOP ";
					break;
				case Ocena::NDST:
					wiersz += "NDST ";
					break;		
			}
		}
		wiersz += "\n";
		return wiersz;
	};
	virtual string drukujStopke() const {
		return "---------- Koniec Oceny ----------\n";	
	}
};

class Dziennik : public vector<WierszDziennika> {
private:
	ZasadaOceniania & zasadaOceniania;
	Drukarz& drukarz;
public:
	Dziennik(ZasadaOceniania& _zasadaOceniania, Drukarz& _drukarz) : zasadaOceniania(_zasadaOceniania), drukarz(_drukarz) {};
	void ocen() {
		unsigned rozmiar = this->size();
		cout << "Oceny: " << endl;
		
		for( unsigned i = 0; i < rozmiar; i++ )
			cout << this->at( i ).Imie() << " " << this->at( i ).Nazwisko() << " " <<  zasadaOceniania.ocen( this->at( i ) ) << endl;
	};
	void drukuj() {
		unsigned rozmiar = this->size();
		for( unsigned i = 0; i < rozmiar; i++ ){
			cout << drukarz.drukujNaglowek();
			cout << drukarz.drukujWiersz( this->at( i ) );
			cout << drukarz.drukujStopke();
		}
	};
};


int main(){
	WierszDziennika wd1( "Jan", "Kowalski" );
	WierszDziennika wd2( "Antoni", "Malinowski" );
	WierszDziennika wd3( "Weronika", "Truskawka" );
	WierszDziennika wd4( "Jacek", "Marek" );
	WierszDziennika wd5( "Michal", "Tracz" );
	WierszDziennika wd6( "Zbigniew", "Mucha" );
	
	wd1.push_back( { Ocena::NDST, Ocena::ODPOWIEDZ } );
	wd1.push_back( { Ocena::BDB, Ocena::SPRAWDZIAN } );
	wd1.push_back( { Ocena::DB, Ocena::KARTKOWKA } );
	wd1.push_back( { Ocena::DST, Ocena::SPRAWDZIAN } );
	
	
	wd2.push_back( { Ocena::NDST, Ocena::KARTKOWKA } );
	wd2.push_back( { Ocena::NDST, Ocena::SPRAWDZIAN } );
	wd2.push_back( { Ocena::BDB, Ocena::KARTKOWKA } );
	wd2.push_back( { Ocena::BDB, Ocena::SPRAWDZIAN } );
	
	wd3.push_back( { Ocena::DB, Ocena::ODPOWIEDZ } );
	wd3.push_back( { Ocena::DST, Ocena::SPRAWDZIAN } );
	wd3.push_back( { Ocena::DOP, Ocena::KARTKOWKA } );
	wd3.push_back( { Ocena::BDB, Ocena::SPRAWDZIAN } );
	
	wd4.push_back( { Ocena::NDST, Ocena::ODPOWIEDZ } );
	wd4.push_back( { Ocena::NDST, Ocena::ODPOWIEDZ } );
	wd4.push_back( { Ocena::NDST, Ocena::KARTKOWKA } );
	wd4.push_back( { Ocena::NDST, Ocena::SPRAWDZIAN } );
	
	wd5.push_back( { Ocena::DOP, Ocena::ODPOWIEDZ } );
	wd5.push_back( { Ocena::DB, Ocena::ODPOWIEDZ } );
	wd5.push_back( { Ocena::DB, Ocena::KARTKOWKA } );
	wd5.push_back( { Ocena::DST, Ocena::SPRAWDZIAN } );
	
	wd6.push_back( { Ocena::DOP, Ocena::ODPOWIEDZ } );
	wd6.push_back( { Ocena::DB, Ocena::ODPOWIEDZ } );
	wd6.push_back( { Ocena::DB, Ocena::KARTKOWKA } );
	wd6.push_back( { Ocena::DST, Ocena::SPRAWDZIAN } );
	
	ProstaSrednia prostaSrednia;
	SredniaWazona sredniaWazona;
	ProstaSredniaBezOdpowiedzi prostaSredniaBezOdpowiedzi;
	
	ProsteWyswietlenie prosteWyswietlanie;
	ZaawansowaneWyswietlanie zaawansowaneWyswietlanie;
	SlowneWyswietlanie slowneWyswietlanie;
	
	
	cout << "--------------- Dziennik 1 ---------------" << endl << endl; 
	Dziennik dziennik1( prostaSrednia, prosteWyswietlanie );
	dziennik1.insert( dziennik1.begin(), { wd1, wd2, wd3, wd4, wd5, wd6 } );
	dziennik1.ocen();
	dziennik1.drukuj();
	cout << endl << endl;
	
	cout << "--------------- Dziennik 2 ---------------" << endl << endl; 
	Dziennik dziennik2( sredniaWazona, zaawansowaneWyswietlanie );
	dziennik2.insert( dziennik2.begin(), { wd1, wd2, wd3, wd4, wd5, wd6 } );
	dziennik2.ocen();
	dziennik2.drukuj();
	cout << endl << endl;
	
	cout << "--------------- Dziennik 3 ---------------" << endl << endl; 
	Dziennik dziennik3( prostaSredniaBezOdpowiedzi, slowneWyswietlanie );
	dziennik3.insert( dziennik3.begin(), { wd1, wd2, wd3, wd4, wd5, wd6 } );
	dziennik3.ocen();
	dziennik3.drukuj();
	cout << endl << endl;
		

	return 0;
}
