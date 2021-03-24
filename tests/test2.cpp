#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(!(x/t == y));
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona dzielenie przez liczbe zespolona") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    
   
    WARN_THROWS(x/y);
}

TEST_CASE("Test LZespolona dzielenie przez liczbe zespolona1") {
    LZespolona x, y, z;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = -1;

    z.re = 0;
    z.im = 2;
   
    CHECK(x/y == z);
}

TEST_CASE("Test LZespolona dzielenie przez liczbe zespolona2") {
    LZespolona x, y, z;
    
    x.re = 4;
    x.im = -2;

    y.re = 1;
    y.im = 2;

    z.re = 0;
    z.im = -2;
   
    CHECK(x/y == z);
}

TEST_CASE("Test LZespolona sprzerzenia 1") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = -2;

   
    CHECK(Sprzerzenie(x)==y);
}

TEST_CASE("Test LZespolona sprzerzenia 2") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 0;

    y.re = 2;
    y.im = 0;

   
    CHECK(Sprzerzenie(x)==y);
}

TEST_CASE("Test LZespolona sprzerzenia 3") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = -2;

    y.re = 2;
    y.im = 2;

   
    CHECK(Sprzerzenie(x)==y);
}

TEST_CASE("Test LZespolona Modul") {
    LZespolona x;
    double y;
    
    x.re = 1;
    x.im = 2;

    y = sqrt(5);

   
    CHECK(y==Modul(x));
}


