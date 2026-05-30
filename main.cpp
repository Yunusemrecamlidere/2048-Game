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
    
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->code == sf::Keyboard::Key::Up) yukarikaydir();
        else if (keyPressed->code == sf::Keyboard::Key::Down) asagikaydir();
        else if (keyPressed->code == sf::Keyboard::Key::Left) solakaydir();
        else if (keyPressed->code == sf::Keyboard::Key::Right) sagakaydir();
        addRandom();
        
        // kazanma kontrolü
for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
        if (board[i][j] == 2048) kazanma = true;

// kaybetme kontrolü
kaybetme = true;
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        if (board[i][j] == 0) kaybetme = false;
        if (j < 3 && board[i][j] == board[i][j+1]) kaybetme = false;
        if (i < 3 && board[i][j] == board[i+1][j]) kaybetme = false;
    }
}
    }
}
       window.clear(sf::Color(250, 248, 239));

       
        sf::Text skorText(font, "Skor: " + std::to_string(skor), 28);
skorText.setFillColor(sf::Color(119, 110, 101));
skorText.setPosition({20, 20});
window.draw(skorText);

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

       sf::Color hucreRengi;
switch(board[i][j]) {
    case 0:    hucreRengi = sf::Color(205, 193, 180); break;
    case 2:    hucreRengi = sf::Color(238, 228, 218); break;
    case 4:    hucreRengi = sf::Color(237, 224, 200); break;
    case 8:    hucreRengi = sf::Color(242, 177, 121); break;
    case 16:   hucreRengi = sf::Color(245, 149, 99);  break;
    case 32:   hucreRengi = sf::Color(246, 124, 95);  break;
    case 64:   hucreRengi = sf::Color(246, 94, 59);   break;
    case 128:  hucreRengi = sf::Color(237, 207, 114); break;
    case 256:  hucreRengi = sf::Color(237, 204, 97);  break;
    case 512:  hucreRengi = sf::Color(237, 200, 80);  break;
    case 1024: hucreRengi = sf::Color(237, 197, 63);  break;
    case 2048: hucreRengi = sf::Color(237, 194, 46);  break;
    default:   hucreRengi = sf::Color(60, 58, 50);    break;
}

hucre.setFillColor(hucreRengi);
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
if (kazanma) {
    sf::Text kazanText(font, "Tebrikler! 2048!", 40);
    kazanText.setFillColor(sf::Color(119, 110, 101));
    kazanText.setPosition({80, 50});
    window.draw(kazanText);
}

if (kaybetme) {
    sf::Text kaybeText(font, "Oyun Bitti!", 40);
    kaybeText.setFillColor(sf::Color(255, 0, 0));
    kaybeText.setPosition({130, 50});
    window.draw(kaybeText);
}
window.display();
    }
    
    return 0;
}