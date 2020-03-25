#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

class samochod
{
	public:
	string marka;
	string model;
	string rocznik;
	string pojemnosc;
	string przebieg;
	string typ_skrzyni_biegow;
	public:
	samochod(__cxx11::string ma,__cxx11::string mo,__cxx11::string ro,__cxx11::string poj,__cxx11::string prz,__cxx11::string typ):marka(ma),model(mo),rocznik(ro),pojemnosc(poj),przebieg(prz),typ_skrzyni_biegow(typ) {}
	string toString()//zwraca elementy klasy jako string
	{
		return(marka+" "+model+" "+rocznik+" "+pojemnosc+" "+przebieg+" "+typ_skrzyni_biegow+"\n");
	}
	friend struct porownanie;

};

class operacje_na_samochodach
{
	private:
	vector <samochod> samochody;
	public:
	void dodaj();
	vector<samochod> wczytaj();
	void zapisz();
	void lista();
	void lista_warunek_rocznik();
	void lista_warunek_pojemnosc();
	void lista_warunek_przebieg();
	void usun();

	vector <samochod> sortuj_marka();
	vector <samochod> sortuj_model();
	vector <samochod> sortuj_rocznik();
	vector <samochod> sortuj_pojemnosc();
	vector <samochod> sortuj_przebieg();
	vector <samochod> sortuj_typ_skrzyni_biegow();
	void lista_kopii(vector<samochod> kopia);
};

struct porownanie{
	int parametr;
	porownanie(int parametr){this->parametr=parametr;}
	bool operator()(const samochod & s1, const samochod & s2) const
	{
		switch(parametr)
		{
			case 1:
			{
				return s1.marka<s2.marka;
				break;
			}
			case 2:
			{
				return s1.model<s2.model;
				break;
			}
			case 3:
			{
				return s1.rocznik<s2.rocznik;
				break;
			}
			case 35:
			{
				return s1.rocznik.length()<s2.rocznik.length();
				break;
			}
			case 4:
			{
				return s1.pojemnosc<s2.pojemnosc;
				break;
			}
			case 45:
			{
				return s1.pojemnosc.length()<s2.pojemnosc.length();
				break;
			}
			case 5:
			{
				return s1.przebieg<s2.przebieg;
				break;
			}
			case 55:
			{
				return s1.przebieg.length()<s2.przebieg.length();
				break;
			}
			case 7:
			{
				return s1.rocznik<"2000";
				break;
			}
			default:
			{
				return s1.typ_skrzyni_biegow<s2.typ_skrzyni_biegow;
				break;
			}
		}
	}
};
void operacje_na_samochodach::dodaj()
{
	string ma,mo,ro,poj,prz,typ;
	cout<<"Marka: ";
	cin>>ma;
	cout<<"Model: ";
	cin>>mo;
	cout<<"Rocznik: ";
	cin>>ro;
	cout<<"Pojemnosc: ";
	cin>>poj;
	cout<<"Przebieg: ";
	cin>>prz;
	cout<<"Typ skrzyni biegów: ";
	cin>>typ;
	samochod tmp(ma,mo,ro,poj,prz,typ);
	samochody.push_back(tmp);
	
}
vector<samochod> operacje_na_samochodach::wczytaj()
{
	samochody.clear();
	ifstream plik("katalog.txt");
	while(plik)
	{
		string ma,mo,ro,poj,prz,typ;
		plik>>ma>>mo>>ro>>poj>>prz>>typ;
		samochod tmp(ma,mo,ro,poj,prz,typ);
		samochody.push_back(tmp);
	}
	plik.close();
	return samochody;
}

void operacje_na_samochodach::zapisz()
{
	ofstream plik("katalog.txt",ios::out|ios::trunc);
	for(vector<samochod>::iterator i = samochody.begin();i<samochody.end();i++)
	plik<<i->toString();
	plik.close();
}

void operacje_na_samochodach::lista()
{
	for(vector<samochod>::iterator i = samochody.begin();i<samochody.end();i++)
	{
		cout<<i->toString();
	}
}

