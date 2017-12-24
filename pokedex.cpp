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
bool pokedex::insert(const pokemon& toAdd) {
    bool success = false;
    success = insert(toAdd,this->root);
    return success;
}

// recursive insert function
bool pokedex::insert(const pokemon& toAdd, node*& root) {
    bool success = false;
    if (!root) {
        root = new node(toAdd);
        //root->left = root->right = nullptr; // possibly redundant
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
bool pokedex::build() {
    bool success = false;
    pokemon newCatch;
    do {
        newCatch.create(); // pokemon class data entry
        newCatch.display(); // display for user what they just entered
    } while (!confirm()); // do again if they press 'n' on confirm
    if (insert(newCatch)) {
        success = true; // report successful insert
    }
    return success;
}

// inorder display wrapper
void pokedex::display()const {
    if (!entryCount) {
        cout << "\nNothing to display, Pokédex is empty!";
        return;
    } else {
        cout << "\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
        return display((*this).root);
    }
}

// recursive, in-order display
void pokedex::display(node * current)const {
    if (!current) {
        return;
    }
    display(current->left);
    current->entry.display(); // pokemon class display function
    cout << "\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; //
    display(current->right);
}

/*
bool pokedex::copyAll(pokedex& source) {
    bool success = copyAll(this->root, source.root);
    if (success) {
        this->entryCount = source.entryCount;
    }
    return success;
}

bool pokedex::copyAll(node*& dest, node * source) {
    bool success = false;
    if (!source) {
        dest = nullptr;
    } else {
        dest = new node(source);
        success = true;
        success = copyAll(dest->left, source->left);
        success = copyAll(dest->right, source->right);
        //return true;
    }
    return success;
}
*/

bool pokedex::copyAll(const pokedex& source) {
    bool success = copyAll(source.root);
    if (success) {
        this->entryCount = source.entryCount;
    }
    return success;
}

bool pokedex::copyAll(node * source) {
    if (!source) {
        return false;
    }
    bool success = false;
    if (this->insert(source->entry)) {
        success = true;
    }
    success = copyAll(source->left);
    success = copyAll(source->right);
    return success;
}

// determine height of entire tree
int pokedex::getHeight()const {
    return getHeight((*this).root);
}

// determine height of supplied argument's subtree
int pokedex::getHeight(node * current)const {
    if (!current) {
        return 0;
    }
    int leftHeight = (getHeight(current->left));
    int rightHeight = (getHeight(current->right));
    int height = (max(leftHeight, rightHeight) + 1);
    return height;
}

// returns balance of entire tree
int pokedex::balanceFactor()const {
    return (*this).balanceFactor((*this).root);
}

// returns balance factor supplied argument's subtree
// >0 == left-heavy, 0 == balanced, <0 == right-heavy
int pokedex::balanceFactor(node * current)const {
    if (!current) {
        return 0;
    }
    /*
    int leftHeight = getHeight(current->left);
    int rightHeight = getHeight(current->right);
    int balance = leftHeight - rightHeight;
    return balance;
    */
    int balance = 0;
    balance += getHeight(current->left);
    balance -= getHeight(current->right);
    return balance;
}
