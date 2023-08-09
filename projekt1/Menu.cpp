//
//  Menu.cpp
//  projekt1
//
//  Created by Paola Caric on 04.08.2023..
//

#include "Menu.hpp"
using namespace std;
#include <vector>
#include <map>



string Menu::showMenu (list<string> myList) {
    
    myList.push_front("EXIT");
    
    //map<int, string> myMap;
    vector<string> myVector;
    
    
    printf ("menu \n");
    printf ("======== \n");
    int i = 0;
    for (string& worker : myList) {
        //myMap [i] = worker;
        myVector.push_back(worker);
        printf("%d. %s \n", i, worker.c_str());
        i ++;
    }

    printf ("======== \n");
    int selectedNum;
    scanf("%d", &selectedNum);
    if (selectedNum > myList.size()) return "Not found";
    
    return myVector [selectedNum];
    //return myMap [selectedNum] ;
}

