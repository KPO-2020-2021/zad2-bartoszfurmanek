#include "WyrazenieZesp.hh"
#include <iostream>

using namespace std;

/*!
 * Realizuje wyswietlenie wyrazenie zespolonego skladajacego sie z dwoch liczb zespolonych.
 * Argumenty:
 *    WyrZ - Wyrazenie zespolone, ktore ma zostac wyswietlone,
 *    StrmWyj - Strumień na którym wyrażenie ma zostać wyświetlone.
 * Zwraca:
 *    Strumień wyjsciowy.
 */

ostream& operator << (ostream& StrmWyj, WyrazenieZesp& WyrZ)
{
LZespolona Skl1, Skl2;      //Liczby zespolone wyrażenia
Skl1.re=WyrZ.Arg1.re;       //Wczytanie liczb zespolonych
Skl1.im=WyrZ.Arg1.im;
Skl2.re=WyrZ.Arg2.re;
Skl2.im=WyrZ.Arg2.im;

cout << Skl1;               //Wyświetlenie pierwszej liczby zespolonej wyrażenia

switch(WyrZ.Op)             //Wyświetlenie odpowiedniego operator
    {
        case Op_Dodaj:
            cout<<" + ";
            break;
        case Op_Odejmij:
            cout<<" - ";
            break;
        case Op_Mnoz:
            cout<<" * ";
            break;
        case Op_Dziel:
            cout<<" / ";
            break;
    }

cout << Skl2;             //Wyświetlenie drugiej liczby zespolonej wyrażenia

return StrmWyj;
}

/*!
 * Oblicza wyrazenia zespolone.
 * Argumenty:
 *    Wyrz - Wyrazenie zespolone, ktore ma zostac obliczone.
 * Zwraca:
 *    Wynik obliczenia wyrazenia zespolonego.
 */

LZespolona WyrazenieZesp::Oblicz()
{
LZespolona Skl1, Skl2, Wynik;       //Utworzenie liczb zespolonych argumentow oraz wyniku
Skl1.re=this->Arg1.re;
Skl1.im=this->Arg1.im;
Skl2.re=this->Arg2.re;
Skl2.im=this->Arg2.im;

switch(this->Op)                     //Wybor operacji
{
    case Op_Dodaj:
        Wynik=Skl1+Skl2;            //Realizacja dodawania
        break;
    case Op_Odejmij:
        Wynik=Skl1-Skl2;            //Realizacja odejmowania
        break;
    case Op_Mnoz:
        Wynik=Skl1*Skl2;            //Realizacja mnozenie
        break;
    case Op_Dziel:
        Wynik=Skl1/Skl2;         //Realizacja dzielenia
        break;
}
return Wynik;
}

/*!
 * Realizuje wczyatnie wyrazenie zespolonego skladajacego sie z dwoch liczb zespolonych.
 * Argumenty:
 *    WyrZ - Wyrazenie zespolone, ktore ma zostac wczytane,
 *    StrmWyj - Strumień z którego dane maja zostać wczytane.
 * Zwraca:
 *    Strumień wejsciowy.
 */



istream& operator >> (istream& StrmWej, WyrazenieZesp& WyrZ)
{
char Operator;

StrmWej >> WyrZ.Arg1;                   //Wczytanie pierwszej liczby zespolonej
if(StrmWej.fail())
    {
    StrmWej.setstate(ios::failbit);     //Ustawienie znacznika błędu w przypadku błędu zapisu liczby zespolonej
    return StrmWej;
    }

StrmWej >> Operator;                    //Pobranie operatora wyrażenia
if(StrmWej.fail())
    {
    return StrmWej;
    }

switch(Operator)                        //Określenie operatora wyrażenia i zapisanie
    {
    case '+':
        WyrZ.Op = Op_Dodaj;
        break;
    case '-':
        WyrZ.Op = Op_Odejmij;
        break;
    case '*':
        WyrZ.Op = Op_Mnoz;
        break;
    case '/':
        WyrZ.Op = Op_Dziel;
        break;
    default:
        StrmWej.setstate(ios::failbit); //Ustawienie znacznika błędu w przypadku nieznanego operatora
        throw runtime_error("Nieznany operator");
    }

StrmWej >> WyrZ.Arg2;                   //Wczytanie drugiej liczby zespolonej
if(StrmWej.fail())
    {
    StrmWej.setstate(ios::failbit);     //Ustawienie znacznika błędu w przypadku błędu wczytania liczby zespolonej
    return StrmWej;
    }

return StrmWej;
}

