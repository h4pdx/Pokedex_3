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
    pokedex& operator = (const node& source);
    int retreive(node& found);
    void display();
    int insert(pokemon& toAdd);
    int removeEntry();
    int removeAll();
    int copyAll(pokedex& source);
    int copyEntry(node& source);


private:
    node * root;
    int entryCount;

    int insert(pokemon& toAdd, node*& root);
    void display(node * root);


};

#endif //POKEDEX_POKEDEX_H