void operacje_na_samochodach::lista_warunek_rocznik()
{
	vector<samochod> samo;
	string warunek;
	cin>>warunek;
	for(auto&samochody : samochody)
		{
	if(samochody.rocznik.length()>warunek.length())
	samo.push_back(samochody);
	else
	{if(samochody.rocznik.length()==warunek.length())
		if(samochody.rocznik>warunek)
		samo.push_back(samochody);
	}}
	for(vector<samochod>::iterator i= samo.begin();i<samo.end();i++)
	{
		cout<<i->toString();
	}
}
void operacje_na_samochodach::lista_warunek_pojemnosc()
{
	vector<samochod> samo;
	string warunek;
	cin>>warunek;
	for(auto&samochody : samochody)
	{
	if(samochody.pojemnosc.length()>warunek.length())
	samo.push_back(samochody);
	else
	{if(samochody.pojemnosc.length()==warunek.length())
		if(samochody.pojemnosc>warunek)
		samo.push_back(samochody);
	}}
	for(vector<samochod>::iterator i= samo.begin();i<samo.end();i++)
	{
		cout<<i->toString();
	}
}
void operacje_na_samochodach::lista_warunek_przebieg()
{
	vector<samochod> samo;
	string warunek;
	cin>>warunek;
	for(auto&samochody : samochody)
		{
	if(samochody.przebieg.length()>warunek.length())
	samo.push_back(samochody);
	else
	{if(samochody.przebieg.length()==warunek.length())
		if(samochody.przebieg>warunek)
		samo.push_back(samochody);
	}}
	for(vector<samochod>::iterator i= samo.begin();i<samo.end();i++)
	{
		cout<<i->toString();
	}
}


void operacje_na_samochodach::usun()
{
	int dousuniecia;
	cout<<"Ktory samochod usunac?";
	cin>>dousuniecia;
	iter_swap(samochody.begin(),samochody.begin()+(dousuniecia-1));
	if(samochody.size()>0)
	samochody.erase(samochody.begin());
}

vector <samochod> operacje_na_samochodach::sortuj_marka()
{
	int parametr=1;	//numer parametru
	vector<samochod> samochody_kopia=samochody;
	sort(samochody_kopia.begin(),samochody_kopia.end(),porownanie(parametr));
	return samochody_kopia;
}
vector <samochod> operacje_na_samochodach::sortuj_model()
{
	int parametr=2;
	vector<samochod> samochody_kopia=samochody;
	sort(samochody_kopia.begin(),samochody_kopia.end(),porownanie(parametr));
	return samochody_kopia;
}
vector <samochod> operacje_na_samochodach::sortuj_rocznik()
{
	int parametr=3;
	vector<samochod> samochody_kopia=samochody;
	sort(samochody_kopia.begin(),samochody_kopia.end(),porownanie(parametr));
	parametr=35;
	sort(samochody_kopia.begin(),samochody_kopia.end(),porownanie(parametr));
	return samochody_kopia;
}
vector <samochod> operacje_na_samochodach::sortuj_pojemnosc()
{
	int parametr=4;
	vector<samochod> samochody_kopia=samochody;
	sort(samochody_kopia.begin(),samochody_kopia.end(),porownanie(parametr));
	parametr=45;
	sort(samochody_kopia.begin(),samochody_kopia.end(),porownanie(parametr));
	return samochody_kopia;
}
vector <samochod> operacje_na_samochodach::sortuj_przebieg()
{
	int parametr=5;
	vector<samochod> samochody_kopia=samochody;
	sort(samochody_kopia.begin(),samochody_kopia.end(),porownanie(parametr));
	parametr=55;
	sort(samochody_kopia.begin(),samochody_kopia.end(),porownanie(parametr));
	return samochody_kopia;
}
vector <samochod> operacje_na_samochodach::sortuj_typ_skrzyni_biegow()
{
	int parametr=6;
	vector<samochod> samochody_kopia=samochody;
	sort(samochody_kopia.begin(),samochody_kopia.end(),porownanie(parametr));
	return samochody_kopia;
}
void operacje_na_samochodach::lista_kopii(vector <samochod> kopia)
{
	for(vector<samochod>::iterator i=kopia.begin();i<kopia.end();i++)
	{
		cout<<i->toString();
	}
}
/*
bool operacje_na_samochodach::operator <(const samochod &s2)
{return this-> marka<s2.marka();}
*/
int menu()
{
	int wybor;
	cout<<"\n\t\tKatalog samochodow\n1.Lista samochodow\n2.Lista samochodow (warunek)\n3.Sortowanie po parametrze\n4.Dodaj samochod do katalogu\n5.Usun samochod z katalogu\n6.Wyjscie\n";
	while( !( cin >> wybor ) )//zabezpieczenie przed wpisywaniem liter
{
	cout<<"To nie cyfra!\n";
    cin.clear();
    cin.sync();
    cin.ignore(INT8_MAX,'\n');
}
	return wybor;
}


