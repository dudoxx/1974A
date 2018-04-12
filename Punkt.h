#ifndef PUNKT_H
#define PUNKT_H

class Punkt
{
    public:

    static int d_ptr[2];        // zmienna pomocnicza
    enum Kierunek {N, W, S , E};
    int x ;     // wspó³rzedna x
    int y ;     // wspólrzedna y

    Punkt();
    Punkt(int, int);
    Punkt(int xx, char dd);

};

#endif // PUNKT_H
