//Sebastian Jadczak Zadanie 

/*
Podproblemy:

Wczytać informację od użytkownika do struktur (imie nazwisko i pelna date urodzenia)
Posortować tablicę użytkowników, tak by najstarszy był pierwszy wyświetlany
Wyświetlic użytkowników od najstarszego.

*/


#include <iostream>

const int MAX_OSOB = 40;

//Struktura daty urodzin użytkownika
struct Data
{
	int dzien;
	int miesiac;
	int rok;
}data;

//Struktura danych personalnych użytkownika
struct Osoba
{
	char imie[20];
	char nazwisko[20];
	struct Data data;
}osoba[MAX_OSOB];


//Wypełnienie informacji o użytkowniku, użytkownik podaje imie, nazwisko, dzien, miesiac, rok urodzenia.
void wypelnij(int* ileOsob, Osoba osoba[MAX_OSOB])
{
	for (int i = 0; i < *ileOsob; i++)
	{
		std::cout << i + 1 << "." << std::endl;
		std::cout << "Podaj imie: " << std::endl;
		std::cin >> osoba[i].imie;
		std::cout << " Podaj nazwisko: " << std::endl;
		std::cin >> osoba[i].nazwisko;
		std::cout << "Podaj dzien urodzenia:" << std::endl;
		std::cin >> osoba[i].data.dzien;
		std::cout << "Podaj miesiac urodzenia:" << std::endl;
		std::cin >> osoba[i].data.miesiac;
		std::cout << "Podaj rok urodzenia:" << std::endl;
		std::cin >> osoba[i].data.rok;

	}
}

//Sortujemy użytkowników od najstarszego do najmłodszego
void sortowanie(Osoba osoba[MAX_OSOB], int* ileOsob)
{
	struct Osoba temp;
	for (int i = 1; i < *ileOsob; i++)
		for (int j = 0; j < *ileOsob - i; j++)
		{
			if (osoba[j].data.rok > osoba[j + 1].data.rok) 
			{
				temp = osoba[j];
				osoba[j] = osoba[j + 1];
				osoba[j + 1] = temp;
			}
		}
}

//Wyświetlamy użytkowników, już posortowanych
void wyswietl(Osoba osoba[MAX_OSOB], int *ileOsob)
{
	for (int i = 0; i < *ileOsob; i++)
	{
		std::cout << "";
		std::cout << " Lista nazwisk według wieku uporządkowana malejąco ";
		std::cout << osoba[i].nazwisko << std::endl;
	}
}

int main()
{
	int ileOsob=0;
	std::cout << "Ilu osob dane chcesz wprowadzic? " << std::endl;
	std::cin >> ileOsob;

	//Jeśli użytkownik wprowadzi zbyt dużą liczbę, zostanie o tym poinformowany.
	if (ileOsob > MAX_OSOB)
	{
		std::cout << "Wprowadź liczbę mniejszą od 40";
		std::cin >> ileOsob;
	}
	wypelnij(&ileOsob, osoba);
	wyswietl(osoba, &ileOsob);
}
