#include<stdio.h>
#include<wchar.h>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<time.h>
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
                    table[i][j] = (int) newSymbols[l];
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
    int removedPieces = 0;



    gotoxy(x, y);
    while(1){
        int key = 0;
        int selectedPiece = selectedX == x && selectedY == y;
        int samePieces = selectedSymbol == table[positionY][positionX];
        int validPiece = !table[positionY][positionX + 1] || !table[positionY][positionX - 1];
        int isSelected = selectedX == x && selectedY == y;

        if(_kbhit()){
            key = _getch();
            if(key == 0 || key == 0XE0) key = _getch();

            if(key == 77 && positionX < 7){
                positionX += 1;
                x += 5;
            } else
            if(key == 75 && positionX > 1){
                positionX -= 1;
                x -= 5;
            } else
            if(key == 72 && positionY > 0){
                positionY -= 1;
                y -= 4;
            } else
            if(key == 80 && positionY < 5){
                positionY += 1;
                y += 4;
            } else
            if(key == 27){
                reset();
                break;
            } else
            if(key == 13 && table[positionY][positionX] && validPiece && !isSelected){
                if(!samePieces && selectedSymbol){
                    gotoxy(x, y - 1);
                    wprintf(L" ");
                    gotoxy(selectedX, selectedY - 1);
                    wprintf(L" ");
                    selectedX = 0;
                    selectedY = 0;
                    selectedSymbol = 0;
                } else 
                if(samePieces){
                    reset();
                    table[(int)floor((selectedY - 10)/4)][(int)floor((selectedX - 62)/5)] = 0;
                    table[positionY][positionX] = 0;
                    printGameStyle();
                    for (int i = 0; i < 6; i++){
                        for (int j = 0; j < 9; j++){
                                if(table[i][j]){
                                    printPiece(60 + (j * 5), 8 + (i * 4), table[i][j]);
                                }
                        }
                    }
                    removedPieces += 2;
                    gotoxy(130, 8);
                    wprintf(L"Peças retiradas: ");
                    gotoxy(148, 8);
                    wprintf(L"%d", removedPieces);
                    selectedX = 0;
                    selectedY = 0; 
                    selectedSymbol = 0;
                }
                else {
                    gotoxy(x, y - 1);
                    selectedX = x;
                    selectedY = y;
                    selectedSymbol = table[positionY][positionX];
                    wprintf(L"#");
                }
            } else
            if(key == 13 && isSelected){
                gotoxy(x, y -1);
                selectedX = 0;
                selectedY = 0;
                selectedSymbol = 0;
                wprintf(L" ");
            }
        gotoxy(x, y);
        }
    if(removedPieces == 38){
        reset();
        break;
    }
    }
}

void randomizePiecesMedium(){   
    wprintf(L"");
}

void randomizePiecesHard(){
    wprintf(L"");
}