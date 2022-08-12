#include<stdio.h>
#include<wchar.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include"console.h"
#include"style.h"
#include"dificulty.h"
#include"pieces.h"


void printEasy(){
    reset();
    printGameStyle();
    randomizePiecesEasy();
}

void printMedium(){
    wprintf(L"printa modo medio");
}

void printHard(){
    wprintf(L"printa modo dificil");
}