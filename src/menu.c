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
    wprintf(L"│      SAIR     │");
    gotoxy(120, 18);
    wprintf(L"│               │");
    gotoxy(120, 19);
    wprintf(L"└───────────────┘");
}

void selectItem(){
    char *keySelected[4] = {"printGame", "printDificulty", "printHelp", "quit"};
    
    int key = 0;
    int position = 0, x = 38, y = 17;


    while(1)
    {
        if (_kbhit()) {
            key = _getch();
            if (key==0 || key==0xE0) key=_getch();

            if (key == 77 && position < 3) {
                position += 1;
                x += 30;
            } else if (key == 75 && position > 0) {
                position -= 1;
                x -= 30;
            } else if (key == 13) {
                wprintf(L"%ls", keySelected[position]);
            } else if (key == 27)
			break;

            gotoxy(x, y);
        }    
    } 
 
}


void main(){
    _setmode(_fileno(stdout), 0x00020000);
    printMenu();
    selectItem();    
} 