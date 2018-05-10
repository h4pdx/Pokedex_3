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
    //types = new char * [19]; // dynamic allocation of type array
    //types = new string[19];
    /*
    types[0] = new char[5];
    strcpy(types[0], "FIRE");
    */
    //types[0] = new string("FIRE");
    types.push_back("FIRE");
    types.push_back("WATER");
    types.push_back("GRASS");
    types.push_back("FLYING");
    types.push_back("NORMAL");
    types.push_back("FIGHTING");
    types.push_back("GHOST");
    types.push_back("POISON");
    types.push_back("DRAGON");
    types.push_back("FAIRY");
    types.push_back("ICE");
    types.push_back("PSYCHIC");
    types.push_back("ROCK");
    types.push_back("GROUND");
    types.push_back("DARK");
    types.push_back("BUG");
    types.push_back("ELECTRIC");
    types.push_back("STEEL");
    /*
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
    */
}

pokemonTypes::~pokemonTypes() {
    types.clear();
    /*
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
    */
}

pokemon::pokemon():
    number(0),
name(),
desc(),
typeOne(),
typeTwo(),
bio() {
    //pokemonTypes();
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
    /*
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
    */
   if (!name.empty()) {
       name.clear();
   }
   if (!desc.empty()) {
       desc.clear();
   }
   if (!typeOne.empty()) {
       typeOne.clear();
   }
   if (!typeTwo.empty()) {
       typeTwo.clear();
   }
   if (!bio.empty()) {
       bio.clear();
   }
}

string pokemon::getName(void)const {
  return this->name;
}

string pokemon::getTypeOne(void)const {
  return this->typeOne;
}

string pokemon::getTypeTwo(void)const {
  return this->typeTwo;
}

int pokemon::getNum(void)const {
  return this->number;
}

// Prompt user for input, repeat if invalid input entered
void pokemon::createField(string inputPrompt, string& userInput, int fieldLen) {
    try {
        cout << "\n >> " << inputPrompt << ": ";
        //cin.get(userInput, fieldLen, '\n');
        //cin.ignore(fieldLen, '\n');
        getline(cin, userInput);
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
void pokemon::create(void) {
    // numbers and char arrays for taking user input, then are passed off
    int number = 0;
    //char name[NAME], desc[DESC], typeOne[NAME], typeTwo[NAME], bio[BIO];
    string name, desc, typeOne, typeTwo, bio;
    // Pokemon Number
    createField(number);
    // Pokemon Name
    createField("Pokémon name", name, NAME);
    //cout << "\ncreate()::name = " << name;

    formatName(name);
    //cout << "\ncreate()::formateName(name) = " << name;
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
        } while(!validateType(typeTwo));
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
void pokemon::create(int number, string name, string desc, string typeOne, string typeTwo, string bio) {
    if (number != 0) {
        this->number = number;
    } else {
        this->number = 0;
    }
    // clear name ptr for use if it isn't already null
    //clearArray(this->name);
    // if the argument isn't null, then deep copy into calling object data members
    /*
    if (name) {
        this->name = copyArray(name);
    } else {
        this->name = nullptr;
    }
    */
    if (!name.empty()) {
        //this->name.copy(name, name.length(), 0);
        this->name = name;
    } else {
        this->name.clear();
    }
    //cout << "\ncreate(i,s,s,s,s,s)::this->name = " << this->name;
    // clear desc
    //clearArray(this->desc);
    // deep copy
    /*
    if (desc) {this->desc = copyArray(desc);}
    else {this->desc = nullptr;}
    */
    if (!desc.empty()) {
        this->desc = string(desc);
    } else {
        this->desc.clear();
    }
    // clear typeOne
    //clearArray(this->typeOne);
    // deep copy
    /*
    if (typeOne) {
        this->typeOne = copyArray(typeOne);
    } else {
        this->typeOne = nullptr;
    }
    */
   if (!typeOne.empty()) {
       this->typeOne = string(typeOne);
   } else {
       this->typeOne.clear();
   }
    // clear typeTwo
    //clearArray(this->typeTwo);
    // deep copy
    /*
    if (typeTwo != nullptr) {
        this->typeTwo = copyArray(typeTwo);
    } else {
        this->typeTwo = nullptr;
    }
    */
    if (!typeTwo.empty()) {
        this->typeTwo = string(typeTwo);
    } else {
        this->typeTwo.clear();
    }
    // clear bio
    //clearArray(this->bio);
    // deep copy
    /*
    if (bio) {
        this->bio = copyArray(bio);
    } else {
        this->bio = nullptr;
    }
    */
    if (!bio.empty()) {
        this->bio = string(bio);
    } else {
        this->bio.clear();
    }

}

// create(args) does a lot of work
void pokemon::copy(const pokemon& src) {
    this->create(src.number, src.name, src.desc, src.typeOne, src.typeTwo, src.bio);
}

// populate passed-in found object
bool pokemon::retrieve(string keyword, pokemon& found)const {
    bool match = false;
    if (this->name == keyword) {
        match = true;
        found.copy(*this); // populate empty passed-in obj
        //return match;
    }
    return match;
}

// search by name, return new object pointer
pokemon* pokemon::retrieve(string keyword)const {
    pokemon * found = nullptr;
    if (this->name == keyword) {
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
    //cout << "\ndisplay()::this->name = " << this->name << endl;
    if (!this->name.empty()) {
        cout << "\t" << this->name;
    } else {
        cout << "\tNo name on file. Please update Pokédex."; // if nullptr
    }
    // description "Mouse Pokemon"
    if (!this->desc.empty()) {
        cout << "\n\n" << this->desc;
    } else {
        cout << "\n\nNo description on file. Please update Pokedex."; // if nullptr
    }
    // type one - "Electric"
    if (!this->typeOne.empty()) {
        cout << "\t\t" << this->typeOne;
    } else {
        cout << "\t\t[NOT ON FILE]"; // if nullptr
    }
    // if type two has any substance
    // would it be better off to leave typeTwo as NULL if there is no 2nd type?
    if (!this->typeTwo.empty()) {
        if (this->typeTwo[0] != ' ') { // first letter will have been assigned
            cout << " / " << this->typeTwo; // otherwise display full typeTwo
        }
    } else {
        cout << ""; // if the ptr is NULL
    }
    if (!this->typeOne.empty() || !this->typeTwo.empty()) {
        cout << " Type.";
    }
    // display bio
    if (!this->bio.empty()) {
        cout << "\n" << this->bio; // display the brief bio under the other stats
    } else {
        cout << "\n\nNO BIO ON RECORD.\n"; // if nullptr
    }
}

bool pokemon::validateType(string toCheck) {
    pokemonTypes compareTo;
    for (int i = 0; i < 18; ++i) {
        /*
        if (!toCheck.compare(compareTo.types[i])) {
            return true;
        }
        */
       if (toCheck == compareTo.types[i]) {
           return true;
       }
    }
    cout << "\nInvalid Type! Try Again.";
    return false;
}
