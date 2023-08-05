//
//  Menu.cpp
//  projekt1
//
//  Created by Paola Caric on 04.08.2023..
//

#include "Menu.hpp"


int Menu::showMenu () {
    
    int userselection = 1 ;
    printf ("menu \n");
    printf ("======== \n");
    printf ("1. GAME: guess number \n");
    printf ("0. EXIT \n");
    printf ("======== \n");
    
    while (userselection != 0) {
        scanf ("%d", &userselection);
        if (userselection == 1) {
            printf("Guess the number \n");
        }
        else if (userselection == 0){
            printf("You exited the app \n");
        }
        else {
            printf("incorrect number \n");
        }
    }
    return userselection ;
}
