//
//  Menu.hpp
//  projekt1
//
//  Created by Paola Caric on 04.08.2023..
//

#ifndef Menu_hpp
#define Menu_hpp
#include <string>
#include <list>

#include <stdio.h>
using namespace std;

class Menu {
    
public:
    //public je dostupno u dr klasama i mainu
    string showMenu (list<string>); //deklaracija funkcije showmenu, ulazni arg je lista stringova,a funk vrača samo jedan string
    /*
     tip podatka: int,string, double, float, void, bull....
     standarne funkcije: printf, scanf ILI moje funk koje ja izmisljan( showmenu),
     varijable: nalaze se kao argument funkcije, spremaju neke podatke nekih tipova
     logicke instrukcije: for, while,if,else....
    */
    
protected:
    //dostupno u ovoj klasi i klasama koje nasljeđuju ovu
    
    
    
private:
    //dostupno samo u ovoj klasi
};

#endif /* Menu_hpp */


