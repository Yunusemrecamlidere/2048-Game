#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>// bu fonksiyon tuşlara bastıktan sonra entera basmaya gerek kalmadan hamleyi yapmamıza yarayacak.
#include <SFML/Graphics.hpp>
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

    sf::Font font;
font.openFromFile("C:\\Windows\\Fonts\\arial.ttf");

  sf::RenderWindow window(sf::VideoMode({520u, 620u}), "2048");
    
    srand(time(0));
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = 0;
    
    addRandom();
    addRandom();
    
    bool kazanma = false;
    bool kaybetme = false;
    
    while (window.isOpen()) {
        
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        
       window.clear(sf::Color(250, 248, 239));

// Tahta arka planı
sf::RectangleShape tahta(sf::Vector2f(480, 480));
tahta.setPosition({20, 120});
tahta.setFillColor(sf::Color(187, 173, 160));

window.draw(tahta);

// Hücreleri çiz
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      sf::RectangleShape hucre(sf::Vector2f(106, 106));
hucre.setPosition({28.f + j * 118.f, 128.f + i * 118.f});
        hucre.setFillColor(sf::Color(205, 193, 180));
        window.draw(hucre);
        if (board[i][j] != 0) {
    sf::Text text(font, std::to_string(board[i][j]), 32);
    text.setFillColor(sf::Color(119, 110, 101));
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({bounds.position.x + bounds.size.x / 2.f, 
                    bounds.position.y + bounds.size.y / 2.f});
    text.setPosition({28.f + j * 118.f + 53.f, 128.f + i * 118.f + 53.f});
    window.draw(text);
}
    }
}

window.display();
    }
    
    return 0;
}