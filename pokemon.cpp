#include "pokemon.h"

node::node() {
    this->left = this->right = nullptr;
}

node::~node() {
    if (this->left) {
        this->left = nullptr;
    }
    if (this->right) {
        this->right = nullptr;
    }
}

node::node(const pokemon& source) {
    this->entry.copy(source);
    this->left = this->right = nullptr;
}

// should move this out of pokemon class. probably Util
pokemonTypes::pokemonTypes() {
    types = new char * [19]; // dynamic allocation of type array

    types[0] = new char[5];
    strcpy(types[0], "FIRE");

    types[1] = new char[6];
    strcpy(types[1], "WATER");

    types[2] = new char[6];
    strcpy(types[2], "GRASS");

    types[3] = new char[7];
    strcpy(types[3], "FLYING");

    types[4] = new char[7];
    strcpy(types[4], "NORMAL");

    types[5] = new char[9];
    strcpy(types[5], "FIGHTING");

    types[6] = new char[6];
    strcpy(types[6], "GHOST");

    types[7] = new char[7];
    strcpy(types[7], "POISON");

    types[8] = new char[7];
    strcpy(types[8], "DRAGON");

    types[9] = new char[6];
    strcpy(types[9], "FAIRY");

    types[10] = new char[4];
    strcpy(types[10], "ICE");

    types[11] = new char[5];
    strcpy(types[11], "ROCK");

    types[12] = new char[7];
    strcpy(types[12], "GROUND");

    types[13] = new char[8];
    strcpy(types[13], "PSYCHIC");

    types[14] = new char[5];
    strcpy(types[14], "DARK");

    types[15] = new char[4];
    strcpy(types[15], "BUG");

    types[16] = new char[9];
    strcpy(types[16], "ELECTRIC");

    types[17] = new char[6];
    strcpy(types[17], "STEEL");
}

pokemonTypes::~pokemonTypes() {
    for (int i = 0; i < 18; ++i) {
      if (types[i] != nullptr) {
        delete [] types[i];
        types[i] = nullptr;
      }
    }
    if (types != nullptr) {
      delete [] types;
      types = nullptr;
    }
}

pokemon::pokemon():
number(0),
name(nullptr),
desc(nullptr),
typeOne(nullptr),
typeTwo(nullptr),
bio(nullptr) {
    pokemonTypes();
}

pokemon::pokemon(const pokemon& source) {
    this->copy(source);
}

pokemon& pokemon::operator = (const pokemon& source) {
    if (this == &source) {
        return (*this);
    }
    this->clear();
    this->copy(source);
    return (*this);
}

