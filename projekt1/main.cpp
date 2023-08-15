//
//  main.cpp
//  projekt1
//
//  Created by Paola Caric on 01.08.2023..
//

#include <iostream>
#include "Menu.hpp"
#include "GuessNum.hpp"
#include "Constants.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Menu MyMenu;
    string selectedItem = MyMenu.showMenu ({Constants::GUESS_NUMBER,Constants::CALCULATOR});
    //printf("%s \n", selectedItem.c_str());
    if (selectedItem == Constants::GUESS_NUMBER ) {
        GuessNum guessNum;
       // GuessNum guessNum = new GuessNum();
      //insert two number for min and max
        printf("Insert minimum and maximum: \n");
        int min, max;
        scanf("%d %d", &min, &max);
        printf("Congratulation you guessed the correct number %d! \n ", guessNum.playersNum(min, max));
    }
    
    return 0;
}

