//
//  Calculator.hpp
//  projekt1
//
//  Created by Paola Caric on 02.08.2023..
//

#ifndef Quiz_hpp
#define Quiz_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <curl/curl.h>
/*
 In the project settings under Build Phases, expand Link Binary With Libraries.
 Click the + button to add a new library.
 In the dialog that appears, search for libcurl. You should find libcurl.tbd or a similar file. Select it and click Add.
*/

//#include <nlohmann/json.hpp>
#include "rapidjson/document.h"
#include "rapidjson/error/en.h"
// brew install nlohmann-json
/*
 Choose your target application.
 Go to the Build Settings tab.
 Search for Header Search Paths.
 Add /usr/local/include/ to the list.
*/



using namespace std;
//using json = nlohmann::json;
using namespace rapidjson;



/* {
 "question": "A flashing red traffic light signifies that a driver should do what?",
 "A": "stop",
 "B": "speed up",
 "C": "proceed with caution",
 "D": "honk the horn",
 "answer": "A"
} */



//task je slozeni tip podatka, mora pocet sa struct "ime"
struct Task{
    string question;
    map<char, string> options;
    char answer;
};

class Quiz {
    
    
public:
    string http_get(const string& url);
    void questions (const string& );
    
    
    
private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
    vector<Task> parseQuestions (const string& );
    vector<Task> parseQuestionsOld (const string& );

protected:
};
#endif /* Calculator_hpp */
