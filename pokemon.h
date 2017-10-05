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

const int NAME = 21;
const int DESC = 41;
const int BIO = 201;
/*locale loc;*/


class pokemon {

public:
    pokemon();
    pokemon(const pokemon& source);
    pokemon& operator = (const pokemon& source);

    ~pokemon();

    void create();
    void create(int number, char* name, char* desc, char* typeOne, char* typeTwo, char* bio);
    void copy(const pokemon& src);
    void display()const;
    bool retrieve(char* keyword, pokemon& found);
    void formatName(char* keyWord);
    void allCaps(char * keyWord);
    void formatSentence(char * keyWord);
    int getNum();

protected:
    int number;     // 025
    char* name;     // Pikachu
    char* desc;     // Thunder Mouse
    char* typeOne;  // Lighting
    char* typeTwo;  // Fairy
    char* bio;      // 1-2 sentences
};

struct node {
    node();
    ~node();
    node(pokemon& source);
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
