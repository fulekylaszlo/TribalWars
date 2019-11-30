#define RESET       "\033[0m"              /* Reset */
#define GRAY        "\033[1;30m"           /* Gray */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */


#include <iostream>
#include "stdlib.h"
#include <unistd.h>
using namespace std;

int main()
{
    
    //Terminál törlése és méret beállítása
    cout << "\033[2J\033[1;1H";
    cout << "\e[8;24;71t";
    
    //Alapfalu tanyahelyei
    int mainb = 99;
    int barrack = 303;
    int stable = 158;
    int garage = 15;
    int smith = 180;
    int statue = 10;
    int market = 395;
    int wood = 326;
    int stone = 447;
    int iron = 949;
    int wall = 99;
    int church = 0;
    int academy = 0;
    int watchtower = 0;
    
    //Alapfalu szintjei
    cout << BOLDRED << "Alapfalu kiépítése szintekkel:" << RESET << endl;
    cout << BOLDBLUE << "Főhadiszállás: " << RESET << "20" << endl;
    cout << BOLDBLUE << "Barakk: " << RESET << "25" << endl;
    cout << BOLDBLUE << "Istálló: " << RESET << "20" << endl;
    cout << BOLDBLUE << "Műhely: " << RESET << "5" << endl;
    cout << BOLDBLUE << "Kovácsműhely: " << RESET << "15" << endl;
    cout << BOLDBLUE << "Szobor: " << RESET << "1" << endl;
    cout << BOLDBLUE << "Piac: " << RESET << "20" << endl;
    cout << BOLDBLUE << "Fatelep: " << RESET << "30" << endl;
    cout << BOLDBLUE << "Agyagbánya: " << RESET << "30" << endl;
    cout << BOLDBLUE << "Vasbánya: " << RESET << "30" << endl;
    cout << BOLDBLUE << "Tanya: " << RESET << "30" << endl;
    cout << BOLDBLUE << "Raktár: " << RESET << "30" << endl;
    cout << BOLDBLUE << "Fal: " << RESET << "20" << endl;
    cout << BOLDRED << "--------------------------------" << RESET << endl;
    
    // Akadémia számolása
    cout << BOLDRED << "->Hanyas szintű az akadémia [0-1] ?" << RESET << endl;
    cin >> academy;
    switch (academy)
        {
        case 1 : academy = 80;
            break;
        default : academy =0;
        }
    
    // Őrtorony számolása
    cout << BOLDRED << "->Hanyas szintű az őrtorony [0-20] ?" << RESET << endl;
    cin >> watchtower;
    switch (watchtower)
          {
              case 1 : watchtower = 500;
                  break;
              case 2 : watchtower = 590;
                  break;
              case 3 : watchtower = 696;
                  break;
              case 4 : watchtower = 822;
                  break;
              case 5 : watchtower = 969;
                  break;
              case 6 : watchtower = 1144;
                  break;
              case 7 : watchtower = 1350;
                  break;
              case 8 : watchtower = 1593;
                  break;
              case 9 : watchtower = 1879;
                  break;
              case 10 : watchtower = 2218;
                  break;
              case 11 : watchtower = 2617;
                  break;
              case 12 : watchtower = 3088;
                  break;
              case 13 : watchtower = 3644;
                  break;
              case 14 : watchtower = 4300;
                  break;
              case 15 : watchtower = 5074;
                  break;
              case 16 : watchtower = 5987;
                  break;
              case 17 : watchtower = 7065;
                  break;
              case 18 : watchtower = 8336;
                  break;
              case 19 : watchtower = 9837;
                  break;
              case 20 : watchtower = 11607;
                  break;
              default : watchtower =0;
          }
    
    // Templom számolása
    cout << BOLDRED << "->Hanyas szintű a templom [0-3] ?" << RESET << endl;
    cin >> church;
    switch (church)
       {
           case 1 : church = 5000;
               break;
           case 2 : church = 7750;
               break;
           case 3 : church = 12013;
               break;
           default : church =0;
       }
    // Minden épület tanyahelye
    int alltanya = mainb + barrack
    + stable + garage + smith + statue + market + wood + stone + iron + wall +
    church + watchtower + academy;
    
    // Lefoglalt/Szabad tanyahelyek száma
    cout << BOLDRED << "->Összesen lefoglalt tanyahely:" << RESET << BOLDBLUE << alltanya  << RESET << endl;
    cout << BOLDRED << "->Szabadon maradt tanyahely:" << RESET << BOLDBLUE << 24000 - alltanya << RESET << endl;
    
    return 0;
}
