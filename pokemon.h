//
// Created by Ryan on 7/14/17.
//

#ifndef POKEDEX_POKEMON_H
#define POKEDEX_POKEMON_H

/*
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;
 */

#include "utility.h"

const int NAME = 21;
const int DESC = 41;
const int BIO = 201;
/*locale loc;*/

class pokemon: public utility {

public:
    pokemon(void);
    pokemon(const pokemon& source);
    pokemon& operator = (const pokemon& source);

    friend bool operator == (const pokemon& cmp1, const pokemon& cmp2);
    friend bool operator == (const pokemon& cmp1, int cmp2);
    friend bool operator == (int cmp1, const pokemon& cmp2);

    friend bool operator != (const pokemon& cmp1, const pokemon& cmp2);
    friend bool operator != (const pokemon& cmp1, int cmp2);
    friend bool operator != (int cmp1, const pokemon& cmp2);

    friend bool operator < (const pokemon& cmp1, const pokemon& cmp2);
    friend bool operator < (const pokemon& cmp1, int cmp2);
    friend bool operator < (int cmp1, const pokemon& cmp2);

    friend bool operator > (const pokemon& cmp1, const pokemon& cmp2);
    friend bool operator > (const pokemon& cmp1, int cmp2);
    friend bool operator > (int cmp1, const pokemon& cmp2);

    friend bool operator <= (const pokemon& cmp1, const pokemon& cmp2);
    friend bool operator <= (const pokemon& cmp1, int cmp2);
    friend bool operator <= (int cmp1, const pokemon& cmp2);

    friend bool operator >= (const pokemon& cmp1, const pokemon& cmp2);
    friend bool operator >= (const pokemon& cmp1, int cmp2);
    friend bool operator >= (int cmp1, const pokemon& cmp2);

    ~pokemon(void);
    void clear(void);

    void create(void);
    void createField(string inputPrompt, char* userInput, int fieldLen) throw(char*);
    void createField(int& userInput) throw(int);

    void create(int number, char* name, char* desc, char* typeOne, char* typeTwo, char* bio);
    void copy(const pokemon& src);
    void display(void)const;
    bool retrieve(char* keyword, pokemon& found)const;
    pokemon* retrieve(char* keyword)const;
    bool retrieve(int key, pokemon& found) const;
    pokemon* retrieve(int key)const;
    int getNum(void)const;
    char* getName(void)const;
    bool validateType(char* toCheck);

private:
    int number;      // 025
    char * name;     // Pikachu
    char * desc;     // Thunder Mouse
    char * typeOne;  // Lighting
    char * typeTwo;  // Fairy
    char * bio;      // 1-2 sentences
    char ** pokemonTypes; // dynamic array of char*
};

struct node {
    node();
    ~node();
    explicit node(const pokemon& source);
    pokemon entry;
    node * left;
    node * right;
};
// class node
/*
class node: public pokemon {
public:
    node();
    node(node& source);

    explicit node(pokemon& source);
    ~node();
    node*& goLeft();
    node*& goRight();
    void setLeft(node* left);
    void setRight(node* right);
    bool isLeft();
    bool isRight();

private:
    node* left;
    node* right;
};
*/

#endif //POKEDEX_POKEMON_H
