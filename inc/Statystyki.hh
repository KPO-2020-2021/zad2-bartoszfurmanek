#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

/*
 * Tu nalezy zdefiniowac funkcje, ktore definiuja model statystyki 
 */

struct Statystyka
{
int popr;   //Pole reprezentujace ilosc poprawnych odpowiedzi
int blad;   //Pole reprezentujace ilosc blednych odpowiedzi
};

void Clear(Statystyka &Stat);

void PoprawnaOdpowiedz(Statystyka &Stat);

void BlednaOdpowiedz(Statystyka &Stat);

float ProcentPoprawnych(Statystyka &Stat);

void Wyswietl(Statystyka Stat);
#endif
