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

public:

LZespolona  operator + (LZespolona  Z)const;

LZespolona  operator - (LZespolona  Z)const;

LZespolona  operator * (LZespolona  Z)const;

double Modul();

LZespolona Sprzerzenie();

LZespolona operator / (LZespolona  Z)const;

bool operator == ( LZespolona Z)const;

LZespolona operator / (double Liczba)const;

double Arg()const;

LZespolona operator += (const LZespolona Z);

LZespolona operator /= (LZespolona Z);

friend ostream& operator << (ostream &StrmWyj, LZespolona Z);

friend istream& operator >> (istream &StrmWej, LZespolona &Z);
};
#endif
