#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<wchar.h>
#include<stdlib.h>
#include"console.h"

void gotoxy(int x, int y){

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

void reset(){
    system("cls");
}

void quit(){
    reset();
    exit(1);
}



