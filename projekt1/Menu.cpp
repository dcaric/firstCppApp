//
//  Menu.cpp
//  projekt1
//
//  Created by Paola Caric on 04.08.2023..
//

#include "Menu.hpp"
using namespace std;
#include <vector>
#include <map>


//cili kod je implementacija (izgradnja) funkcije showmenu


//myList je varijabla koja prima listu stringova i vratit ce string
string Menu::showMenu (list<string> myList) {
    
    
    myList.push_front("EXIT");
    //push front je funk koja prima string i stavlja ga na pocetak liste
    
    vector<string> myVector;
    //nova lista myVecto iako smo mogli bez nje
    //vektor (list ali mocnija) je lista stringova
    
    printf ("menu \n");
    printf ("======== \n");
    int i = 0;
    //log. instrukcija for: varijabla worker skace po listi myList sve dok ne dode do kraja
    for (string& worker : myList) {
        myVector.push_back(worker); //punimo listu
        printf("%d. %s \n", i, worker.c_str());
        i ++;
    }

    printf ("======== \n");
    int selectedNum;
    scanf("%d", &selectedNum);
    if (selectedNum > myList.size()) return "Not found";
    
    return myVector [selectedNum]; //vraca element iz liste koji san izabrala sa indeksom selectednum
}

