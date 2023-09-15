//
//  Animal.hpp
//  projekt1
//
//  Created by Paola Caric on 28.08.2023..
//

#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Animal {
    public:
    void printNumOfLegs();
    virtual void printTitle(); // virtual means it can be overriden in another class
    int showAge ();
    Animal (string name, int age); //konstruktor ,kreira objekt od ove klase ako nema defoltnog konst
    //Animal ();
    
    private:
    string namePrivate;
    int agePrivate ;
    
    
    protected:
    
    
};



#endif /* Animal_hpp */


