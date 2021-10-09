#include "TXLib.h"

void Massiv (int data[], int size);
void Postroenie (int data[], int size);

int main ()
    {
    int data[32] = {};

    Massiv (data, 32);
    Postroenie (data, 32);

    return 0;
    }

void Massiv (int data[], int size)
    {
    $h; printf ("Zapolnenie massiva:");

    for (int i = 0; i < size; i++)
        {
        assert (0 <= i && i < size);
        data[i] = i+1;

        if (i % 6 == 0) printf ("\n");

        $h; printf ("[%2d] = ", i);
        $b; printf ("%2d ", data[i]);
        }
    printf ("\n");
    }

void Postroenie (int data[], int size)
    {
    printf ("\n");
    $h; printf ("Resultat vipolneniya programmy:");
    printf ("\n");

    int n = 2;

    for (int i = 0; i < size - size%3; i++)
        {
        $b;
        if (i <= n) printf ("%d ", data[i]);
        if (i > n)
            {
            n += 6;
            i += 2;
            }
        }

    if (size%6 != 0 && size%3 != 0) printf (".. ");

    n = size - size%6 - 3;

    for (int i = (size-1) - size%6; i >= 0; i--)
        {
        $h;
        if (i >= n) printf ("%d ", data[i]);
        if (i < n)
            {
            n -= 6;
            i -= 2;
            }
        }
    }
