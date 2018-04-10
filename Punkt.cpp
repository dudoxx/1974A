#include "Punkt.h"

Punkt::Punkt() {}

Punkt::Punkt(int xx, char dd)
{
    x = d_ptr[0];
    y = d_ptr[1];

    switch (dd)
        {
            case 'N':
                x += 0;
                y += xx;
                break;
            case 'W':
                x -= xx;
                y += 0;
                break;
            case 'S':
                x += 0;
                y -= xx;
                break;
            case 'E':
                x += xx;
                y += 0;
                break;
        }
    d_ptr[0] = x;
    d_ptr[1] = y;
};
