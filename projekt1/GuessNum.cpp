//
//  GuessNum.cpp
//  projekt1
//
//  Created by Paola Caric on 11.08.2023..
//

#include "GuessNum.hpp"
#include <iostream>
#include <random>


using namespace std;
 
/*GuessNum::GuessNum (){
    printf("konstruktor \n");
}
GuessNum::~GuessNum (){
    printf("destruktor \n");
}*/
int GuessNum::randomNum(int min, int max){

    
    random_device rd; //generira neki random stvar
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(min, max);
    return distribution(gen);

}

int GuessNum::playersNum (int min, int max){
    
    int rd = randomNum(min, max); //funk randomnum izabere sluc br izmedu min i max
    int  chosenNum;
    printf("Guess a random number \n");
    scanf("%d", &chosenNum);
    if ( chosenNum == rd){
        printf("You guessed the number! \n");
    }
    while (chosenNum != rd) {
        if (chosenNum < rd ) {
            printf("The number you wrote is less then mine. Guess again. \n");
        }
        else if (chosenNum > rd) {
            printf("The number you wrote is greater then mine. Guess again. \n");
        }
        else if ( chosenNum == rd){
            printf("You guessed the number! \n");
        }
        scanf("%d", &chosenNum);
    }
    return chosenNum;
}

    

