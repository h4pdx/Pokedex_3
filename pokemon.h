//
// Created by Ryan on 7/14/17.
//

#ifndef POKEDEX_POKEMON_H
#define POKEDEX_POKEMON_H

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
    void createField(string inputPrompt, string& userInput, int fieldLen);
    void createField(int& userInput);

    void create(int number, string name, string desc, string typeOne, string typeTwo, string bio);
    void copy(const pokemon& src);
    void display(void)const;
    bool retrieve(string keyword, pokemon& found)const;
    pokemon* retrieve(string keyword)const;
    bool retrieve(int key, pokemon& found) const;
    pokemon* retrieve(int key)const;
    bool validateType(string toCheck);
    string getName(void)const;
    string getTypeOne(void)const;
    string getTypeTwo(void)const;
    int getNum(void)const;


private:
    int number;
    /*      // 025
    char * name;     // Pikachu
    char * desc;     // Thunder Mouse
    char * typeOne;  // Lighting
    char * typeTwo;  // Fairy
    char * bio;      // 1-2 sentences
    */
    string name;     // Pikachu
    string desc;     // Thunder Mouse
    string typeOne;  // Lighting
    string typeTwo;  // Fairy
    string bio;      // 1-2 sentences
    //char ** pokemonTypes; // dynamic array of char*
};

struct node {
    node();
    ~node();
    explicit node(const pokemon& source);
    pokemon entry;
    node * left;
    node * right;
};

struct pokemonTypes {
  pokemonTypes();
  ~pokemonTypes();
  vector<string> types;
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
