#include <iostream>
//#include "pokemon.h"
#include "pokedex.h"

int main() {


    //pokemon newCatch;
    pokedex alolaDex;
    /*
    do {
        newCatch.create();
        newCatch.display();
        //cout << "\nInsert into tree";
        alolaDex.insert(newCatch);
    } while (alolaDex.again());
    */

    if (alolaDex.build())
        cout << "\nEntry data added to Pokedex!";
    else cout << "\nError - Entry Data not added to Pokedex.";
    //cout << "\nDisplay Tree";
    alolaDex.display();
    return 0;
}
