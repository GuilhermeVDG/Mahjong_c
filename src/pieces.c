#include<stdio.h>
#include<wchar.h>
#include<windows.h>
#include<conio.h>
#include"console.h"
#include"pieces.h"
#include"style.h"


void printPiece(int x, int y, int symbol){
    gotoxy(x, y);
    wprintf(L"┏┅┅┅┓");
    gotoxy(x,y+1);
    wprintf(L"┇   ┇");
    gotoxy(x,y+2);
    wprintf(L"┇   ┇");
    gotoxy(x,y+3);
    wprintf(L"┇   ┇");
    gotoxy(x,y+4);
    wprintf(L"┗┅┅┅┛");
    gotoxy(x+2,y+2);
    wprintf(L"%S", symbol);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize(int arr[], int n){
    srand(time(NULL));
    int i;
    for(i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]); 
    }
}


void randomizePiecesEasy(){
    reset();
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};
    int n = sizeof(arr)/sizeof(arr[0]);
    char *symbols[38] = {"a","a","a","a","a","a","b","b","b","b","c","c","c","c","d","d","d","d","e","e","e","e","f","f","f","f","g","g","g","g","h","h","h","h","i","i","i","i"};
    randomize(arr, n);
    int table[6][9] = {{0,0,1,1,1,1,1,0,0},
                       {0,1,1,1,1,1,1,1,0},
                       {0,1,1,1,1,1,1,1,0},
                       {0,1,1,1,1,1,1,1,0},
                       {0,1,1,1,1,1,1,1,0},
                       {0,0,1,1,1,1,1,0,0}};

    int x = 60;
    int y = 8;
    char *newSymbols[38];

    for(int k = 0; k < n; k++){
        int index = arr[k];
        newSymbols[k] = symbols[index];
    }
    int l = 0;

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
                if(table[i][j]){
                    table[i][j] = newSymbols[l];
                    printPiece(x + (j * 5), y + (i * 4), table[i][j]);
                    l++;
                }
        }
    }
    
    printGameStyle();
    int positionX = 0;
    int positionY = 0;
    x = 62;
    y = 10;
    int selectedX = 0;
    int selectedY = 0;
    int selectedSymbol = 0;



    
    while(1){
        int key = 0;
        int selectedPiece = selectedX == x && selectedY == y;
        int samePieces = selectedSymbol == table[positionY][positionX];

        if(_kbhit()){
            key = _getch();
            if(key == 0 || key == 0XE0) key = _getch();

            if(key == 77){
                positionX += 1;
                x += 5;
            }
            if(key == 75){
                positionX =- 1;
                x -= 5;
            }
            if(key == 80){
                positionY += 1;
                y += 4;
            }
            if(key == 72){
                positionY -= 1;
                y -= 4;
            }
        gotoxy(x, y);
        }
    }
}

void randomizePiecesMedium(){
    wprintf(L"printa modo medio");
}

void randomizePiecesHard(){
    wprintf(L"printa modo dificil");
}