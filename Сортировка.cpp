#include "TXLib.h"
#include <iostream>

const int WidthWindow  = 1200,
          HeightWindow =  700;
const HDC Knopki = txLoadImage ("Knopki.bmp");

void FillArray (int data [], int size, int max);
void SortingArray (int data [], int  size);
void OutputArray (int data [], int size);
void DrawGraph (int data [], int Width, int Height, int size, int max, COLORREF color, int font);
void MenuButtons (int data [], int size, int max, int Width, int Height, double CenterX,
                  double CenterY, double ButtonsX, double ButtonsY, double MinXArray,
                  double MaxXArray, double MinXGraph, double MaxXGraph, double MinXSorting,
                  double MaxXSorting, double MinXClean, double MaxXClean, double MinYKnopki,
                  double MaxYKnopki);
void Menu (int data [], int size, int max);

int main ()
    {
    txCreateWindow (WidthWindow, HeightWindow);
    int data [15] = {};
    int size = 15;
    int max = 50;
    Menu (data, size, max);

    txDeleteDC (Knopki);
    }

void FillArray (int data [], int size, int max)
    {
    for (int i = 0; i < size; i++)
        {
        assert (0 <= i && i < size);
        data [i] = rand () % max;
        }
    }

void SortingArray (int data [], int  size)
    {
    for (int i = 0; i < size; i++)
        {
        for (int g = i + 1; g < size; g++)
            {
            if (data [i] > data [g])
                {
                int chislo = data [i];
                data [i] = data [g];
                data [g] = chislo;
                }
            }
        }
    }

void OutputArray (int data [], int size)
    {
    for (int i = 0; i < size; i++)
        {
        if (i % 10 == 0) printf ("\n");

        $B; printf ("[%2d] = ", i);
        $b; printf ("%2d ", data[i]);
        }
    printf ("\n");
    }

void DrawGraph (int data [], int Width, int Height, int size, int max, COLORREF color, int font)
    {
    int x = 100;
    int y = HeightWindow - 200;
    int delX = (Width  - 400) / size;
    int delY = (Height - 400) / max;

    txSetColor (color, font);
    txLine (x, y, x + delX, y - data [0] * delY);

    for (int i = 1; i < size; i++)
        {
        txSetColor (color, font);
        txLine (x + i * delX, y - data [i-1] * delY, x + (i + 1) * delX, y - data [i] * delY);
        }
    }

void MenuButtons (int data [], int size, int max, int Width, int Height, double CenterX, double CenterY,
                  double ButtonsX, double ButtonsY, double MinXArray, double MaxXArray, double MinXGraph,
                  double MaxXGraph, double MinXSorting, double MaxXSorting, double MinXClean,
                  double MaxXClean, double MinYKnopki, double MaxYKnopki)
    {
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txRectangle (0, 0, Width, Height);

    txSetColor (TX_BLACK, 5);
    txLine (100, Height - 100, 100, 100);
    txLine (100, Height - 100, Width - 100, Height - 100);

    txBegin ();
    while (! txGetAsyncKeyState (VK_ESCAPE))
        {
        txClear ();
        txBitBlt (txDC (), MinXArray, 600, 0, 70, Knopki, 0, 0);

        if (MinXArray <= txMouseX () && txMouseX () <= MaxXArray &&
            MinYKnopki <= txMouseY () && txMouseY () <= MaxYKnopki - ButtonsY)
            {
            txTransparentBlt (txDC (), MinXArray, 600, ButtonsX, ButtonsY,
                              Knopki, 0, ButtonsY, RGB (250, 249, 244));
            if (txMouseButtons () == 1)
                {
                system("cls");

                printf ("\n");
                $B; printf ("Исходный массив:");
                printf ("\n");
                FillArray (data, size, max);
                OutputArray (data, size);
                }
            }

        if (MinXSorting <= txMouseX () && txMouseX () <= MaxXSorting &&
            MinYKnopki <= txMouseY () && txMouseY () <= MaxYKnopki - ButtonsY)
            {
            txTransparentBlt (txDC (), MinXSorting, 600, ButtonsX, ButtonsY,
                              Knopki, MinXArray, ButtonsY, RGB (250, 249, 244));
            if (txMouseButtons () == 1)
                {
                system("cls");

                printf ("\n");
                $B; printf ("Отсортированный массив:");
                printf ("\n");
                SortingArray (data, size);
                OutputArray (data, size);
                }
            }

        if (MinXGraph <= txMouseX () && txMouseX () <= MaxXGraph &&
            MinYKnopki <= txMouseY () && txMouseY () <= MaxYKnopki - ButtonsY)
            {
            txTransparentBlt (txDC (), MinXGraph, 600, ButtonsX, ButtonsY,
                              Knopki, MinXSorting, ButtonsY, RGB (250, 249, 244));
            if (txMouseButtons () == 1)
                {
                system("cls");

                while (txMouseButtons () == 0)
                    {
                    DrawGraph (data, WidthWindow, HeightWindow, size, max, TX_GREEN, 4);
                    txSleep (1);
                    }
                }
            }

        if (MinXClean <= txMouseX () && txMouseX () <= MaxXClean &&
            MinYKnopki <= txMouseY () && txMouseY () <= MaxYKnopki - ButtonsY)
            {
            txTransparentBlt (txDC (), MinXClean, 600, ButtonsX, ButtonsY,
                              Knopki, MinXGraph, ButtonsY, RGB (250, 249, 244));
            if (txMouseButtons () == 1)
                {
                system("cls");
                }
            }
        txSleep (1);
        }
    txEnd ();
    }

void Menu (int data [], int size, int max)
    {
    double CenterX = WidthWindow / 2,
           CenterY = HeightWindow / 2;

    double ButtonsX = txGetExtentX (Knopki) / 4,
           ButtonsY = txGetExtentY (Knopki) / 2;

    double MinXArray    = CenterX - ButtonsX * 2,
           MaxXArray    = CenterX - ButtonsX,
           MinXSorting  = CenterX - ButtonsX,
           MaxXSorting  = CenterX,
           MinXGraph    = CenterX,
           MaxXGraph    = CenterX + ButtonsX,
           MinXClean    = CenterX + ButtonsX,
           MaxXClean    = CenterX + ButtonsX * 2;

    double MinYKnopki  = 600,
           MaxYKnopki  = 740;

    MenuButtons (data, size, max, WidthWindow, HeightWindow, CenterX, CenterY, ButtonsX, ButtonsY, MinXArray, MaxXArray, MinXGraph,
                MaxXGraph, MinXSorting, MaxXSorting, MinXClean, MaxXClean, MinYKnopki, MaxYKnopki);

    txDeleteDC (Knopki);
    }
