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


pokedex::pokedex(const pokedex& source) {
    this->copyAll(source);
}

pokedex& pokedex::operator = (const pokedex& source) {
    if (this == &source) {
        return (*this);
    }
    this->removeAll();
    this->copyAll(source);
    this->balanceAll();
    return (*this);
}

pokedex& pokedex::operator += (const pokemon& toAdd) {
    if (this->insert(toAdd)) {
        return (*this);
    }
    return (*this);
}

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
        root->left = root->right = nullptr; // possibly redundant
        success = true;
        ++entryCount; // not job of this function?
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
    cout << "\nBuild your Pokédex: Enter the details of a New Entry!";
    do {
        newCatch.create(); // pokemon class data entry
        newCatch.display(); // display for user what they just entered
    } while (!confirm()); // do again if they press 'n' on confirm
    if (this->insert(newCatch)) {
        //++this->entryCount; // is it not insert's job to keep count? just insert
        success = true; // report successful insert
    }
    // only need to balance if the pokedex is large enough
    if (this->entryCount >= 3) {
        cout << "\nSorting Pokédex Entries...";
        if (!this->balanceAll()) {
            cout << "\nPokédex not sorted.";
        } else {
            cout << "\nPokédex Sorted!";
        }
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
        return display(this->root);
    }
}

// recursive, in-order display
void pokedex::display(node* current)const {
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

// return false if object not found
bool pokedex::contains(pokemon& toCheck) {
    return contains(toCheck, this->root);
}

bool pokedex::contains(pokemon& toCheck, node* root) {
    if (!root) {
        return false;
    }
    bool isContained = false;
    if (toCheck == root->entry) { // overloaded pokemon ==
        isContained = true;
        //return isContained;
    }
    // only recurse further if contained == false, possibly still one out there to find
    // otherwise just return upward
    if (!isContained) {
        isContained = contains(toCheck, root->left);
    }
    if (!isContained) {
        isContained = contains(toCheck, root->right);
    }
    return isContained;
}

bool pokedex::copyAll(const pokedex& source) {
    bool success = copyAll(source.root);
    if (success) {
        (*this).entryCount = source.entryCount;
        success = this->balanceAll();
    }
    return success;
}

// traverse source tree and call this->insert using the source tree as arguments
bool pokedex::copyAll(node * source) {
    if (!source) {
        return false;
    }
    bool success = false;
    if (this->insert(source->entry)) {
        success = true; // should catch true all the way back to the calling routine
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
int pokedex::getBalanceFactor()const {
    return (*this).getBalanceFactor((*this).root);
}

// returns balance factor supplied argument's subtree
// >0 == left-heavy, 0 == balanced, <0 == right-heavy
int pokedex::getBalanceFactor(node * current)const {
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

bool pokedex::removeAll() {
    //int counter = removeAll(this->root);
    // if the tally of removed objects equals entryCount,
    // all items were successfully removed
    if (removeAll(this->root) == this->entryCount) {
        this->entryCount = 0; // reset tree count to 0
        return true; // all objects removed
    } else {
        return false;
    }
}

int pokedex::removeAll(node*& current) {
    if (!current) {
        return 0;
    }
    int counter = 0;
    counter += removeAll(current->left) + removeAll(current->right);
    if (current) {
        delete current;
        current = nullptr;
        ++counter;
    }
    return counter;
}

// balances entire tree
int pokedex::balanceAll() {
    return balanceAll(this->root); // balances from the top, down
}

// balances starting from the argument node/pokemon
int pokedex::balanceAll(node*& current) {
    if (!current) {
        return 0;
    }
    int counter = 0;
    counter += balanceAll(current->left) + balanceAll(current->right);
    int balanceFactor = getBalanceFactor(current);
    // determine rotation based on balanceFactor
    // left-heavy
    if (balanceFactor >= 2) {
        int leftBal = getBalanceFactor(current->left);
        if (leftBal >= 1) {
            counter += rotateLeft(current);
        } else {
            counter += rotateLeftLeft(current);
        }
    }
    // right heavy
    else if (balanceFactor <= -2) {
        int rightBal = getBalanceFactor(current->right);
        if (rightBal <= -1) {
            counter += rotateRight(current);
        } else {
            counter += rotateRightRight(current);
        }
    }
    return counter;
}

int pokedex::rotateRightRight(node*& root) {
    if (!root || !root->left || !root->right) {
        return 0;
    }
    node * oldRoot = root; // current invocation of root
    node * hold = oldRoot->right; // hold root's right subtree
    node * newRoot = hold->left; // hold's smaller subtree, new root
    if (newRoot) {
        oldRoot->right = newRoot->left; // adopt new root's smaller subtree
        hold->left = newRoot->right; // adopt new root's left subtree
        newRoot->right = hold; // new root can now adopt, hold is larger value subtree
        newRoot->left = oldRoot; // adopt old root as smaller value subtree
        root = newRoot; // set current invocation of root to rearranged node
        return 1;
    } else {
        return 0;
    }
}

int pokedex::rotateRight(node*& root) {
    if (!root || !root->left || !root->right) {
        return 0;
    }
    node * oldRoot = root; // will be swapped
    node * newRoot = oldRoot->right; // larger value sub tree
    if (newRoot) {
        oldRoot->right = newRoot->left; // adopt as new larger value subtree
        newRoot->left = oldRoot; // adopt old root as lesser value subtree
        root = newRoot; // reassign root
        return 1;
    } else {
        return 0;
    }
}

int pokedex::rotateLeftLeft(node*& root) {
    if (!root || !root->left || !root->right) {
        return 0; // return false if there are no children either
    }
    node * oldRoot = root;
    node * hold = oldRoot->left;
    node * newRoot = hold->right;
    if (newRoot) {
        oldRoot->left = newRoot->right;
        hold->right = newRoot->left;
        newRoot->left = hold;
        newRoot->right = oldRoot;
        root = newRoot;
        return 1;
    } else {
        return 0;
    }
}

int pokedex::rotateLeft(node*& root) {
    if (!root || !root->left || !root->right) {
        return 0;
    }
    node * oldRoot = root;
    node * newRoot = oldRoot->left;
    if (newRoot) {
        oldRoot->left = newRoot->right;
        newRoot->right = oldRoot;
        root = newRoot;
        return 1;
    } else {
        return 0;
    }
}
