/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project3
 
 * * * * * * * * * * * * * * * * * */

#ifndef p3dict_h
#define p3dict_h

#define SIZE 131071

#include <cmath>

using namespace std;

class Dictionary {
  private:
    BookCharacter *characters;
    unsigned long hashing(unsigned long key) const;
    unsigned long probing(unsigned long hash, int i) const;
  public:
    Dictionary();
    ~Dictionary();
    void insert(const BookCharacter& newCharacter);
    void deleteItem();
    void lookup() const;
};

#endif /* p3dict_h */
