/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 main.cpp -o proj3
 
 * * * * * * * * * * * * * * * * * */

#ifndef p3dict_h
#define p3dict_h

#define SIZE 131071

#include <cmath> // modf

using namespace std;

class Dictionary {
  private:
    BookCharacter *characters;
    unsigned long hashing(unsigned long key) const;
    unsigned long probing(unsigned long hash, int i) const;
  public:
    Dictionary();
    ~Dictionary();
    int insert(const BookCharacter& newCharacter);
    void deleteItem(const BookCharacter& deleteCharacter);
    char lookup(const BookCharacter& lookUpCharacter) const;
};

#endif /* p3dict_h */
