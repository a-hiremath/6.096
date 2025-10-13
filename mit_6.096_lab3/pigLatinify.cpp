//
// Created by adity on 10/13/2025.
//

#include <iostream>
#include "piglatin.h"
using namespace std;

string vowels = "ioaue";

string pigLatinify(string str) {

    int vLoc = str.find_first_of(vowels); // identifies the index of the first vowel in str

    int strLen = str.size() - 1; // set the size of str to a variable

    string firstConsonants = str.substr(0,vLoc);

    // cout << firstConsonants << endl << vLoc << endl << strLen;

    str.erase(0,vLoc);

    // cout << endl << str;

    string endSequence = firstConsonants.append("ay");

    str.append(endSequence);

    cout << endl << str;

    return str;
}

int main() {

    string message;
    cin >> message;

    pigLatinify(message);
}