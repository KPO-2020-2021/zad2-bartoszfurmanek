#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Statystyki.hh"

TEST_CASE("Test Statystyki czyszczenie wynikow1") {
    Statystyka Stat;
    int Wynik=0;
    
    Stat.popr=3;
    Stat.blad=2;
    Stat.Clear();
    
    if((Stat.popr==0)&&(Stat.blad==0))
    {Wynik=1;}
    
    CHECK(Wynik==1);
}

TEST_CASE("Test Statystyki poprawna odpowiedz") {
    Statystyka Stat;
    int Wynik=0;
    
    Stat.popr=0;
    Stat.blad=0;

    Stat.PoprawnaOdpowiedz();
    
    if((Stat.popr==1)&&(Stat.blad==0))
    {Wynik=1;}
    
    CHECK(Wynik==1);
}

TEST_CASE("Test Statystyki bledna odpowiedz") {
    Statystyka Stat;
    int Wynik=0;
    
    Stat.popr=0;
    Stat.blad=0;

    Stat.BlednaOdpowiedz();
    
    if((Stat.popr==0)&&(Stat.blad==1))
    {Wynik=1;}
    
    CHECK(Wynik==1);
}


TEST_CASE("Test Statystyki kilka odpowiedzi") {
    Statystyka Stat;
    int Wynik=0;
    
    Stat.popr=0;
    Stat.blad=0;

    Stat.PoprawnaOdpowiedz();
    Stat.PoprawnaOdpowiedz();
    Stat.PoprawnaOdpowiedz();
    Stat.BlednaOdpowiedz();
    Stat.BlednaOdpowiedz();
    Stat.PoprawnaOdpowiedz();
    Stat.BlednaOdpowiedz();
    Stat.BlednaOdpowiedz();
    
    if((Stat.popr==4)&&(Stat.blad==4))
    {Wynik=1;}
    
    CHECK(Wynik==1);
}


TEST_CASE("Test Statystyki kilka odpowiedzi") {
    Statystyka Stat;
    
    Stat.popr=0;
    Stat.blad=0;

    Stat.PoprawnaOdpowiedz();
    Stat.PoprawnaOdpowiedz();
    Stat.PoprawnaOdpowiedz();
    Stat.BlednaOdpowiedz();
    Stat.BlednaOdpowiedz();
    Stat.PoprawnaOdpowiedz();
    Stat.BlednaOdpowiedz();
    Stat.BlednaOdpowiedz();
    Stat.PoprawnaOdpowiedz();
    Stat.PoprawnaOdpowiedz();
    
    
    CHECK(Stat.ProcentPoprawnych()==60);
}
