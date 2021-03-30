#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"

TEST_CASE("Test WyrazenieZesp obliczanie wyrazenia 1") {  //Dodawnie liczb zespolonych
    LZespolona x, y;
    WyrazenieZesp z;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;


    z.Arg1.re = 2;
    z.Arg1.im = 2;
    z.Op = Op_Dodaj;
    z.Arg2.re = 1;
    z.Arg2.im = 1;
   
    CHECK(z.Oblicz() == x + y);
}

TEST_CASE("Test WyrazenieZesp obliczanie wyrazenia 2") {  //Odejmowanie liczb zespolonych
    LZespolona x, y;
    WyrazenieZesp z;
    
    x.re = 2;
    x.im = 3;

    y.re = 1;
    y.im = 4;


    z.Arg1.re = 2;
    z.Arg1.im = 3;
    z.Op = Op_Odejmij;
    z.Arg2.re = 1;
    z.Arg2.im = 4;
   
    CHECK(z.Oblicz() == x - y);
}

TEST_CASE("Test WyrazenieZesp obliczanie wyrazenia 3") {  //Mnozenie liczb zespolonych
    LZespolona x, y;
    WyrazenieZesp z;
    
    x.re = 2;
    x.im = -2;

    y.re = 3;
    y.im = -5;


    z.Arg1.re = 2;
    z.Arg1.im = -2;
    z.Op = Op_Mnoz;
    z.Arg2.re = 3;
    z.Arg2.im = -5;
   
    CHECK(z.Oblicz() == x * y);
}

TEST_CASE("Test WyrazenieZesp obliczanie wyrazenia 4") {  //Dziel liczb zespolonych
    LZespolona x, y;
    WyrazenieZesp z;
    
    x.re = 16;
    x.im = 4;

    y.re = 2;
    y.im = 1;

    z.Arg1.re = 16;
    z.Arg1.im = 4;
    z.Op = Op_Dziel;
    z.Arg2.re = 2;
    z.Arg2.im = 1;
    

    CHECK(z.Oblicz() == x / y);
}
/*
TEST_CASE("Test WyrazenieZesp wyswietlanie") {
    WyrazenieZesp z;

    z.Arg1.re = 2;
    z.Arg1.im = 1;
    z.Op = Op_Dodaj;
    z.Arg2.re = 1;
    z.Arg2.im = 2;


    std::ostringstream out;

    out << z;

    
    CHECK("(2+1i) + (1+2i)" == out.str());


}


TEST_CASE("Test WyraznieZesp Wczytywanie") {  
    WyrazenieZesp z;

    std::ostringstream out;
    std::istringstream in("(2+1i) + (1+2i)");
    in >> z;
    out << z;
    
    CHECK("(2+1i) + (1+2i)" == out.str());


}
*/

TEST_CASE("Test LZespolona Wczytywanie") { //Bledny operator
    WyrazenieZesp z;
    
    std::istringstream in("(7+4i) % (3+1i)");
    
    WARN_THROWS(in >> z);


}

