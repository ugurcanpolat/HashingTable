/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project3
 
 * * * * * * * * * * * * * * * * * */

#include "p3char.h"

using namespace std;

BookCharacter::BookCharacter() {
    pageNo = lineNo = index = -1;
    character = '\0';
    key = 0;
}

BookCharacter::BookCharacter(string read[]) {
    pageNo = stoi(read[0]);
    lineNo = stoi(read[1]);
    index = stoi(read[2]);
    character = read[3][0];
    
    key = index;
    key += lineNo*100;
    key += pageNo*10000;
    read[0] = "s";
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
