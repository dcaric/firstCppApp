//
//  calculator.cpp
//  projekt1
//
//  Created by Paola Caric on 02.08.2023..
//

#include "Quiz.hpp"
#include "Constants.hpp"


/*
 The purpose of this function is to be used as a callback for libcurl when data is received from an HTTP request. The primary task is to collect (or "write") this data somewhere so it can be processed or stored. This function gets called multiple times by libcurl - each time a "chunk" of data is received.
 
 The function returns the number of bytes taken care of. If this does not match the amount passed to your function, it'll signal an error to libcurl.
 
 void* contents: A pointer to the actual data that's been received. It can be a chunk of an HTML page, JSON data, or any other type of data you're fetching.
 size_t size: This is always 1 for this context.
 size_t nmemb: The number of bytes in the contents buffer. It tells us the size of the chunk received.
 void* userp: A user pointer. This allows us to pass custom data to the callback function. In your case, you're passing a pointer to a std::string (readBuffer), which will store the fetched data.
 
 */
size_t Quiz::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// PUBLIC:

/**
 Makes GET request
 This function's purpose is to make an HTTP GET request to the provided URL and return the resulting data (in your case, presumably JSON data).
 
 CURL* curl;: Declare a pointer to a CURL object. This object holds a lot of state and options for the transfer.
 CURLcode res;: This type is an enumeration, and it will hold the result code of the curl_easy_perform function.
 string readBuffer;: This is the string where the fetched data will be stored.
 curl_easy_init(): Initializes a session and returns a CURL handle that you'll use for other libcurl operations.
 The next block of code sets various options for the libcurl transfer:

 CURLOPT_URL sets the URL you want to fetch.
 CURLOPT_WRITEFUNCTION tells libcurl which function to call when there's data to write/save.
 CURLOPT_WRITEDATA is the user pointer that will be passed to the write function; in this case, a pointer to readBuffer.
 
 @param url which will be fetched
 @return JSON as a string
 */




//httpget prima string koji je zap link (url) di se nalazi ona sva pitanja (file) koja uzima i vraca u obliku velikog stringa
string Quiz::http_get(const string& url) {
    CURL* curl;
    CURLcode response;
    string readBuffer;


    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        // performs the transfer (makes the HTTP GET request).
        response = curl_easy_perform(curl);
        cout << "respons:" << response << endl;
        
        if(response != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(response) << endl;
        }
        curl_easy_cleanup(curl);
    }
    
    return readBuffer; // returns the fetched data, returns the raw JSON data
    
}

/*vector<Task> Quiz::parseQuestionsOld (const string& data){
    vector<Task> questionList;
    
    json myJason = json::parse(data);

    for (const auto& block : myJason){
        Task t;
        t.question = block ["question"].get<string>();
        t.options ['A'] = block ["A"].get<string>();
        t.options ['B'] = block ["B"].get<string>();
        t.options ['C'] = block ["C"].get<string>();
        t.options ['D'] = block ["D"].get<string>();
        t.answer = block ["answer"].get<char>();
        
        questionList.push_back(t);
    }
    
    return questionList;
}*/


//funkcija parse prima string data (u kojem je onaj veliki string s linka) i vraca listu tipa Task (slozeni podatak)
vector<Task> Quiz::parseQuestions(const string& data) {
    vector<Task> questionsList; //pomocna lista
    
    
    /*
     parsiranje (sjecaknje) na blokove velikog stringa
     */
    Document myJason;
    myJason.Parse(data.c_str());
    
    //for (const auto& block : myJason){
    for (int i = 0; i < myJason.Size(); i++) {
        const auto& block = myJason[i];

        Task t;
        t.question = block["question"].GetString();
        t.options['A'] = block["A"].GetString(); // GetSring() is same as Get<string>()
        t.options['B'] = block["B"].GetString();
        t.options['C'] = block["C"].GetString();
        t.options['D'] = block["D"].GetString();
        t.answer = block["answer"].GetString()[0];

        questionsList.push_back(t);
    }

    return questionsList; //vracamo listu podijeljenu u blokove tipa task
}


//glavna funkija Questions koja igracu prezentira pitanje po pitanje
void Quiz::questions (const string& data) {
    vector<Task> questions = parseQuestions(data);
    
    
    for (const auto& examiner : questions){
        printf("%s \n", examiner.question.c_str());
        for (const auto& lines : examiner.options){
            printf("%c.  %s \n", lines.first,lines.second.c_str());
        }
        char myAns;
        scanf(" %c", &myAns);
        myAns = toupper(myAns); // nije bitno jel upisen malo il veliko slovo (stavlja uvik u velika slova)
        
        if (myAns != examiner.answer){
            printf("Wrong answer. \n");
        }
        else {
            printf("Congratulations! \n");
        }
        printf("\n");
    }
    
}
