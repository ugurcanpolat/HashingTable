/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project3
 
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
    void deleteItem();
    void lookup() const;
};

#endif /* p3list_h */
