/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 main.cpp -o proj3
 
 * * * * * * * * * * * * * * * * * */

#include "p3list.h"

List::List() {
    characters.resize(SIZE);
}

void List::insert(const BookCharacter& newCharacter) {
    characters.push_back(newCharacter);
}

void List::deleteItem(const BookCharacter& deleteCharacter) {
    for(int counter = 0; counter < characters.capacity(); counter++) {
        if(characters[counter].getKey() == deleteCharacter.getKey()) {
            BookCharacter empty;
            characters[counter] = empty;
        }
    }
}

char List::lookup(const BookCharacter& lookUpCharacter) const {
    for(int counter = 0; counter < characters.capacity(); counter++) {
        if(characters[counter].getKey() == lookUpCharacter.getKey())
            return characters[counter].getCharacter();
    }
    return '\0';
}
