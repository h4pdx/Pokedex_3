//
// Created by Ryan on 10/5/17.
//

#ifndef POKEDEX_UTILITY_H
#define POKEDEX_UTILITY_H

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class utility {
public:
    void formatName(string& keyWord);
    void allCaps(string& keyWord);
    void formatSentence(string& keyWord);
    /*
    char* copyArray(char* sourceWord);
    void clearArray(char* toClear);
    */
    int mainMenu(void);
    bool askUser(string toAsk);

};


#endif //POKEDEX_UTILITY_H
