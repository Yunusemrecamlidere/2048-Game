#include <iostream>
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

int main() {
    cout << "2048 Oyunu - Baslangic" << endl;

for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = 0;

    printBoard();


   return 0;
}