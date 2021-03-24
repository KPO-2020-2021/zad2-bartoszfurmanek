#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Porownanie"){  //Rownosc 
    LZespolona x, y;

    x.re = 1;
    x.im = 2;

    y.re = 1;
    y.im = 2;

    
    CHECK(x==y);
}

TEST_CASE("test LZespolona Porownanie2"){  //Nierownosc
    LZespolona x, y;

    x.re = 1;
    x.im = 2;

    y.re = 2;
    y.im = 1;

    
    CHECK(!(x==y));
}

TEST_CASE("test LZespolona Porownanie3"){ //Minimalna nierwonosc
    LZespolona x, y;

    x.re = 1;
    x.im = 0.0003;

    y.re = 1;
    y.im = 0.0001;

    
    CHECK(!(x==y));
}

TEST_CASE("test LZespolona Porownanie4"){  //Nierownosc, ktora jest mniejsza niz minimalna roznica
    LZespolona x, y;

    x.re = 1;
    x.im = 0.00005;

    y.re = 1;
    y.im = 0.00002;

    
    CHECK(x==y);
}


TEST_CASE("test LZespolona Suma1"){    //Dodawnie liczb całkowitych
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma2"){    //Dodawnie liczb z wartosciami po przecinku
    LZespolona x, y, z;

    x.re = 1.27;
    x.im = 2.68;

    y.re = 4.23;
    y.im = -3.56;

    z.re = 5.5;
    z.im = -0.88;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma3"){    //Dodawnie liczb z wartości mniejszymi niż minimalna roznica
    LZespolona x, y, z;

    x.re = 0.00001;
    x.im = 0.00003;

    y.re = 0.00002;
    y.im = 0.00004;

    z.re = 0.00005;
    z.im = 0.00005;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Odjemowanie1"){    //Odjemowanie liczb całkowitych
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 0;
    z.im = 4;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona Odejmowanie2"){    //Odjemowanie liczb z wartosciami po przecinku
    LZespolona x, y, z;

    x.re = 1.27;
    x.im = 2.68;

    y.re = 4.23;
    y.im = -3.56;

    z.re = -2.96;
    z.im = 6.24;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona Odjemowanie3"){    //Odjemowanie liczb z wartości mniejszymi niż minimalna roznica
    LZespolona x, y, z;

    x.re = 0.00001;
    x.im = 0.00003;

    y.re = 0.00002;
    y.im = 0.00004;

    z.re = 0.00000;
    z.im = 0.00000;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona Mnozenie1"){  
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 4;
    z.im = -2;
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona Mnozenie2"){  
    LZespolona x, y, z;

    x.re = 0;
    x.im = 0;

    y.re = 1;
    y.im = -3;

    z.re = 0;
    z.im = 0;
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona Mnozenie3"){  
    LZespolona x, y, z;

    x.re = 1;
    x.im = 0;

    y.re = 1;
    y.im = -3;

    z.re = 1;
    z.im = -3;
    
    CHECK(x*y == z);
}

TEST_CASE("test LZespolona Mnozenie4"){  
    LZespolona x, y, z;

    x.re = 0;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 3;
    z.im = 1;
    
    CHECK(x*y == z);
}



