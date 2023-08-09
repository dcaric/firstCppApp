//
//  Menu.cpp
//  projekt1
//
//  Created by Paola Caric on 04.08.2023..
//

#include "Menu.hpp"
using namespace std;


string Menu::showMenu (list<string> myList) {
    
    myList.push_front("EXIT");
    
    printf ("menu \n");
    printf ("======== \n");
    int i = 0;
    for (string& worker : myList) {
        printf("%d. %s \n", i, worker.c_str());
        i ++;
    }

    printf ("======== \n");
    int selectedNum;
    scanf("%d", &selectedNum);
    
    int index = 0;
    list<string>::const_iterator jumper = myList.begin ();
    while (jumper != myList.end()) {
        if (index == selectedNum) return *jumper ;
        jumper ++;
        index ++;
    }
    return "Not found";
}

