/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project3
 
 * * * * * * * * * * * * * * * * * */

#include "p3list.h"

List::List() {
    characters.resize(SIZE);
}

void List::insert(const BookCharacter& newCharacter) {
    characters.push_back(newCharacter);
}

void List::deleteItem() {
    
}

void List::lookup() const {
    
}
