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
    bool confirm();
    bool again();
    bool backToMenu();
    //bool mainMenu();
    void formatName(char* keyWord);
    void allCaps(char * keyWord);
    void formatSentence(char * keyWord);
    char* copyArray(char* sourceWord);

    int mainMenu();
};


#endif //POKEDEX_UTILITY_H
