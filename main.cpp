#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int board[4][4];

void printBoard() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

void addRandom() {
    int r, c;
    do {
        r = rand() % 4;
        c = rand() % 4;
    } while (board[r][c] != 0);
    
    int sayi = rand() % 10 + 1;
    if (sayi == 10)
        board[r][c] = 4;
    else
        board[r][c] = 2;
}

int main() {
    cout << "2048 Oyunu - Baslangic" << endl;

for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = 0;

srand(time(0));
addRandom();
addRandom();

    printBoard();

  return 0;
}