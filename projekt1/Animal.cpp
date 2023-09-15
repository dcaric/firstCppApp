//
//  Animal.cpp
//  projekt1
//
//  Created by Paola Caric on 28.08.2023..
//

#include "Animal.hpp"


void Animal::printTitle() {
    printf("I am animal \n");
    
}

void Animal::printNumOfLegs(){
    
    
}

Animal::Animal (string name, int age) {
    namePrivate = name;
    agePrivate = age ;
    
}

int Animal::showAge (){
    return agePrivate;
}


