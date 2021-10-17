#include "TXLib.h"

void FillArray (int data[], int size);
void Result (int data[], int size);

int main ()
    {
    int data[20] = {};

    FillArray (data, 20);
    Result (data, 20);

    return 0;
    }

void FillArray (int data[], int size)
    {
    $h; printf ("First part of Array:");

    int triplets = size / 3;
    if (triplets % 2 != 0) triplets ++;

    int polovina = triplets / 2 * 3;
    if (size % 6 <= 3 && size % 3 != 0) polovina = triplets / 2 * 3 + size % 6;

    int n = 1;

    for (int i = 0; i <= polovina - 1; i ++)
        {
        assert (0 <= i && i < size);
        if (i % 6 == 0) printf ("\n");

        data[i] = i + n;
        if ((i + 1) % 3 == 0) n += 3;

        $h; printf ("[%2d] = ", i);
        $b; printf ("%2d ", data[i]);
        }

    printf ("\n");
    printf ("\n");
    $h; printf ("Second part of Array:");

    n = size;

    if (size % 6 <= 3 && size % 3 != 0) n = size - size % 6;
    if (size % 6 != 0 && size % 3 == 0) n = size - 3;

    for (int i = polovina; i < size; i ++)
        {
        assert (0 <= i && i < size);
        if ((i - polovina) % 6 == 0) printf ("\n");

        data[i] = n;
        n --;

        if (n % 3 == 0) n -= 3;

        $h; printf ("[%2d] = ", i);
        $b; printf ("%2d ", data[i]);
        }

    printf ("\n");
    }

void Result (int data[], int size)
    {
    printf ("\n");
    $h; printf ("Result:");
    printf ("\n");

    for (int i = 0; i < size; i++)
        {
        $b;
        printf ("%d ", data[i]);
        }
    }
