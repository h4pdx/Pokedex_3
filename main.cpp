#include <iostream>
//#include "pokemon.h"
#include "pokedex.h"

int main() {

    pokemon newCatch;
    pokedex alolaDex;
    do {
        newCatch.create();
        newCatch.display();
        //cout << "\nInsert into tree";
        alolaDex.insert(newCatch);
    } while (alolaDex.again());
    //cout << "\nDisplay Tree";
    alolaDex.display();
    return 0;
}