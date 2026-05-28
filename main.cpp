#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>// bu fonksiyon tuşlara bastıktan sonra entera basmaya gerek kalmadan hamleyi yapmamıza yarayacak.

using namespace std;
int board[4][4];
int yedeksa[4];
int skor=0;

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
            skor+=yedeksa[k];
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
             skor+=yedeksa[k];
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

    void yukarikaydir(){
            for (int j=0;j<4;j++){
   for (int i=0;i<4; i++) {
      yedeksa[i]=board[i][j];
       }
 
       for (int t=0;t<3;t++){// bu döngü yukarı kaydırıyor.
         for (int k=0;k<3;k++){
         if (yedeksa[k]==0){
           yedeksa[k]=yedeksa[k+1];
           yedeksa[k+1]=0;
          }
         }
        }

            for (int k=0;k<3;k++){// bu döngü yukarı kaymış olanı topluyor. 
           if(yedeksa[k]==yedeksa[k+1]){
            yedeksa[k]*=2;
            yedeksa[k+1]=0;
             skor+=yedeksa[k];
           }
        }

         for (int t=0;t<3;t++){// bu döngüde toplanmış olanları tekrar yukarı kaydırıyor.
   for (int k=0;k<3;k++){
      if (yedeksa[k]==0){
         yedeksa[k]=yedeksa[k+1];
         yedeksa[k+1]=0;
      }
   }
}

for (int i=0;i<4; i++) {// bu da diğer sutüna geçmeden doğru sutünü boarda ekliyor.
     board[i][j]=yedeksa[i];
       }
      }
     }

     void asagikaydir(){//nerdeyse herşey yukarı kaydırma fonksiyonu ile aynı ama sadece yedek kısma ters kopyalayıp yukarı kaydırıyoruz ve yine tersten yapıştırıyoruz boarda böylece aşağı kaymış oluyor
            for (int j=0;j<4;j++){
   for (int i=0;i<4; i++) {
      yedeksa[i]=board[3-i][j];
       }
 
       for (int t=0;t<3;t++){// bu döngü yukarı kaydırıyor.
         for (int k=0;k<3;k++){
         if (yedeksa[k]==0){
           yedeksa[k]=yedeksa[k+1];
           yedeksa[k+1]=0;
          }
         }
        }

            for (int k=0;k<3;k++){// bu döngü yukarı kaymış olanı topluyor. 
           if(yedeksa[k]==yedeksa[k+1]){
            yedeksa[k]*=2;
            yedeksa[k+1]=0;
             skor+=yedeksa[k];
           }
        }

         for (int t=0;t<3;t++){// bu döngüde toplanmış olanları tekrar yukarı kaydırıyor.
   for (int k=0;k<3;k++){
      if (yedeksa[k]==0){
         yedeksa[k]=yedeksa[k+1];
         yedeksa[k+1]=0;
      }
   }
}

for (int i=0;i<4; i++) {// bu da diğer sutüna geçmeden doğru sutünü boarda ekliyor.
     board[3-i][j]=yedeksa[i];
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
    cout << endl;
    cout << "Skor: " << skor << endl;
}

void addRandom() {
    int r, c;
    bool bosvarmi = false;
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (board[i][j] == 0) bosvarmi = true;}
        }
    
    if (bosvarmi) {
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
}

int main() {
   bool kazanma=false;
   bool kaybetme=true;
   srand(time(0));
    cout << "2048 Oyunu - Baslangic" << endl;




for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            board[i][j] = 0;}
}

addRandom();
addRandom();
do {
system("cls");
printBoard();   
int tus = _getch();
if (tus == 224) {
    tus = _getch();
    if (tus == 72) yukarikaydir();
    else if (tus == 80) asagikaydir();
    else if (tus == 75) solakaydir();
    else if (tus == 77) sagakaydir();
}
 for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (board[i][j] == 2048) kazanma = true;}
        }

         kaybetme=true;
         for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) kaybetme=false;     
            if (j < 3 && board[i][j] == board[i][j+1]) kaybetme=false; 
            if (i < 3 && board[i][j] == board[i+1][j]) kaybetme=false; 
        }
    }

    addRandom();
}
while (kazanma || !kaybetme);

system("cls");
printBoard();
if (kazanma) cout << "Tebrikler! Kazandiniz! Skor: " << skor << endl;
if (kaybetme) cout << "Oyun Bitti! Skor: " << skor << endl;


  return 0;
}