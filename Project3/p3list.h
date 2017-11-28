/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 main.cpp -o proj3
 
 * * * * * * * * * * * * * * * * * */

#ifndef p3list_h
#define p3list_h

#include <vector>

#define SIZE 131071

using namespace std;

class List {
private:
    vector<BookCharacter> characters;
public:
    List();
    void insert(const BookCharacter& newCharacter);
    char lookup(const BookCharacter& lookUpCharacter) const;
};

#endif /* p3list_h */
