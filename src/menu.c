#include<stdio.h>
#include<wchar.h>
#include<windows.h>
#include<conio.h>
#include"console.h"
#include"style.h"

void printMenu(){
    reset();
    printBars(25);
    printMenuTittle();

    gotoxy(30, 15);
    wprintf(L"┌───────────────┐");
    gotoxy(30, 16);
    wprintf(L"│               │");
    gotoxy(30, 17);
    wprintf(L"│     JOGAR     │");
    gotoxy(30, 18);
    wprintf(L"│               │");
    gotoxy(30, 19);
    wprintf(L"└───────────────┘");

    gotoxy(60, 15);
    wprintf(L"┌───────────────┐");
    gotoxy(60, 16);
    wprintf(L"│               │");
    gotoxy(60, 17);
    wprintf(L"│  DIFICULDADE  │");
    gotoxy(60, 18);
    wprintf(L"│               │");
    gotoxy(60, 19);
    wprintf(L"└───────────────┘");

    gotoxy(90, 15);
    wprintf(L"┌───────────────┐");
    gotoxy(90, 16);
    wprintf(L"│               │");
    gotoxy(90, 17);
    wprintf(L"│     AJUDA     │");
    gotoxy(90, 18);
    wprintf(L"│               │");
    gotoxy(90, 19);
    wprintf(L"└───────────────┘");

    gotoxy(120, 15);
    wprintf(L"┌───────────────┐");
    gotoxy(120, 16);
    wprintf(L"│               │");
    gotoxy(120, 17);
    wprintf(L"│     SAIR      │");
    gotoxy(120, 18);
    wprintf(L"│               │");
    gotoxy(120, 19);
    wprintf(L"└───────────────┘");
}


void main(){
    _setmode(_fileno(stdout), 0x00020000);
    printMenu();
} 