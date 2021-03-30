#include "LZespolona.hh"
#include <iostream>
#include <math.h>

#define MIN_ROZNICA 0.0001

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (LZespolona  Z)const
{
  LZespolona Wynik;
  Wynik.re = this->re + Z.re;
  Wynik.im = this->im + Z.im;
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

LZespolona  LZespolona::operator - (LZespolona  Z)const
{
  LZespolona Wynik;
  Wynik.re = this->re - Z.re;
  Wynik.im = this->im - Z.im;
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

LZespolona  LZespolona::operator * (LZespolona  Z)const
{
  LZespolona  Wynik;

  Wynik.re = (this->re*Z.re) - (this->im*Z.im);
  Wynik.im = (this->im*Z.re) + (this->re*Z.im);
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

double LZespolona::Modul()
{
double Wynik;
Wynik = sqrt(Potegowanie(this->re) + Potegowanie(this->im));
return Wynik;
}

/*!
 * Realizuje sprzerzenie liczby zespolonej
 * Argumenty:
 *    Skl1 - Liczba zespolona, na ktorej ma zostac wykonane sprzerzenie.
 * Zwraca:
 *    Sprzerzenie liczby zespolonej podanej jako parametr.
 */

LZespolona LZespolona::Sprzerzenie()
{
LZespolona Wynik;
Wynik.im= -this->im;
Wynik.re= this->re;
return Wynik;
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

LZespolona LZespolona::operator / (LZespolona Z)const
{
LZespolona Wynik;
Wynik = (*this * Z.Sprzerzenie())/Potegowanie(Z.Modul());
return Wynik;
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

LZespolona LZespolona::operator / (double Liczba)const
{
LZespolona Wynik;
if(Liczba == 0)
    {
    throw runtime_error("Próba dzielenia przez zero");
    }
else
    {
    Wynik.re = this->re/Liczba;
    Wynik.im = this->im/Liczba;
    return Wynik;
    }
}

/*!
 * Realizuje porownanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik,
 *    Skl2 - drugi skladnik.
 * Zwraca:
 *    True, jeżeli liczby zespolone są takie same, lub False, jeżeli są różne.
 */


bool LZespolona::operator == (LZespolona Z)const
{
if((abs(this->re - Z.re) <= MIN_ROZNICA) && (abs(this->im - Z.im) <= MIN_ROZNICA))
    {return true;}
else
    {return false;}
}



/*!
 * Realizuje wyświetlenie liczby zespolonej.
 * Argumenty:
 *    Skl1 - Liczba zespolona, która ma zostać wyświetlona.
 *    StrmWy - Strumień, na który chcemy wyslać liczbe zespolona.
 * Zwraca:
 *    Strumień wyjściowy
 */

ostream& operator << (ostream &StrmWyj, LZespolona Z)
{
return StrmWyj << "(" <<Z.re << showpos << Z.im << noshowpos << "i)";
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

istream& operator >> (istream &StrmWej, LZespolona &Z)
{

if(!WczytajZnak(StrmWej, '('))            //Sprawdzenie czy znak jest nawiasem (jeżeli nie ustawiamy znacznik błędu)
    {
    StrmWej.setstate(ios::failbit);
    return StrmWej;
    }

StrmWej >> Z.re;                     //Wczytanie częsci rzeczywistej
if(StrmWej.fail())
    {return StrmWej;}

StrmWej >> Z.im;                     //Wczytanie częsci urojonej
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



