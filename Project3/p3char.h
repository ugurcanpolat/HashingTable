/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project2
 
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
    int determineNumberOfDigits(int number) const;
public:
    BookCharacter(string read[]);
};

#endif /* p3char_h */
