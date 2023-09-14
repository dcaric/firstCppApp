//
//  Cat.hpp
//  projekt1
//
//  Created by Paola Caric on 28.08.2023..
//

#ifndef Cat_hpp
#define Cat_hpp

#include <stdio.h>
#include "Animal.hpp"
using namespace std;

class Cat : public Animal {
    public:
    Cat(string, int, bool); // constructor for cat has all from Animal + one more variable bool
    string isWhiteOrBlack();
    void printTitle() override; // overriden method printTitle from Animal

    
    private:
    bool whiteOrBlack; // additional variable which Animal doesn't have
    
    
    protected:
    
    
};


#endif /* Cat_hpp */
