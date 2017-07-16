//
// Created by Ryan on 7/14/17.
//

#ifndef POKEDEX_POKEMON_H
#define POKEDEX_POKEMON_H

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;


class pokemon {

public:
    pokemon();
    pokemon(pokemon& source);
    pokemon& operator = (pokemon& source);
    ~pokemon();

    bool create();
    bool create(int number, string name, string desc, string typeOne, string typeTwo, string bio);
    bool copy(pokemon& source);
    void display();
    bool retrieve();



private:
    int number; // 025
    string name; // Pikachu
    string desc;    // Thunder Mouse
    string typeOne; // Lighting
    string typeTwo; // Fairy
    string bio; // two-three sentences
};


#endif //POKEDEX_POKEMON_H
