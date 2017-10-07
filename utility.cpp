//
// Created by Ryan on 10/5/17.
//

#include "utility.h"

bool utility::again() {
    bool again = false;
    char response = 'n';
    do {
        cout << "\n > Again? (y/n): ";
        cin >> response; cin.ignore(100, '\n');
        if (response == 'Y' || response == 'y')
            again = true;
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
    return again;
}

bool utility::confirm() {
    bool confirm = false;
    char response = 'n';
    do {
        cout << "\n > Confirm? (y/n): ";
        cin >> response; cin.ignore(100, '\n');
        if (response == 'Y' || response == 'y')
            confirm = true;
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
    return confirm;
}

bool utility::backToMenu() {
    bool back = false;
    char response = 'n';
    do {
        cout << "\n > Confirm? (y/n): ";
        cin >> response;
        if (response == 'Y' || response == 'y')
            back = true;
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
    return back;
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
