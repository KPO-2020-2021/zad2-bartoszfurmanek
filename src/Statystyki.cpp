#include "Statystyki.hh"
#include <iostream>


using namespace std;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */


/*!
 * Realizuje zerowanie wartości statystki.
 * Argumenty:
 *    Stat - Statytyska której wartości mają zostać wyzerowane.
 */

void Statystyka::Clear()
{
this->popr=0;
this->blad=0;
}

/*!
 * Realizuje dodawnie informacji o poprawnej odpowiedzi do statystyki.
 * Argumenty:
 *    Stat - Statytyska której wartości wartość poprawnych odpowiedzi ma zostać zwiększona.
 */

void Statystyka::PoprawnaOdpowiedz()
{
this->popr +=1;
}

/*!
 * Realizuje dodawnie informacji o błędnej odpowiedzi do statystyki.
 * Argumenty:
 *    Stat - Statytyska której wartości wartość błędnych odpowiedzi ma zostać zwiększona.
 */

void Statystyka::BlednaOdpowiedz()
{
this->blad +=1;
}

/*!
 * Realizuje procentowego obliczenia ilosci poprawnych odpowiedzi wzgledem wszystkich odpowiedzi.
 * Argumenty:
 *    Stat - Statytyska dla której ma zostać obliczony procent poprawnych odpowiedzi.
 * Zwraca:
 *    Procentowa wartość poprawnych odpowiedzi wzgledem wszystkich odpowiedzi.
 */

float Statystyka::ProcentPoprawnych()
{
return ((this->popr*100)/(this->popr+this->blad));
}

/*!
 * Realizuje wyswietlenie danych statystyki
 * Argumenty:
 *    Stat - Statytyska której dane maja zostac wyswietlone.
 */

void Statystyka::Wyswietl()
{
cout << endl;
cout << "Ilosc poprawnych odpowiedzi: " << this->popr << endl;
cout << "Ilosc blednych odpowiedzi: " << this->blad << endl;
cout << "Wynik procentowy poprawnych odpowedzi: " << (*this).ProcentPoprawnych() << "%";
}
