//
// Created by Ryan on 9/28/17.
//

#ifndef POKEDEX_POKEDEX_H
#define POKEDEX_POKEDEX_H


#include "pokemon.h"

const int MAX_COUNT = 300;

class pokedex: public utility {
public:
    pokedex();
    ~pokedex();
    pokedex(const pokedex& source);
    pokedex& operator = (const pokedex& source);
    pokedex& operator += (const pokemon& toAdd);
    int retreive(node& found);
    void display(void)const;
    bool insert(const pokemon& toAdd);
    //int removeEntry();
    bool removeAll(void);
    //int copyAll(pokedex& source);
    int copyEntry(node& source);
    bool build(void);
    int getHeight(void)const;
    int balanceFactor(void)const;
    bool copyAll(const pokedex& source);


private:
    node * root;
    int entryCount;

    bool insert(const pokemon& toAdd, node*& root);
    void display(node * current)const;
    int getHeight(node * current)const;
    int balanceFactor(node * current)const;
    bool copyAll(node * source);
    int removeAll(node*& current);


};

#endif //POKEDEX_POKEDEX_H
