#include "Tekran.h"

// konstruktor
    Tekran::Tekran(char znak = '*')
    {
        znak_tla = znak;
        wyczysc();
    }

void Tekran::wyczysc()
{

    int ile_znakow = wysokosc_ekranu * szerokosc_ekranu;
    tresc.assign(ile_znakow,znak_tla);

    for(int i = 0 ; i < wysokosc_ekranu; i++)
    {
        tresc[(i+1)*szerokosc_ekranu-1] = '\n';
    }
}

//----------
void Tekran::wyswietl()
{
    cout<<'\n';
    cout << tresc << flush;
}
//-----------
void Tekran::napisz (int kolumna, int rzad, string tekst)
{
    tresc.replace( (szerokosc_ekranu*rzad) + kolumna, tekst.length(), tekst);
}

