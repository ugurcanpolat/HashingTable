/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project3
 
 * * * * * * * * * * * * * * * * * */

#include "p3char.h"
#include <cmath>

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
    key += lineNo*pow(10,determineNumberOfDigits(static_cast<int>(key)));
    key += pageNo*pow(10,determineNumberOfDigits(static_cast<int>(key)));
}

int BookCharacter::determineNumberOfDigits(int number) const {
    int numberOfDigits = 0;
    
    float fNumber = number;
    
    while(fNumber >= 1) {
        fNumber /= 10;
        numberOfDigits++;
    }
    return numberOfDigits;
}

unsigned long BookCharacter::getKey() const {
    return key;
}

char BookCharacter::getCharacter() const {
    return character;
}

void BookCharacter::setCharacter(char lookedUpCharacter) {
    character = lookedUpCharacter;
}
