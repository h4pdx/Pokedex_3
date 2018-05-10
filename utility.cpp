//
// Created by Ryan on 10/5/17.
//

#include "utility.h"

int utility::mainMenu() {
    try {
        int userInput = 0;
        cout << "\n + + Main Menu + + + +\n"
             << "\nPress (1) To Add a New Entry."
             << "\nPress (2) To Display All Entries."
             << "\nPress (0) to Exit.\n";
        do {
            cout << "\n >> Make a selection: ";
            cin >> userInput;
            cin.ignore(100, '\n');
            if (cin.fail()) {
                cout << "\nError - Enter a valid number.\n";
                cin.clear();
                cin.ignore();
                throw userInput;
            }
        } while (userInput < 0 || userInput > 2);
        return userInput;
    }
    catch (int) {
        return mainMenu();
    }
}

bool utility::askUser(string toAsk) {
    char response = 'n';
    try {
        cout << "\n >> " << toAsk << "? (y/n): ";
        cin >> response;
        cin.ignore(100, '\n');
        response = toupper(response);
        if (response != 'Y' && response != 'N') {
            cout << "\nError - enter a valid answer.";
            throw response;
        }
        if (response == 'Y') {
            return true;
        } else {
            return false;
        }
    } catch (char) {
        return askUser(toAsk);
    }
}

// Format inputs, for consistency in recording, searching, displaying
void utility::formatName(string& keyWord) {
    /*
    if (!keyWord)
        return;
    int keyWordLen = 0;
    keyWordLen = strlen(keyWord);
    */
    if (keyWord.length() != 0) {
        keyWord[0] = toupper(keyWord[0]);
        // loop through keyWord and properly capitalize/lowercase letters
        for (int i = 1; i < keyWord.length(); ++i) {
            if (keyWord[i-1] == ' ' || keyWord[i-1] == '-') {
                keyWord[i] = toupper(keyWord[i]);
            }
            else {
                keyWord[i] = tolower(keyWord[i]);
            }
            /*
            if (keyWord[i] == ' ') {
                keyWord[i+1] = toupper(keyWord[i+1]);
            }
             */
        }
        //cout << keyWord;
    }
}

void utility::allCaps(string& keyWord) {
    /*
    if (!keyWord)
        return;
    int keyWordLen = 0;
    keyWordLen = strlen(keyWord);
    */
    if (keyWord.length() != 0) {
        for (int i = 0; i < keyWord.length(); ++i) {
            keyWord[i] = toupper(keyWord[i]);
        }
    }
}

void utility::formatSentence(string& keyWord) {
    /*
    if (!keyWord)
        return;
    int keyWordLen = 0;
    keyWordLen = strlen(keyWord);
    */
    if (keyWord.length() != 0) {
        // capitalize 1st letter, then start loop after
        keyWord[0] = toupper(keyWord[0]);
        for (int i = 1; i < keyWord.length(); ++i) {
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

/*
char* utility::copyArray(char*toCopy) {
    if (toCopy != nullptr) {
        char * newWord = new char[strlen(toCopy) + 1];
        strcpy(newWord, toCopy);
        return newWord;
    } else {
        return nullptr;
    }
}

void utility::clearArray(char * toClear) {
    if (toClear != nullptr) {
        delete [] toClear;
        toClear = nullptr;
    }
    return;
}
*/
