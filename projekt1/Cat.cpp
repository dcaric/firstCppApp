//
//  Cat.cpp
//  projekt1
//
//  Created by Paola Caric on 28.08.2023..
//

#include "Cat.hpp"

Cat::Cat(string n, int a, bool whiteBlack) : Animal(n, a) {
    whiteOrBlack = whiteBlack;
}


string Cat::isWhiteOrBlack() {
    if (whiteOrBlack) return "White";
    else return "Black";
}

void Cat::printTitle() {
    printf("I am cat \n");
    
}
