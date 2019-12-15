#define RESET       "\033[0m"              /* Reset */
#define GRAY        "\033[90m"           /* Gray */
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
    cout << "\e[8;40;71t";
    
    //Újraszámítás kezdete
    ujrakezdes :
    
    //Újraszámítás
    int ujraszamitas = 0;
    
    //Faluban levő nyersanyagok
    int falubanlevonyersanyag = 0;
    
    int zaszlohasznalat = 0;
    
    //Zászlók:
    float bonusz = 0;
    cout << BOLDRED << "->Hány százalékos érmecsökkentéses bónuszaid vannak?" << RESET << endl;
   /* cout << GRAY << "#----------------------------------" << RESET << endl;
    cout << GRAY << "#Zászló használat nélkül '0'-át írj!" << RESET << endl;
    cout << GRAY << "#10 %-os zászló esetén '10'-et írj!" << RESET << endl;
    cout << GRAY << "#12 %-os zászló esetén '12'-őt írj!" << RESET << endl;
    cout << GRAY << "#14 %-os zászló esetén '14'-et írj!" << RESET << endl;
    cout << GRAY << "#16 %-os zászló esetén '16'-ot írj!" << RESET << endl;
    cout << GRAY << "#18 %-os zászló esetén '18'-at írj!" << RESET << endl;
    cout << GRAY << "#20 %-os zászló esetén '20'-at írj!" << RESET << endl;
    cout << GRAY << "#22 %-os zászló esetén '22'-őt írj!" << RESET << endl;
    cout << GRAY << "#23 %-os zászló esetén '23'-at írj!" << RESET << endl;
    cout << GRAY << "#24 %-os zászló esetén '24'-et írj!" << RESET << endl;
    cout << GRAY << "#----------------------------------" << RESET << endl; */
    cout << GRAY << "Bónusz:" << RESET;
    cin >> bonusz;
    
    //1 darab érme legyártásának költségei zászlóval
    float ermefa = 28000 - (28000 * (bonusz / 100));
    float ermeagyag = 30000 - (30000 * (bonusz / 100));
    float ermevas = 25000 - (25000 * (bonusz / 100));
    
    //1 darab nemes legyártásának költségei
    float nemesmennyiseg = 0;
    float nemesfa = 40000;
    float nemesagyag = 50000;
    float nemesvas = 50000;
    
    //1 falu termelése 1 óra alatt
    float termelesfa = 0;
    float termelesagyag = 0;
    float termelesvas = 0;
    
    //Faluban lévő nyersanyagok
    float alapfa = 0;
    float alapagyag = 0;
    float alapvas = 0;
    
    //Szükséges érme mennyisége 1 darab nemeshez
    float ermemennyiseg = 0;
    
    //Termelés megadása
    cout << BOLDRED << "->Add meg a termelésed:" << RESET << endl;
    cout << GRAY << "Fa:" << RESET;
    cin >> termelesfa;
    
        if (termelesfa < 0)
        {
            cout << GRAY << "#Helytelen gomblenyomás, kérlek [0-∞] közül válassz!" << RESET << endl;
            goto ujrakezdes;
        }
        cout << GRAY << "Agyag:" << RESET;
        cin >> termelesagyag;
    
        if (termelesagyag < 0)
        {
            cout << GRAY << "#Helytelen gomblenyomás, kérlek [0-∞] közül válassz!" << RESET << endl;
            goto ujrakezdes;
        }
        cout << GRAY << "Vas:" << RESET;
        cin >> termelesvas;
    
        if (termelesvas < 0)
        {
            cout << GRAY << "#Helytelen gomblenyomás, kérlek [0-∞] közül válassz!" << RESET << endl;
            goto ujrakezdes;
        }
    
    //Faluban levő nyersanyaggal való számolás
    cout << BOLDRED << "->A termeléshez hozzá szeretnéd adni a faluban levő nyersanyagokat?" << RESET << endl;
    cout << GRAY << "#Nem esetében nyomj '0'-át!" << RESET << endl;
    cout << GRAY << "#Igen esetében nyomj '1'-et!" << RESET << endl;
    cout << GRAY << "Választásod:" << RESET;
    cin >> falubanlevonyersanyag;
    
        if (falubanlevonyersanyag == 0)
        {
            goto alapnyersanyagnelkul ;
        }
        else if (falubanlevonyersanyag == 1)
        {
    
    //Faluban lévő nyersanyagok megadása
    cout << BOLDRED << "->Add meg a faluban levő nyersanyagok mennyiségét:" << RESET << endl;
    cout << GRAY << "Fa:" << RESET;
    cin >> alapfa;
    cout << GRAY << "Agyag:" << RESET;
    cin >> alapagyag;
    cout << GRAY << "Vas:" << RESET;
    cin >> alapvas;
    
    alapnyersanyagnelkul :
    
    //Érmék számának megadása
    cout << BOLDRED << "->Add meg hány érme kell a nemes legyártásához:" << RESET;
    cin >> ermemennyiseg;
    
    //Nemes számának megadása
    cout << BOLDRED << "->Add meg hány nemest szeretnél hozzá legyártani:" << RESET;
    cin >> nemesmennyiseg;
    
    //Összesített nyersanyagszükséglet
    float osszesfa = (ermemennyiseg * ermefa) + (nemesfa * nemesmennyiseg);
    float osszesagyag = (ermemennyiseg * ermeagyag) + (nemesagyag * nemesmennyiseg);
    float osszesvas = (ermemennyiseg * ermevas) + (nemesvas * nemesmennyiseg);
    
    cout << GRAY << "#Szükséges idő/nyersanyagok a gyártáshoz:" << RESET << endl;
    cout << GRAY << "#----------------------------------------" << RESET << endl;
    
    //Összes szükséges fa és idő
    cout << BOLDBLUE << "Fa: " << RESET << (osszesfa - alapfa) << BOLDBLUE
    <<"    Idő(h): " << RESET << ((osszesfa - alapfa) / termelesfa) << BOLDBLUE << " --->(d): " << RESET << (((osszesfa - alapfa) / termelesfa) /24) << endl;
    
    //Összes szükséges agyag és idő
    cout << BOLDBLUE << "Agyag: " << RESET << (osszesagyag - alapagyag) << BOLDBLUE
    <<"    Idő(h): " << RESET << ((osszesagyag - alapagyag) / termelesagyag) << BOLDBLUE << " --->(d): " << RESET << (((osszesagyag - alapagyag) / termelesagyag) /24) << endl;
    
    //Összes szükséges vas és idő
    cout << BOLDBLUE << "Vas: " << RESET << (osszesvas - alapvas) << BOLDBLUE
    <<"    Idő(h): "<< RESET << ((osszesvas - alapvas) / termelesvas) << BOLDBLUE << " --->(d): " << RESET << (((osszesvas - alapvas) / termelesfa) /24) << endl;
    }
        else
        {
        cout << GRAY << "#Helytelen gomblenyomás, kérlek [0-1] közül válassz!" << RESET << endl;
    }
    cout << GRAY << "----------------------------------------" << RESET << endl;
    
    //Újraszámítás lehetőségének felajánlása
    cout << BOLDRED << "->Szeretnél új adatokat megadni ?" << RESET << endl;
    cout << GRAY << "#Nem esetében nyomj '0'-át!" << RESET << endl;
    cout << GRAY << "#Igen esetében nyomj '1'-et!" << RESET << endl;
    cin >> ujraszamitas;
    
    //Újraszámítás lehetőségei
        switch (ujraszamitas)
        {
        case 0 : cout << BOLDRED << "Helló!" << RESET << endl;
            break;
        case 1 : goto ujrakezdes;
            break;
        default: cout << GRAY << "#Helytelen gomblenyomás, kérlek [0-1] közül válassz!" << RESET << endl;
            goto ujrakezdes;
    }
    
    return 0;
}
