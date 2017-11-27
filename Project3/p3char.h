/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project3
 
 * * * * * * * * * * * * * * * * * */

#ifndef p3char_h
#define p3char_h

#include <iostream>
#include <string>

using namespace std;

class BookCharacter {
private:
    int pageNo;
    int lineNo;
    int index;
    char character;
    unsigned long key;
public:
    BookCharacter();
    BookCharacter(string read[]);
    unsigned long getKey() const;
    int getPageNo() const;
    int getLineNo() const;
    int getIndex() const;
    char getCharacter() const;
    void setCharacter(char lookedUpCharacter);
};

#endif /* p3char_h */