int main()
{
	//cout<<"Prosze uzywac WIELKICH liter"; //podyktowane brakiem czasu
	//vector <samochod> samochody;
	int wybor;
	bool chcejeszcze=true;
	operacje_na_samochodach operacje;
	while(chcejeszcze)
	{
	wybor=menu();
	operacje.wczytaj();
	switch(wybor)
	{
	case 1:
	{
		cout<<"\nLista samochodow\n";
		operacje.lista();
		break;
	}
	case 2:
	{
		cout<<"\nLista samochodow (warunek)";
		int war;
		cout<<" - Wybierz warunek\n1.Rocznik\n2.Pojemnosc\n3.Przebieg\n";
		cin>>war;
		cout<<"\nWieksze od: ";
		switch(war)
		{
		case 1:
		{
			operacje.lista_warunek_rocznik();
			break;
		}
		case 2:
		{
			operacje.lista_warunek_pojemnosc();
			break;
		}
		case 3:
		{
			operacje.lista_warunek_przebieg();
			break;
		}
		}
		break;
	}
	case 3:
	{
		int sortowanie;
		cout<<"Sortowanie po parametrze - Wybierz parametr do posortowania\n1.Sortowanie po marce Alfabetycznie\n2.Sortowanie po modelu Alfabetycznie\n3.Sortowanie po roczniku\n4.Sortowanie po pojemnosci\n5.Sortowanie po przebiegu\n6.Sortowanie po typie skrzyni biegow\n";
		cin>>sortowanie;
		switch(sortowanie)
		{
			case 1:
			{
				cout<<"Sortowanie po marce Alfabetycznie\n\n";
				operacje.lista_kopii(operacje.sortuj_marka());
				break;
			}
			case 2:
			{
				cout<<"Sortowanie po modelu Alfabetycznie\n\n";
				operacje.lista_kopii(operacje.sortuj_model());
				break;
			}
			case 3:
			{
				cout<<"Sortowanie po roczniku\n\n";
				operacje.lista_kopii(operacje.sortuj_rocznik());
				break;
			}
			case 4:
			{
				cout<<"Sortowanie po pojemnosci\n\n";
				operacje.lista_kopii(operacje.sortuj_pojemnosc());
				break;
			}
			case 5:
			{
				cout<<"Sortowanie po przebiegu\n\n";
				operacje.lista_kopii(operacje.sortuj_przebieg());
				break;
			}
			case 6:
			{
				cout<<"Sortowanie po typie skrzyni biegow\n\n";
				operacje.lista_kopii(operacje.sortuj_typ_skrzyni_biegow());
				break;
			}
		}
		break;
	}
	case 4:
	{
		cout<<"Dodaj samochod\n";
		operacje.dodaj();
		operacje.zapisz();
		break;
	}
	case 5:
	{
		cout<<"Usun samochod\n";
		operacje.lista();
		operacje.usun();
		operacje.zapisz();
		break;
	}
	case 6:
	{
		cout<<"Do widzenia!";
		chcejeszcze=false;
		break;
	}
	default:
	{
		cout<<"Traf dobrze";
		break;
	}
}
}
return 1;
}
