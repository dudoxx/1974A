#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include "Punkt.h"
#include <iomanip>


using namespace std;



void LiczPole(Punkt *m, int ile)       // funkcja obliczaj¹ca Pole
{
    double * dlugosc = new double[ile]; // alokacja tablicy

    for(int i = 0; i < ile; i++)
        cout<<"Punkt nr "<<right<<setw(3)<< i <<" wynosi: "<<setw(3)<<m[i].x<<", "<<m[i].y<<"\n";
    cout<<"-----------\n";
    for(int i = 0; i <ile;i++)
    {

        dlugosc[i] = sqrt( pow( (m[i].x-m[(i+1)%ile].x),2 ) + pow( (m[i].y-m[(i+1)%ile].y),2 ) );
        cout<<"Dlugosc boku nr "<<right<<setw(2)<< i+1 <<" wynosi "<< dlugosc[i]<<endl;
    }

    int  P = 0;

    P += (m[0].x) * ( (m[1].y) - m[ile-1].y );
    P+= (m[ile-1].x) * ( (m[0].y) - (m[ile-2].y) );
    for(int i = 1; i < ile-1; i++)
    {
        P+=( (m[i].x) * ( (m[i+1].y) - (m[i-1].y) ));
    }
    cout<<"-----------";
    P < 0 ? P=-P : P=P;
    cout<<"\n\nNowe pole wynosi: "<<P/2.0;
}
int  Punkt::d_ptr[2] = {0,0};
//--------------------------------------------------------------------------------------------------


stringstream dane;

int main()
{
    dane << "12 10 n 3 e 5 s 3 e 5 n 3 e 5 s 2 e 5 n 2 e 11 s 13 w"; //dane wejœciowe w strumieniu string
    //dane << "6 5 n 5 e 2 s 5 e 3 s 10 w";
    //dane << "4 5 n 4 e 5 s 4 w";

    Punkt Punkty[13];

    Punkty[0].x = Punkty[0].y = 0;    // Inicjalizacja pierwszego punktu (0,0)

    int a;
    char k;
    int n = 0;
    dane >> n;

    for(int i = 1 ; i < n; i++)
    {
        dane>>a>>k;     // a = wymiar k = kierunek
        k = toupper(k);
        Punkty[i] = Punkt(a,k);
    }

    LiczPole(Punkty,n);


    return 0;
}
