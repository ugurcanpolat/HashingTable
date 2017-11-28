/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 main.cpp -o proj3
 
 * * * * * * * * * * * * * * * * * */

#include "p3list.h"

List::List() {
    characters.resize(SIZE); // Define the size of the container
}

void List::insert(const BookCharacter& newCharacter) {
    characters.push_back(newCharacter);
}

char List::lookup(const BookCharacter& lookUpCharacter) const {
    for(int counter = 0; counter < characters.size(); counter++) {
        if(characters[counter].getKey() == lookUpCharacter.getKey()) // Found
            return characters[counter].getCharacter(); // Return the character
    }
    return '\0'; // Not found
}
