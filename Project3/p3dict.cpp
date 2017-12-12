/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 main.cpp -o proj3
 
 * * * * * * * * * * * * * * * * * */

#include "p3dict.h"

Dictionary::Dictionary() {
    characters = new BookCharacter[SIZE]; // Allocate according to size
}

Dictionary::~Dictionary() {
    delete [] characters;
}

unsigned long Dictionary::hashing(unsigned long key) const {
    // h(key) = SIZE * (key * 0,618) (mod 1)
    double redundant; // unnecessary integer part
    double hash = key * 0.61803398875;
    hash = modf(hash, &redundant); // (mod 1) = fraction part
    hash *= SIZE;
    return static_cast<unsigned long>(hash);
}

unsigned long Dictionary::probing(unsigned long hash, int i) const {
    // Probing = (h+7i+3i^2)(mod SIZE)
    unsigned long nHash = hash + 7*i;
    nHash += (3*i*i) % SIZE;
    nHash %= SIZE; // In case if it exceeds the SIZE
    return nHash; // Return new hash
}

int Dictionary::insert(const BookCharacter& newCharacter) {
    // Get hash
    unsigned long hash = hashing(newCharacter.getKey());
    
    int i = 1;
    while((*(characters+hash)).getKey() != 0) { // Slot is not empty
        hash = probing(hash, i);
        i++;
    }
    
    // Insert new element to the position
    *(characters+hash) = newCharacter;
    return i-1; // Return number of collisions
}

char Dictionary::lookup(const BookCharacter& lookUpCharacter) const {
    // Get the hash according to lookup key
    unsigned long hash = hashing(lookUpCharacter.getKey());
    
    int i = 1;
    while((*(characters+hash)).getKey() != 0) { //
        if((*(characters+hash)).getKey() == lookUpCharacter.getKey()) // Found
            return (*(characters+hash)).getCharacter(); // Return character
        
        hash = probing(hash, i); // It is not the key we are looking for
        i++;
    }
    return '\0'; // Not found
}

