#include <iostream>
#include <algorithm>
#include "Universe.h"


Universe::Universe(int num, bool randomize){ // ramdomize first layout of this game
            NumberofGen = num;
            if (randomize == true){
                for (auto& row : board){
                    generate(row.begin(), row.end(), [](){return rand() % 10 == 0 ? 1 : 0;});
                }
            }
            else{
                for (int i = 0; i < SIZE1; i++){
                    for (int j = 0; j < SIZE2; j++){
                        cin >> board[i][j];
                        if (board[i][j] >= 1){
                            board[i][j] = 1;
                        }
                        else{
                            board[i][j] = 0;
                        }
                    }
                }
            } 
        }
void Universe::reset(){
    for (auto& row : board){
        fill(row.begin(), row.end(), 0);
    }
}
int Universe::count_neighbors(int x, int y){
    int count = 0;
    if (board[x - 1][y] == 1){
        count++;
    }
    if (board[x + 1][y] == 1){
        count++;
    }
    if (board[x][y - 1] == 1){
        count++;
    }
    if (board[x][y + 1] == 1){
        count++;
    }
    if (board[x - 1][y - 1] == 1){
        count++;
    }
    if (board[x - 1][y + 1] == 1){
        count++;
    }
    if (board[x + 1][y - 1] == 1){
        count++;
    }
    if (board[x + 1][y + 1] == 1){
        count++;
    }
    return count;
}
void Universe::next_generation(){
    array<array<int, SIZE1> , SIZE2> temp;
    for (int i = 0; i < SIZE1; i++){
        for (int j = 0; j < SIZE2; j++){
            if (count_neighbors(i, j) < 2){
                temp[i][j] = 0;
            }
            else if (count_neighbors(i, j) == 2){
                temp[i][j] = board[i][j];
            }
            else if (count_neighbors(i, j) == 3){
                temp[i][j] = 1;
            }
            else if (count_neighbors(i, j) > 3){
                temp[i][j] = 0;
            }
        }
    }
    board = temp;
}
void Universe::display(){
    for (int i = 0; i < SIZE1; i++){
        for (int j = 0; j < SIZE2; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    this->next_generation();
}
void Universe::run(){
    int temp = NumberofGen;
    int num = 1;
    while (temp != 0){
        cout << num << "/" << NumberofGen << endl;
        this->display();
        system("pause");
        system("CLS");
        num++;
        temp--;
    }
}