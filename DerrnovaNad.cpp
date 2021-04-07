#include "TXLib.h"

void StartTitles();
void DrawSceneNight();
void DrawHouse (int x, int y);

void DrawRoundRocket (int x, int y,
                      double sizeX, double sizeY,
                      COLORREF hullColor     = TX_PINK,
                      COLORREF portholeColor = TX_YELLOW);

void DrawRoundAlien (int x, int y,
                     int crazy,
                     int legs,
                     int rHandUp,
                     double sizeX, double sizeY,
                     COLORREF headColor = TX_BLUE,
                     COLORREF eyesColor = TX_YELLOW);

int main()
    {
    txCreateWindow (1200, 900);
    txBegin();

    StartTitles();
    DrawSceneNight();
    DrawRoundRocket ( 300, 500, 1, 1         );
    DrawRoundAlien  ( 500, 300, 1, 1, 1, 1, 1);

    txEnd();
    return 0;
    }

void DrawSceneNight()
    {
    txSetFillColor (TX_LIGHTBLUE);
    POINT  nebo[] = {txRectangle (0,   0, 1200, 400)};
    txPolygon      (nebo, 3);
    txSetFillColor (TX_GREEN);
    POINT trava[] = {txRectangle (0, 400, 1200, 900)};
    txPolygon      (trava, 3);
    }

    void DrawRoundAlien (int x, int y,
                     int crazy,
                     int legs,
                     int rHandUp,
                     double sizeX, double sizeY,
                     COLORREF headColor,
                     COLORREF eyesColor)
    {
    txSetFillColor (headColor);
    txEllipse      (x,      y,                   x + 60*sizeX, y +  30*sizeY);
    txEllipse      (x + 10*sizeX, y +  30*sizeY, x + 50*sizeX, y + 110*sizeY);

    txSetFillColor (eyesColor);
    txEllipse      (x + 10*sizeX, (y +   5 - crazy) * sizeY, x + 20*sizeX, y + 15*sizeY);
    txEllipse      (x + 40*sizeX, (y +   5 + crazy) * sizeY, x + 50*sizeX, y + 15*sizeY);

    txSetFillColor (TX_BLUE);
    txEllipse      (x - 20*sizeX, (y +  40 + rHandUp) * sizeY, x + 10*sizeX, y + 60*sizeY);
    txEllipse      (x + 50*sizeX, (y +  40 - rHandUp)*sizeY, x + 80*sizeX, y + 60*sizeY);

    txSetFillColor (TX_RED);
    txEllipse      (x + (10 + legs/2) * sizeX, y + 100*sizeY, x + 20*sizeX, y + 120*sizeY);
    txEllipse      (x + (40 - legs/2) * sizeX, y + 100*sizeY, x + 50*sizeX, y + 120*sizeY);
    }

void DrawRoundRocket (int x, int y, double sizeX, double sizeY,
                      COLORREF hullColor, COLORREF portholeColor)
    {
    txSetColor     (TX_BLACK, 3);
    txSetFillColor (hullColor);
    txEllipse      (x,            y,             x + 80*sizeX, y + 150*sizeY);
    txSetColor     (TX_BLACK, 3);
    txSetFillColor (portholeColor);
    txEllipse      (x + 30*sizeX, y +  40*sizeY, x + 50*sizeX, y +  80*sizeY);
    txSetFillColor (TX_GREEN);
    txEllipse      (x,            y + 130*sizeY, x + 20*sizeX, y + 170*sizeY);
    txSetColor     (TX_BLACK, 3);
    txEllipse      (x + 30*sizeX, y + 130*sizeY, x + 50*sizeX, y + 170*sizeY);
    txSetColor     (TX_BLACK, 3);
    txEllipse      (x + 60*sizeX, y + 130*sizeY, x + 80*sizeX, y + 170*sizeY);
    }

void StartTitles()
    {
    int t = 0;

    while (t <= 450)
        {
        txClear();
        txSetFillColor (TX_WHITE);
        txRectangle    (0,   0, 1200, 900);
        txSetColor     (TX_RED);
        txSelectFont   ("Arial", 200);
        txTextOut      (500 + t * 10, 100, "Война миров");
        txSleep        (100);
        t++;
        }
     }
