//
// Created by Ryan on 9/28/17.
//

#include "pokedex.h"

pokedex::pokedex() {
    entryCount = 0;
    root = nullptr;
}


pokedex::~pokedex() {
    //removeAll();
}

/*
pokedex::pokedex(pokedex& source) {
    copyAll(source);
}
*/
// wrapper for recursive insert
bool pokedex::insert(pokemon& toAdd) {
    bool success = false;
    success = insert(toAdd,this->root);
    return success;
}

// recursive insert function
bool pokedex::insert(pokemon& toAdd, node*& root) {
    bool success = false;
    if (!root) {
        root = new node(toAdd);
        root->left = root->right = nullptr;
        success = true;
        ++entryCount;
    }
    else {
        // sort left
        if (toAdd.getNum() < root->entry.getNum()){
            success = insert(toAdd, root->left);
        }
        // sort right
        else {
            success = insert(toAdd, root->right);
        }
    }
    return success;
}

// creates obj of pokemon class from user input, inserts into tree
bool pokedex::createEntry() {
    bool success = false;
    pokemon newCatch;
    do {
        newCatch.create(); // pokemon class data entry
        newCatch.display(); // display for user what they just entered
    } while (!confirm()); // do again if they press 'n' on confirm
    if (insert(newCatch)) // insert only when user confirms entry
        success = true; // report successful insert
    return success;
}

// inorder display wrapper
void pokedex::display() {
    return display(root);
}

void pokedex::display(node * root) {
    if (!root)
        return;
    display(root->left);
    root->entry.display();
    display(root->right);
}



