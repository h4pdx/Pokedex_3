//
// Created by Ryan on 9/28/17.
//

#ifndef POKEDEX_POKEDEX_H
#define POKEDEX_POKEDEX_H


#include "pokemon.h"

const int MAX_COUNT = 300;

class pokedex: public utility {
public:
    pokedex(void);
    ~pokedex(void);
    pokedex(const pokedex& source);
    pokedex& operator = (const pokedex& source);
    pokedex& operator += (const pokemon& toAdd);
    int retreive(node& found);
    void display(void)const;
    bool insert(const pokemon& toAdd);
    //int removeEntry();
    bool removeAll(void);
    int copyEntry(node& source);
    bool build(void);
    int getHeight(void)const;
    int getBalanceFactor(void)const;
    bool copyAll(const pokedex& source);
    bool contains(const pokemon& toCheck);
    //bool isEmpty();
    int balanceAll(void);

private:
    node * root;
    int entryCount;

    bool insert(const pokemon& toAdd, node*& root);
    void display(node * current)const;
    int getHeight(node * current)const;
    int getBalanceFactor(node * current)const;
    bool copyAll(node * source);
    int removeAll(node*& current);
    bool contains(const pokemon& toCheck, node* root);

    int balanceAll(node*& root);
    int rotateLeft(node*& root);
    int rotateLeftLeft(node*& root);
    int rotateRight(node*& root);
    int rotateRightRight(node*& root);

};

#endif //POKEDEX_POKEDEX_H
