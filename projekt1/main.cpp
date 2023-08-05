//
//  main.cpp
//  projekt1
//
//  Created by Paola Caric on 01.08.2023..
//

#include <iostream>
#include "Menu.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Menu MyMenu;
    int selectedNum = MyMenu.showMenu ();
    printf("%d",&selectedNum);
    return 0;
}
