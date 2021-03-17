#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

double Potegowanie(double Liczba);

double Modul(LZespolona Skl1);

LZespolona Sprzerzenie(LZespolona Skl1);

LZespolona operator / (LZespolona Skl1, LZespolona Skl2);

ostream& operator << (ostream& StrmWy, const LZespolona &Skl1);

istream& operator >> (istream& StrmWej, LZespolona &Skl1);

bool operator == (LZespolona Skl1, LZespolona Skl2);

bool WczytajZnak(istream& StrmWej, char Znak);

LZespolona operator / (LZespolona Skl1, double Liczba);


#endif
