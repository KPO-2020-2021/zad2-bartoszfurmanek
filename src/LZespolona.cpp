#include "LZespolona.hh"
#include <iostream>
#include <math.h>

#define MIN_ROZNICA 0.00001

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmnowania.
 * Zwraca:
 *    Roznica dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenie,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re*Skl2.re) - (Skl1.im*Skl2.im);
  Wynik.im = (Skl1.im*Skl2.re) + (Skl1.re*Skl2.im);
  return Wynik;
}

/*!
 * Realizuje wykonanie potegi drugiego stopnia na liczbie.
 * Argumenty:
 *    Liczba - potęgowana liczba.
 * Zwraca:
 *    Kwadrat podanej liczby.
 */

double Potegowanie(double Liczba)
{
double Wynik;
Wynik=Liczba*Liczba;
return Wynik;
}

/*!
 * Realizuje wykonanie modulu liczby zespolonej (Obliczenie jej dlugosci).
 * Argumenty:
 *    Skl1 - Liczba zespolona, ktorej modul ma zostac wyliczony.
 * Zwraca:
 *    Modul liczby zespolonej podanej jako parametr.
 */

double Modul(LZespolona Skl1)
{
double Wynik;
Wynik = sqrt(Potegowanie(Skl1.re) + Potegowanie(Skl1.im));
return Wynik;
}

/*!
 * Realizuje sprzerzenie liczby zespolonej
 * Argumenty:
 *    Skl1 - Liczba zespolona, na ktorej ma zostac wykonane sprzerzenie.
 * Zwraca:
 *    Sprzerzenie liczby zespolonej podanej jako parametr.
 */

LZespolona Sprzerzenie(LZespolona Skl1)
{
Skl1.im = -Skl1.im;
return Skl1;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenie,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 *!!!UWAGA:
 *     Jezeli modul drugiego skladnika jest rowny zeru, funkcja zwroci pierwszy skladnik dzielenia.
*/

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
LZespolona Wynik;
if(Modul(Skl2)==0)
    {
    cerr << "Blad: proba dzielenia przez zero." << endl;
    return Skl1;
    }
else
    {
    Wynik = Skl1 * Sprzerzenie(Skl2);
    Wynik.re = Wynik.re/Potegowanie(Modul(Skl2));
    Wynik.im = Wynik.im/Potegowanie(Modul(Skl2));
    return Wynik;
    }
}

/*!
 * Realizuje dzielenie liczby zespolonej przez skalar.
 * Argumenty:
 *    Skl1 - Liczba zespolona,
 *    Skl2 - skalr.
 * Zwraca:
 *    Wynik dzielenia liczby zespolonej przez skalar.
 *!!!UWAGA:
 *     Jezeli skalar jest rowny zeru funkcja zwroci dzielona liczbe zespolona.
*/

LZespolona operator / (LZespolona Skl1, double Liczba)
{
LZespolona Wynik;
if(Liczba == 0)
    {
    cerr << "Blad: proba dzielenia przez zero." << endl;
    return Skl1;
    }
else
    {
    Wynik.re = Skl1.re/Liczba;
    Wynik.im = Skl1.im/Liczba;
    return Wynik;
    }
}


/*!
 * Realizuje wyświetlenie liczby zespolonej.
 * Argumenty:
 *    Skl1 - Liczba zespolona, która ma zostać wyświetlona.
 *    StrmWy - Strumień, na który chcemy wyslać liczbe zespolona.
 * Zwraca:
 *    Strumień wyjściowy
 */

ostream& operator << (ostream& StrmWy, const LZespolona &Skl1)
{
return StrmWy << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i)";
}

/*!
 * Realizuje wczytywanie liczby zespolonej.
 * Argumenty:
 *    Skl1 - Liczba zespolona, która ma zostać wczytana.
 *    StrmWy - Strumień, z którego liczba będzie wczytana.
 * Zwraca:
 *    Strumień wyjściowy
 */

bool WczytajZnak(istream& StrmWej, char Znak)
{
char WczytanyZnak;
StrmWej >> WczytanyZnak;
if(StrmWej.fail())
    {return false;}
if(WczytanyZnak == Znak)
    {return true;}
else
    {return false;}
}

istream& operator >> (istream& StrmWej, LZespolona &Skl1)
{

if(!WczytajZnak(StrmWej, '('))            //Sprawdzenie czy znak jest nawiasem (jeżeli nie ustawiamy znacznik błędu)
    {
    StrmWej.setstate(ios::failbit);
    return StrmWej;
    }

StrmWej >> Skl1.re;                     //Wczytanie częsci rzeczywistej
if(StrmWej.fail())
    {return StrmWej;}

StrmWej >> Skl1.im;                     //Wczytanie częsci urojonej
if(StrmWej.fail())
    {return StrmWej;}

if(!WczytajZnak(StrmWej, 'i'))           //Sprawdzenie czy znak jest litera 'i' (jeżeli nie ustawiamy znacznik błędu)
    {
    StrmWej.setstate(ios::failbit);
    return StrmWej;
    }

if(!WczytajZnak(StrmWej, ')'))            //Sprawdzenie czy znak jest nawiasem (jeżeli nie ustawiamy znacznik błędu)
    {
    StrmWej.setstate(ios::failbit);
    return StrmWej;
    }

return StrmWej;
}

/*!
 * Realizuje porownanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik,
 *    Skl2 - drugi skladnik.
 * Zwraca:
 *    True, jeżeli liczby zespolone są takie same, lub False, jeżeli są różne.
 */

bool operator == (LZespolona Skl1, LZespolona Skl2)
{
if((abs(Skl1.re - Skl2.re) <= MIN_ROZNICA) && (abs(Skl1.im - Skl2.im) <= MIN_ROZNICA))
    {return true;}
else
    {return false;}
}
