#include<stdio.h>
#include<wchar.h>
#include<windows.h>
#include<conio.h>
#include"console.h"

void printPiece(int x, int y, wchar_t symbol){
    gotoxy(x, y);
    wprintf(L"┌───┐");
    gotoxy(x,y+1);
    wprintf(L"│   │");
    gotoxy(x,y+2);
    wprintf(L"│   │");
    gotoxy(x,y+3);
    wprintf(L"│   │");
    gotoxy(x,y+4);
    wprintf(L"└───┘");
    gotoxy(x+2,y+2);
    wprintf(symbol);
}