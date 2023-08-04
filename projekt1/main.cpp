//
//  main.cpp
//  projekt1
//
//  Created by Paola Caric on 01.08.2023..
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
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
    return 0;
}
