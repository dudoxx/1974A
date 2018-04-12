#ifndef TEKRAN_H
#define TEKRAN_H
#include <string>
#include <iostream>
using namespace std;
class Tekran
{
    string tresc;
    char znak_tla;
public:
    enum {szerokosc_ekranu = 50, wysokosc_ekranu = 26};

    //Tekran() {};
    Tekran(char);
    void wyczysc();
    void wyswietl();
    void napisz(int kolumna, int rzad, string tekst);
};
#endif // TEKRAN_H
