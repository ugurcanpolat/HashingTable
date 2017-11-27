/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 main.cpp -o proj3
 
 * * * * * * * * * * * * * * * * * */

#include "p3dict.h"

Dictionary::Dictionary() {
    characters = new BookCharacter[SIZE];
}

Dictionary::~Dictionary() {
    delete [] characters;
}

unsigned long Dictionary::hashing(unsigned long key) const {
    double redundant;
    double hash = key * 0.618;
    hash = modf(hash, &redundant);
    hash *= SIZE;
    return static_cast<unsigned long>(hash);
}

unsigned long Dictionary::probing(unsigned long hash, int i) const {
    unsigned long nHash = hash + 7*i;
    nHash += (3*i*i) % SIZE;
    nHash %= SIZE;
    return nHash;
}

int Dictionary::insert(const BookCharacter& newCharacter) {
    unsigned long hash = hashing(newCharacter.getKey());
    
    int i = 1;
    while((*(characters+hash)).getKey() != 0) {
        hash = probing(hash, i);
        i++;
    }
        
    *(characters+hash) = newCharacter;
    return i-1;
}

void Dictionary::deleteItem(const BookCharacter& deleteCharacter) {
    unsigned long hash = hashing(deleteCharacter.getKey());
    
    int i = 1;
    while((*(characters+hash)).getKey() != 0) {
        if((*(characters+hash)).getKey() == deleteCharacter.getKey()) {
            BookCharacter empty;
            *(characters+hash) = empty;
        }
        
        hash = probing(hash, i);
        i++;
    }
}

char Dictionary::lookup(const BookCharacter& lookUpCharacter) const {
    unsigned long hash = hashing(lookUpCharacter.getKey());
    
    int i = 1;
    while((*(characters+hash)).getKey() != 0) {
        if((*(characters+hash)).getKey() == lookUpCharacter.getKey())
            return (*(characters+hash)).getCharacter();
        
        hash = probing(hash, i);
        i++;
    }
    return '\0';
}

