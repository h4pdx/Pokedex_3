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
    int menuItem = 0;
    do {
        menuItem = alolaDex.mainMenu();
        switch(menuItem) {
            case 1:
                do {
                    if (alolaDex.build())
                        cout << "\nEntry data added to Pokedex!";
                    else cout << "\nError - Entry Data not added to Pokedex.";
                } while (alolaDex.askUser("Again"));
                break;
            case 2:
                alolaDex.display();
                break;
            case 0:
                if (alolaDex.askUser("Confirm")) {
                    cout << "\nGotta catch 'em all!\n";
                    return 0;
                } else {
                    break;
                }
                break;
            default:
                cout << "\nEnter a valid number.";
                //menuItem = alolaDex.mainMenu();
                break;
        }
    } while (alolaDex.askUser("Back to Menu"));

    //cout << "\nDisplay Tree";
    return 0;
}
