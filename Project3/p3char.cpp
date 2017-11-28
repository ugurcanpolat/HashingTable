/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 main.cpp -o proj3
 
 * * * * * * * * * * * * * * * * * */

#include "p3char.h"

using namespace std;

BookCharacter::BookCharacter() {
    // Create an empty BookCharacter object
    pageNo = lineNo = index = -1;
    character = '\0';
    key = 0;
}

BookCharacter::BookCharacter(string read[]) {
    pageNo = stoi(read[0]); // Convert to integer
    lineNo = stoi(read[1]); // Convert to integer
    index = stoi(read[2]); // Convert to integer
    character = read[3][0]; // Get the character
    
    // Key (pppLLii)
    key = index;
    key += lineNo*100;
    key += pageNo*10000;
}

unsigned long BookCharacter::getKey() const {
    return key;
}

int BookCharacter::getPageNo() const {
    return pageNo;
}

int BookCharacter::getLineNo() const {
    return lineNo;
}

int BookCharacter::getIndex() const {
    return index;
}

char BookCharacter::getCharacter() const {
    return character;
}

void BookCharacter::setCharacter(char lookedUpCharacter) {
    character = lookedUpCharacter;
}
