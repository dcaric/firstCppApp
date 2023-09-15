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
#include "Quiz.hpp"
#include "Animal.hpp"
#include "Cat.hpp"

using namespace std;


//main je posebna funkcija koja nije u klasi i sama za sebe je 
int main(int argc, const char * argv[]) {
    Menu MyMenu; //objekt MyMenu od klase menu
    string selectedItem = MyMenu.showMenu ({Constants::GUESS_NUMBER,Constants::QUIZ,Constants::CLASS}); //pozivanje showmenu priko objekta
    if (selectedItem == Constants::GUESS_NUMBER ) {
        GuessNum guessNum;
        printf("Insert minimum and maximum: \n");
        int min, max;
        scanf("%d %d", &min, &max);
        printf("Congratulation you guessed the correct number %d! \n ", guessNum.playersNum(min, max)); //

    }
    else if (selectedItem == Constants::QUIZ){
        Quiz quiz;
        printf("Choose the correct answer: \n");
        quiz.questions(quiz.http_get(Constants::QUIZ_URL));
        
    }
    else if (selectedItem == Constants::CLASS){
        Animal animal ("tonči",45);
        animal.printTitle();
        printf("Animal is %d old \n",animal.showAge());
        printf("\n========= \n");
        Cat cat("tonči",67, true);
        cat.printTitle();
        printf("Cat is %s \n",cat.isWhiteOrBlack().c_str());
        printf("Cat is %d old \n",cat.showAge());
    }

    return 0;
}

