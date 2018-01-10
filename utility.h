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
using namespace std;

class utility {
public:
    bool confirm(void) throw(char);
    bool again(void) throw(char);
    bool backToMenu(void) throw (char);
    void formatName(char* keyWord);
    void allCaps(char * keyWord);
    void formatSentence(char * keyWord);
    char* copyArray(char* sourceWord);
    void clearArray(char* toClear);
    int mainMenu(void) throw(int);
    bool askUser(string toAsk) throw(char);
};


#endif //POKEDEX_UTILITY_H
