#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

/*
 * Tu nalezy zdefiniowac funkcje, ktore definiuja model statystyki 
 */

struct Statystyka
{
int popr;   //Pole reprezentujace ilosc poprawnych odpowiedzi
int blad;   //Pole reprezentujace ilosc blednych odpowiedzi

public:

void Clear();

void PoprawnaOdpowiedz();

void BlednaOdpowiedz();

float ProcentPoprawnych();

void Wyswietl();
};
#endif