// overload one, overload them all 
bool operator == (const pokemon& cmp1, const pokemon& cmp2) {
    if (cmp1.getNum() == cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator == (const pokemon& cmp1, int cmp2) {
    if (cmp1.getNum() == cmp2) {
        return true;
    } else {
        return false;
    }
}

bool operator == (int cmp1, const pokemon& cmp2) {
    if (cmp1 == cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator != (const pokemon& cmp1, const pokemon& cmp2) {
    if (cmp1.getNum() != cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator != (const pokemon& cmp1, int cmp2) {
    if (cmp1.getNum() != cmp2) {
        return true;
    } else {
        return false;
    }
}

bool operator != (int cmp1, const pokemon& cmp2) {
    if (cmp1 != cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator < (const pokemon& cmp1, const pokemon& cmp2) {
    if (cmp1.getNum() < cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator < (const pokemon& cmp1, int cmp2) {
    if (cmp1.getNum() < cmp2) {
        return true;
    } else {
        return false;
    }
}

bool operator < (int cmp1, const pokemon& cmp2) {
    if (cmp1 < cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator > (const pokemon& cmp1, const pokemon& cmp2) {
    if (cmp1.getNum() > cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator > (const pokemon& cmp1, int cmp2) {
    if (cmp1.getNum() > cmp2) {
        return true;
    } else {
        return false;
    }
}

bool operator > (int cmp1, const pokemon& cmp2) {
    if (cmp1 > cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator <= (const pokemon& cmp1, const pokemon& cmp2) {
    if (cmp1.getNum() <= cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator <= (const pokemon& cmp1, int cmp2) {
    if (cmp1.getNum() <= cmp2) {
        return true;
    } else {
        return false;
    }
}

bool operator <= (int cmp1, const pokemon& cmp2) {
    if (cmp1 <= cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator >= (const pokemon& cmp1, const pokemon& cmp2) {
    if (cmp1.getNum() >= cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

bool operator >= (const pokemon& cmp1, int cmp2) {
    if (cmp1.getNum() >= cmp2) {
        return true;
    } else {
        return false;
    }
}

bool operator >= (int cmp1, const pokemon& cmp2) {
    if (cmp1 >= cmp2.getNum()) {
        return true;
    } else {
        return false;
    }
}

pokemon::~pokemon() {
    this->clear();
}

void pokemon::clear() {
    if (name != nullptr) {
        delete [] name;
        name = nullptr;
    }
    if (desc != nullptr) {
        delete [] desc;
        desc = nullptr;
    }
    if (typeOne != nullptr) {
        delete [] typeOne;
        typeOne = nullptr;
    }
    if (typeTwo != nullptr) {
        delete [] typeTwo;
        typeTwo = nullptr;
    }
    if (bio != nullptr) {
        delete [] bio;
        bio = nullptr;
    }
}

char* pokemon::getName(void)const {
  return this->name;
}

char* pokemon::getTypeOne(void)const {
  return this->typeOne;
}

char* pokemon::getTypeTwo(void)const {
  return this->typeTwo;
}

int pokemon::getNum(void)const {
  return this->number;
}

// Prompt user for input, repeat if invalid input entered
void pokemon::createField(string inputPrompt, char* userInput, int fieldLen) {
    try {
        cout << "\n >> " << inputPrompt << ": ";
        cin.get(userInput, fieldLen, '\n');
        cin.ignore(fieldLen, '\n');
        if (!cin.fail()) {
            return;
        } else {
            throw userInput;
        }
    } catch(char*) {
        cin.clear();
        cin.ignore();
        cout << "\nError - invalid input. Try again.";
        return createField(inputPrompt, userInput, fieldLen);
    }
}

// remove C++14 and prior "throw(int)" specification,
// removed for C++17? need to kae sure
void pokemon::createField(int& userInput) {
    try {
        cout << "\n >> Enter Pokémon number: ";
        cin >> userInput;
        cin.ignore(100, '\n');
        if (cin.fail() || userInput <= 0 || userInput > 800) {
            throw userInput;
        } else {
            return;
        }
    } catch(int) {
        cin.clear();
        cin.ignore();
        cout << "\nError - invalid input. Try again.";
        return createField(userInput);
    }
}

// Take user input for the Pokemon data fields
void pokemon::create() {
    // numbers and char arrays for taking user input, then are passed off
    int number = 0;
    char name[NAME], desc[DESC], typeOne[NAME], typeTwo[NAME], bio[BIO];
    // Pokemon Number
    createField(number);
    // Pokemon Name
    createField("Pokémon name", name, NAME);
    formatName(name);
    // Description
    createField("Brief description", desc, DESC);
    formatName(desc);
    // Type 1
    do {
        createField("Type One", typeOne, NAME);
        allCaps(typeOne);
    } while (!validateType(typeOne)); // do over until valid type entered
    // Type 2 or not
    if (askUser("Does the Pokémon have a 2nd type")) {
        do {
            createField("Type Two", typeTwo, NAME);
            allCaps(typeTwo);
        } while (!validateType(typeTwo));
    } else {
        typeTwo[0] = ' ';
    }
    // Bio
    createField("A short bio", bio, BIO);
    formatSentence(bio);
    // pass populated arrays off for deep copy into calling object
    this->create(number, name, desc, typeOne, typeTwo, bio);
}

// does the legwork for allocating dynamic memory for the class
// reusable in several situations - create, copy, readFile
void pokemon::create(int number, char* name, char* desc, char* typeOne, char* typeTwo, char* bio) {
    if (number) {
        this->number = number;
    } else {
        this->number = 0;
    }
    // clear name ptr for use if it isn't already null
    clearArray(this->name);
    // if the argument isn't null, then deep copy into calling object data members
    if (name) {
        this->name = copyArray(name);
    } else {
        this->name = nullptr;
    }
    // clear desc
    clearArray(this->desc);
    // deep copy
    if (desc) {this->desc = copyArray(desc);} 
    else {this->desc = nullptr;}
    // clear typeOne
    clearArray(this->typeOne);
    // deep copy
    if (typeOne) {
        this->typeOne = copyArray(typeOne);
    } else {
        this->typeOne = nullptr;
    }
    // clear typeTwo
    clearArray(this->typeTwo);
    // deep copy
    if (typeTwo != nullptr) {
        this->typeTwo = copyArray(typeTwo);
    } else {
        this->typeTwo = nullptr;
    }
    // clear bio
    clearArray(this->bio);
    // deep copy
    if (bio) {
        this->bio = copyArray(bio);
    } else {
        this->bio = nullptr;
    }

}

// create(args) does a lot of work
void pokemon::copy(const pokemon& src) {
    this->create(src.number, src.name, src.desc, src.typeOne, src.typeTwo, src.bio);
}

// populate passed-in found object
bool pokemon::retrieve(char* keyword, pokemon& found)const {
    bool match = false;
    if (!strcmp(this->name, keyword)) {
        match = true;
        found.copy(*this); // populate empty passed-in obj
        //return match;
    }
    return match;
}

// search by name, return new object pointer
pokemon* pokemon::retrieve(char* keyword)const {
    pokemon * found = nullptr;
    if (!strcmp(this->name, keyword)) {
        found = new pokemon(*this); // searches will need to be followed by delete, in calling routine most likely
        //return found;
    }
    return found;
}

// search by number, populate passed-in object
bool pokemon::retrieve(int key, pokemon& found)const {
    bool match = false;
    if (this->number == key) {
        match = true;
        found.copy(*this);
    }
    return match;
}

// search by number, return nullptr or pointer value
pokemon* pokemon::retrieve(int key)const {
    pokemon* found = nullptr; // return null if not found
    if (this->number == key) {
        found = new pokemon(*this); // return new object
    }
    return found;
}

void pokemon::display()const {
    // Pokemon number "025"
    if (this->number > 0 && this->number < 10) {
        cout << "\n00" << this->number; // 004
    } // display numbers as always 3 digits
    else if (this->number > 9 && this->number < 100) {
        cout << "\n0" << this->number; // 023
    } // 3 digit numbers need no formatting
    else if (this->number > 100 && this->number < 799) {
        cout << "\n" << this->number; // 122
    }
    else { // 0 somehow or above any possible pokemon number -max 7xx
        cout << "\nNo number on file. Please update Pokedex."; // if number is 0 somehow
    }
    // Pokemon Name "Pikachu"
    if (this->name) {
        cout << "\t" << this->name;
    } else {
        cout << "\tNo name on file. Please update Pokédex."; // if nullptr
    }
    // description "Mouse Pokemon"
    if (this->desc) {
        cout << "\n\n" << this->desc;
    } else {
        cout << "\n\nNo description on file. Please update Pokedex."; // if nullptr
    }
    // type one - "Electric"
    if (this->typeOne) {
        cout << "\t\t" << this->typeOne;
    } else {
        cout << "\t\t[NOT ON FILE]"; // if nullptr
    }
    // if type two has any substance
    // would it be better off to leave typeTwo as NULL if there is no 2nd type?
    if (this->typeTwo) {
        if (this->typeTwo[0] != ' ') { // first letter will have been assigned
            cout << " / " << this->typeTwo; // otherwise display full typeTwo
        }
    } else {
        cout << " [NOT ON FILE]"; // if the ptr is NULL
    }
    if (this->typeOne || this->typeTwo) {
        cout << " Type.";
    }
    // display bio
    if (this->bio) {
        cout << "\n" << this->bio; // display the brief bio under the other stats
    } else {
        cout << "\n\nNO BIO ON RECORD.\n"; // if nullptr
    }

}

bool pokemon::validateType(char* toCheck) {
    //int len = strlen(this->pokemonTypes);
    pokemonTypes compareTo;
    for (int i = 0; i < 18; ++i) {
        if (!strcmp(toCheck, compareTo.types[i])) {
            return true;
        }
    }
    cout << "\nInvalid Type! Try Again.";
    return false;
}

/*
// Format inputs, for consistency in recording, searching, displaying
void pokemon::formatName(char * keyWord) {
if (!keyWord)
return;
int keyWordLen = 0;
keyWordLen = strlen(keyWord);
if (keyWordLen != 0) {
keyWord[0] = toupper(keyWord[0]);
// loop through keyWord and properly capitalize/lowercase letters
for (int i = 1; i < keyWordLen; ++i) {
if (keyWord[i-1] == ' ' || keyWord[i-1] == '-') {
keyWord[i] = toupper(keyWord[i]);
}
else {
keyWord[i] = tolower(keyWord[i]);
}

//if (keyWord[i] == ' ') {
//    keyWord[i+1] = toupper(keyWord[i+1]);
//}

}
//cout << keyWord;
}
}

void pokemon::allCaps(char *keyWord) {
if (!keyWord)
return;
int keyWordLen = 0;
keyWordLen = strlen(keyWord);
if (keyWordLen != 0) {
for (int i = 0; i < keyWordLen; ++i) {
keyWord[i] = toupper(keyWord[i]);
}
}
}

void pokemon::formatSentence(char * keyWord) {
if (!keyWord)
return;
int keyWordLen = 0;
keyWordLen = strlen(keyWord);
if (keyWordLen != 0) {
// capitalize 1st letter, then start loop after
keyWord[0] = toupper(keyWord[0]);
for (int i = 1; i < keyWordLen; ++i) {
// four cases for capitalize: after symbol (. , ! ?)
if (keyWord[i-2] == '.' ||
keyWord[i-2] == '?' ||
keyWord[i-2] == '!') {
if (keyWord[i-1] == ' ') {
keyWord[i] = toupper(keyWord[i]);
}
else {
keyWord[i-1] = toupper(keyWord[i-1]);
keyWord[i] = tolower(keyWord[i]);
}
}
else {
keyWord[i] = tolower(keyWord[i]);
}
}
}
}
*/
// getter func for given pokemon number
/*
int pokemon::getNum()const {
    return this->number;
}

char* pokemon::getName()const {
    return this->name;
}
*/
