#define RESET       "\033[0m"              /* Reset */
#define GRAY        "\033[1;30m"           /* Gray */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

#include <iostream>
#include "stdlib.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;


int main()
{
    // Terminál törlése és méret beállítása
       cout << "\033[2J\033[1;1H";
       cout << "\e[8;54;76t";
    
    double spear = 18 * 60;
    double sword = 22 *60;
    double archer = 18 *60;
    double axe = 18 *60;
    double spy = 9 *60;
    double light = 10 *60;
    double marcher = 10 *60;
    double heavy = 11 *60;
    double ram = 30 *60;
    double catapult = 30 *60;
    double paladin = 10 *60;
    double nobleman = 35 *60;
    
    /* Egységek gyorsasága 1 mezőre megtételére nézve
    double spear = 18.000000000504 * 60;
    double sword = 21.999999999296 *60;
    double archer = 18.000000000504 *60;
    double axe = 18.000000000504 *60;
    double spy = 8.99999999928 *60;
    double light = 9.999999998 *60;
    double marcher = 9.999999998 *60;
    double heavy = 11.0000000011 *60;
    double ram = 29.9999999976 *60;
    double catapult = 29.9999999976 *60;
    double paladin = 9.999999998 *60;
    double nobleman = 34.9999999993 *60;
     */
    
   /* double units[12];
        units[0] = 18.000000000504;
        units[1] = 21.999999999296;
        units[2] = 18.000000000504;
        units[3] = 18.000000000504;
        units[4] = 8.99999999928;
        units[5] = 9.999999998;
        units[6] = 9.999999998;
        units[7] = 11.0000000011;
        units[8] = 29.9999999976;
        units[9] = 29.9999999976;
        units[10] = 9.999999998;
        units[11] = 34.9999999993;
    */
    
    double starta = 0;
    double startb = 0;
    double enda = 0;
    double endb = 0;
    int unittype = 0;
    double ref = 0;
    
    // Indító falu koodinátái
    cout << BOLDRED << "Add meg az indító falu koordinátáit:" << RESET << endl;
    cout << "x1: ";
    cin >> starta;
    cout << "y1: ";
    cin >> startb;
    
    // Érkező falu koordinátái
    cout << BOLDRED << "Add meg az érkezési falu koordinátáit:" << RESET << endl;
    cout << "x2: ";
    cin >> enda;
    cout << "y2: ";
    cin >> endb;
    
    // Milyen egységgel számoljunk
    cout << BOLDRED << "Milyen egységgel szeretnél számolni ?" << RESET << endl;
    cout << GRAY << "Lándzsás = 1" << endl;
    cout << "Kardos = 2" << endl;
    cout << "Íjász = 3" << endl;
    cout << "Bárdos = 4" << endl;
    cout << "Kém = 5" << endl;
    cout << "Könnyűlovas = 6" << endl;
    cout << "Lovasíjász = 7" << endl;
    cout << "Nehzélovas = 8" << endl;
    cout << "Faltörőkos = 9" << endl;
    cout << "Katapult = 10" << endl;
    cout << "Lovag = 11" << endl;
    cout << "Nemes = 12" << RESET << endl;
   
    cout << BOLDRED << "Az általad választott egység: " << RESET;
    cin >> unittype;
    
    switch (unittype)
        {
        case 1 : unittype = spear;
            break;
        case 2 : unittype = sword;
            break;
        case 3 : unittype = archer;
            break;
        case 4 : unittype = axe;
            break;
        case 5 : unittype = spy;
            break;
        case 6 : unittype = light;
            break;
        case 7 : unittype = marcher;
            break;
        case 8 : unittype = heavy;
            break;
        case 9 : unittype = ram;
            break;
        case 10 : unittype = catapult;
            break;
        case 11 : unittype = paladin;
            break;
        case 12 : unittype = nobleman;
            break;
        }
    
    // Távolság számolása
    double distance = sqrt( (enda - starta) * (enda - starta) + (endb - startb) * (endb - startb) );
    
    cout << BOLDBLUE << "A távolság a két falu között: " << RESET << distance << endl;
    
    // Utazási idő számolása
    double travel = (distance * unittype);
    
    cout << "Az utazási idő:" << travel << endl;
    
    // Decimális számérték
    double dec = fmod(travel, 1);
    
    cout << "A decimális szám:" << dec << endl;
    
  /*
    int year = 0;
    int month = 0;
    int day = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    
    cout << "Év:" << endl;
    cin >> year;
    cout << "Hónap:" << endl;
    cin >> month;
    cout << "Nap:" << endl;
    cin >> day;
    cout << "Óra:" << endl;
    cin >> hours;
    cout << "Perc:" << endl;
    cin >> minutes;
    cout << "Másodperc:" << endl;
    cin >> seconds;
    
    std::string nulla = "0";
    
    if (day < 10) {
        day = nulla + day;
    }

    if (month < 10) {
        month = nulla + month;
    }

    if (hours < 10) {
        hours = nulla + hours;
    }

    if (minutes < 10) {
        minutes = nulla + minutes;
    }

    if (seconds < 10) {
        seconds = nulla + seconds;
    }
*/
   // current date/time based on current system
   time_t now = time(0);

   //cout << "Number of sec since January 1,1970:" << now << endl;

   tm *ltm = localtime(&now);

   // print various components of tm structure.
   cout << "Év: " << 1900 + ltm->tm_year << endl;
   cout << "Hónap: "<< 1 + ltm->tm_mon<< endl;
   cout << "Nap: "<<  ltm->tm_mday << endl;
   cout << "Idő: "<< 1 + ltm->tm_hour << ":";
   cout << 1 + ltm->tm_min << ":";
   cout << 1 + ltm->tm_sec << endl;
    
    cout << BOLDRED << "Ez a modified:"<< travel << RESET << endl;


    float modified =0;
    cout << "Add meg az idődet amire időzíteni szeretnél:" << modified << endl;
    cin >> modified;
    //time_t modified = time(0);
    cout << "Number of sec since January 1,1970 to modified:" << modified << endl;
    
    // A decimális számérték átalakítása
    //double decconv = dec * (0.6);
    
    //cout << "A decimális szám átalakítva:" << decconv << endl;
    
    // Az utazási idő, már átalakítva
    //double abstravel = ((travel - dec) + decconv);
    
    //cout << std:: fixed;
    //cout << setprecision(2);
    //cout << BOLDBLUE << "Utazási idő: " << RESET << abstravel << endl;

    return 0;
}
