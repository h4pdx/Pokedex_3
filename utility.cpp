//
// Created by Ryan on 10/5/17.
//

#include "utility.h"

int utility::mainMenu() throw(int) {
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

bool utility::again() throw(char) {
    char response = 'n';
    try {
        cout << "\n >> Again? (y/n): ";
        cin >> response;
        cin.ignore(100,'\n');
        response = toupper(response);
        if (response != 'Y' && response != 'N') {
            cout << "\nError - Enter a valid answer (y/n).";
            throw response;
        }
        if (response == 'Y') {
            return true;
        } else {
            return false;
        }
    }
    catch (char) {
        return again();
    }
}

bool utility::backToMenu() throw(char) {
    char response = 'n';
    try {
        cout << "\n >> Return to previous menu? (y/n): ";
        cin >> response;
        cin.ignore(100,'\n');
        response = toupper(response);
        if (response != 'Y' && response != 'N') {
            cout << "\nError - Enter a valid answer (y/n).";
            throw response;
        }
        if (response == 'Y') {
            return true;
        } else {
            return false;
        }
    }
    catch (char) {
        return backToMenu();
    }
}

bool utility::confirm() throw(char) {
    char response = 'n';
    try {
        cout << "\n >> Confirm? (y/n): ";
        cin >> response;
        cin.ignore(100, '\n');
        response = toupper(response);
        if (response != 'Y' && response != 'N') {
            cout << "\nError - Enter a valid answer (y/n).";
            throw response;
        }
        if (response == 'Y') {
            return true;
        } else {
            return false;
        }
    }
    catch (char) {
        return confirm();
    }
}

// Format inputs, for consistency in recording, searching, displaying
void utility::formatName(char * keyWord) {
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
            /*
            if (keyWord[i] == ' ') {
                keyWord[i+1] = toupper(keyWord[i+1]);
            }
             */
        }
        //cout << keyWord;
    }
}

void utility::allCaps(char *keyWord) {
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

void utility::formatSentence(char * keyWord) {
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

char* utility::copyArray(char * toCopy) {
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
        cout << "\nArray cleared";
    }
    return;
}
