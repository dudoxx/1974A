#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include "Punkt.h"
#include "Tekran.h"
#include <iomanip>
#include <fstream>


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
    ofstream plik("zapisnowy.txt");
  /*  if(plik.good())
        cout<<"Otwarty";
    else
        cout<<"Nie otwarty";*/
    dane << "24 7 n 4 w 2 n 6 w 2 n 2 w 8 n 2 e 2 n 4 e 2 n 16 e 2s 4 e 2 s 2 e 8 s 2 w 2 s 6 w 2 s 4 w 7 s 4 w";
    //dane << "12 10 n 3 e 5 s 3 e 5 n 3 e 5 s 2 e 5 n 7 e 10 s 18 w"; //dane wejœciowe w strumieniu string
    //dane << "6 5 n 5 e 2 s 5 e 3 s 10 w";
    //dane << "4 5 n 4 e 5 s 4 w";


    int a;
    char k;
    int n = 0;
    dane >> n;
    Punkt Punkty[n];
    Punkt tmp;
    Punkty[0].x = Punkty[0].y = 0;    // Inicjalizacja pierwszego punktu (0,0)

    for(int i = 1 ; i < n; i++)
    {
        dane>>a>>k;     // a = wymiar k = kierunek
        k = toupper(k);
        Punkty[i] = Punkt(a,k);
    }

    Tekran ekran('.');
  /*  ekran.napisz(3,3,"Dudo");
    ekran.wyswietl();
    getchar();
    ekran.napisz(3,4,"DudoSUUUU");
    ekran.wyswietl();
    getchar();
    ekran.napisz(3,5,"ELELELELE");
    ekran.wyswietl();
*/

    Punkt srodek(21,24);    // miejsce od którego rysujemy czyli środek układu współrzędnych
    int licznikX = 0, licznikY = 0;
    for(int i = 0; i < n ; i ++)
    {
        if( Punkty[i].x == Punkty[(i+1)%n].x)
        {
            licznikY++;
            int dlugosc = (Punkty[(i+1)%n].y) - (Punkty[i].y);
            if(dlugosc > 0)
                for(int j = 0; j <= abs(dlugosc); j++)
                {
                    ekran.napisz(srodek.x,srodek.y-j,"#");
                   // ekran.wyswietl();

                    if(j == dlugosc)
                        srodek.y = srodek.y-j;
                }
            else
                for(int j = 0; j <= abs(dlugosc); j++)
                {
                    ekran.napisz(srodek.x,srodek.y+j,"#");
                   // ekran.wyswietl();

                    if(j == abs(dlugosc))
                        srodek.y = (srodek.y)+j;
                }

        }
        else if( Punkty[i].y == Punkty[(i+1)%n].y)
        {
            licznikX++;
            int dlugosc = (Punkty[(i+1)%n].x) - (Punkty[i].x);
            if(dlugosc > 0)
                for(int j = 0; j <=abs(dlugosc); j++)
                {
                    ekran.napisz(srodek.x+j,srodek.y,"#");
                  //  ekran.wyswietl();

                    if(j == dlugosc)
                        srodek.x = srodek.x+j;
                }
            else
                for(int j = 0; j <=abs(dlugosc); j++)
                {
                    ekran.napisz(srodek.x-j,srodek.y,"#");
                  //  ekran.wyswietl();

                    if(j == abs(dlugosc))
                        srodek.x = srodek.x-j;
                }
        }

    }

    plik<<ekran.wyswietl();
    //LiczPole(Punkty,n);
   // plik  ekran.wyswietl();



    return 0;
}
