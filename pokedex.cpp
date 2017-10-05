//
// Created by Ryan on 9/28/17.
//

#include "pokedex.h"

pokedex::pokedex() {
    entryCount = 0;
    root = nullptr;
}

pokedex::~pokedex() {
    removeAll();
}

pokedex::pokedex(pokedex& source) {
    copyAll(source);
}


// wrapper for recursive insert
int pokedex::insert(pokemon& toAdd) {
    int success = 0;
    success = insert(toAdd,this->root);
    return success;
}

// recursive insert function
int pokedex::insert(pokemon& toAdd, node*& root) {
    int success = 0;
    if (!root) {
        root = new node(toAdd);
        root->left = root->right = nullptr;
        ++success;
    }
    else {
        // sort left
        if (toAdd.getNum() < root->entry.getNum()){
            success += insert(toAdd, root->left);
        }
        else {
            success += insert(toAdd, root->right);
        }
    }
    return success;
}


void pokedex::display() {
    return display(root);
}

void pokedex::display(node * root) {
    
}



