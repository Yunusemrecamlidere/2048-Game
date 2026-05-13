#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int board[4][4];
int yedeksa[4];

void solakaydir(){

for (int i=0;i<4;i++){
   for (int j = 0; j < 4; j++) {
      yedeksa[j]=board[i][j];
       }
       for (int t=0;t<3;t++){// bu döngü sola kaydırıyor.
         for (int k=0;k<3;k++){
         if (yedeksa[k]==0){
           yedeksa[k]=yedeksa[k+1];
           yedeksa[k+1]=0;}
         }
        }
            for (int k=0;k<3;k++){// bu döngü sola kaymış olanı topluyor. 
           if(yedeksa[k]==yedeksa[k+1]){
            yedeksa[k]*=2;
            yedeksa[k+1]=0;
           }
        }
     for (int t=0;t<3;t++){// bu döngüde toplanmış olanları tekrar sola kaydırıyor.
   for (int k=0;k<3;k++){
      if (yedeksa[k]==0){
         yedeksa[k]=yedeksa[k+1];
         yedeksa[k+1]=0;
      }
   }
}
       
          for (int j=0; j<4; j++){// bu da alt satıra geçmeden doğru satırı boarda ekliyor.
    board[i][j]=yedeksa[j];
}
         }
    }


    void sagakaydir(){
    for (int i=0;i<4;i++){
   for (int j =0; j<4; j++) {//herşeyiyle tamamen sola kaydırmayı kopyaladım ancak burada boardı yedek satıra tersten kopyalıyoruz böylece sola kaydırıp tekrar ters çevirince sağa kaydırmış olacak mantık bu.
      yedeksa[j]=board[i][3-j];
       }
       for (int t=0;t<3;t++){// bu döngü sola kaydırıyor.
         for (int k=0;k<3;k++){
         if (yedeksa[k]==0){
           yedeksa[k]=yedeksa[k+1];
           yedeksa[k+1]=0;}
         }
        }
            for (int k=0;k<3;k++){// bu döngü sola kaymış olanı topluyor. 
           if(yedeksa[k]==yedeksa[k+1]){
            yedeksa[k]*=2;
            yedeksa[k+1]=0;
           }
        }
     for (int t=0;t<3;t++){// bu döngüde toplanmış olanları tekrar sola kaydırıyor.
   for (int k=0;k<3;k++){
      if (yedeksa[k]==0){
         yedeksa[k]=yedeksa[k+1];
         yedeksa[k+1]=0;
      }
   }
}
       
          for (int j =0; j<4; j++){// bu da alt satıra geçmeden doğru satırı boarda ekliyor.
    board[i][j]=yedeksa[3-j];
}
         }
    }
  
     
   
       


 




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
addRandom();
addRandom();
sagakaydir();
printBoard();
  return 0;
}