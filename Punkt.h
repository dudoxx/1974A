#ifndef PUNKT_H
#define PUNKT_H

class Punkt
{
    public:

    static int d_ptr[2];        // zmienna pomocnicza
    enum Kierunek {N, W, S , E};
    int x ;     // wsp�rzedna x
    int y ;     // wsp�lrzedna y

    Punkt();
    Punkt(int, int);
    Punkt(int xx, char dd);

};

#endif // PUNKT_H
