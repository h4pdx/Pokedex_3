//
// Created by Ryan on 9/28/17.
//

#ifndef POKEDEX_POKEDEX_H
#define POKEDEX_POKEDEX_H


#include "pokemon.h"

const int MAX_COUNT = 300;

class pokedex {
public:
    pokedex();
    ~pokedex();
    pokedex(pokedex& source);
    pokedex& operator = (const pokemon& source);
    int retreive(pokemon& found);
    void display();
    int insert(node& toAdd);
    int removeEntry();
    int removeAll();


private:
    node * root;
    int entryCount;


};


#endif //POKEDEX_POKEDEX_H
