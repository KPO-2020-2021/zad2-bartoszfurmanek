#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "Statystyki.hh"


using namespace std;




int main(int argc, char **argv)
{

LZespolona Odpowiedz;
Statystyka Stat;
int LiczbaProb;

Stat.Clear();

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) 
    {
    cout <<"Podaj wynik operacji: " << WyrZ_PytanieTestowe << " =" << endl;
    LiczbaProb=3;
    while(LiczbaProb>0)
        {
        cout << "Twoja odpowiedz: ";
        cin >> Odpowiedz;
        if(cin.fail())
            {
            LiczbaProb--;
            if(LiczbaProb == 0)
                {
                Stat.BlednaOdpowiedz();
                cout << "Blad. Prawidlowym wynikiem jest: " << WyrZ_PytanieTestowe.Oblicz() << endl << endl;
                }
            else
                {cout << endl << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz"<< endl << endl;}
            cin.ignore(10000, '\n');
            cin.clear();
            }
        else
            {
            LiczbaProb=0;
            if(Odpowiedz == (WyrZ_PytanieTestowe.Oblicz()))
                {
                Stat.PoprawnaOdpowiedz();
                cout << "Odpowiedz poprawna" << endl << endl;
                }
            else
                {
                Stat.BlednaOdpowiedz();
                cout << "Blad. Prawidlowym wynikiem jest: " << WyrZ_PytanieTestowe.Oblicz() << endl << endl;
                }
            }
        cin.ignore(10000, '\n');
        cin.clear();
        }
    }



  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  Stat.Wyswietl();
  cout << endl;

}
