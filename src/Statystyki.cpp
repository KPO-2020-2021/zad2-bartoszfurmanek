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

void Clear(Statystyka &Stat)
{
Stat.popr=0;
Stat.blad=0;
}

/*!
 * Realizuje dodawnie informacji o poprawnej odpowiedzi do statystyki.
 * Argumenty:
 *    Stat - Statytyska której wartości wartość poprawnych odpowiedzi ma zostać zwiększona.
 */

void PoprawnaOdpowiedz(Statystyka &Stat)
{
Stat.popr +=1;
}

/*!
 * Realizuje dodawnie informacji o błędnej odpowiedzi do statystyki.
 * Argumenty:
 *    Stat - Statytyska której wartości wartość błędnych odpowiedzi ma zostać zwiększona.
 */

void BlednaOdpowiedz(Statystyka &Stat)
{
Stat.blad +=1;
}

/*!
 * Realizuje procentowego obliczenia ilosci poprawnych odpowiedzi wzgledem wszystkich odpowiedzi.
 * Argumenty:
 *    Stat - Statytyska dla której ma zostać obliczony procent poprawnych odpowiedzi.
 * Zwraca:
 *    Procentowa wartość poprawnych odpowiedzi wzgledem wszystkich odpowiedzi.
 */

float ProcentPoprawnych(Statystyka &Stat)
{
return ((Stat.popr*100)/(Stat.popr+Stat.blad));
}

/*!
 * Realizuje wyswietlenie danych statystyki
 * Argumenty:
 *    Stat - Statytyska której dane maja zostac wyswietlone.
 */

void Wyswietl(Statystyka Stat)
{
cout << endl;
cout << "Ilosc poprawnych odpowiedzi: " << Stat.popr << endl;
cout << "Ilosc blednych odpowiedzi: " << Stat.blad << endl;
cout << "Wynik procentowy poprawnych odpowedzi: " << ProcentPoprawnych(Stat) << "%";
}
