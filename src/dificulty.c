#include<stdio.h>
#include<wchar.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include"console.h"
#include"style.h"
#include"pieces.h"
#include"menu.h"


void printDificulty(){
    reset();
    printDificultyStyle();

    gotoxy(30, 15);
    wprintf(L"┌───────────────┐");
    gotoxy(30, 16);
    wprintf(L"│               │");
    gotoxy(30, 17);
    wprintf(L"│     FÁCIL     │");
    gotoxy(30, 18);
    wprintf(L"│               │");
    gotoxy(30, 19);
    wprintf(L"└───────────────┘");

    gotoxy(60, 15);
    wprintf(L"┌───────────────┐");
    gotoxy(60, 16);
    wprintf(L"│               │");
    gotoxy(60, 17);
    wprintf(L"│     MÉDIO     │");
    gotoxy(60, 18);
    wprintf(L"│               │");
    gotoxy(60, 19);
    wprintf(L"└───────────────┘");

    gotoxy(90, 15);
    wprintf(L"┌───────────────┐");
    gotoxy(90, 16);
    wprintf(L"│               │");
    gotoxy(90, 17);
    wprintf(L"│    DÍFICIL    │");
    gotoxy(90, 18);
    wprintf(L"│               │");
    gotoxy(90, 19);
    wprintf(L"└───────────────┘");

    gotoxy(120, 15);
    wprintf(L"┌───────────────┐");
    gotoxy(120, 16);
    wprintf(L"│               │");
    gotoxy(120, 17);
    wprintf(L"│     VOLTAR    │");
    gotoxy(120, 18);
    wprintf(L"│               │");
    gotoxy(120, 19);
    wprintf(L"└───────────────┘");
}

void selectItemDificulty(){    
    int key = 0;
    int position = 0, x = 38, y = 17;
    gotoxy(x, y);


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
               if(position == 0){
                    randomizePiecesEasy();
                    break;
               } else if (position == 1){
                    randomizePiecesMedium();
               } else if (position == 2){
                    randomizePiecesHard();
               } else if (position == 3){
                    printMenu();
                    selectItem();
               }
            } else if (key == 27)
			break;

            gotoxy(x, y);
        }    
    } 
}