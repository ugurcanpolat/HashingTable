/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project3
 
 * * * * * * * * * * * * * * * * * */

#include <iostream> // cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <string> // string

#include "p3char.cpp"
#include "p3dict.cpp"
#include "p3list.cpp"

using namespace std;

int main() {
    ifstream inputFile("ds-set-input.txt", ifstream::in); // Read
    
    if (!inputFile.is_open()) {
        cout << endl << "Error opening input file." << endl << endl;
        return 0;
    }
    
    string line;
    Dictionary dictionary;
    List list;
    
    while(!inputFile.eof()) {
        getline(inputFile, line); // Read the line
        
        // If line is empty, no need to take action
        if(line.empty()) break;
        
        // Create stringstream to parse with ','
        stringstream linestream(line);
        
        string read[4];
        
        // Parse the line
        getline(linestream, read[0], '\t');
        getline(linestream, read[1], '\t');
        getline(linestream, read[2], '\t');
        linestream >> read[3];
        
        // Create a new BookCharacter
        BookCharacter new_book_character(read);
        dictionary.insert(new_book_character);
        list.insert(new_book_character);
    }
    inputFile.close();
    
    ifstream lookupFile("ds-set-lookup.txt", ifstream::in); // Read
    
    if (!lookupFile.is_open()) {
        cout << endl << "Error opening lookup file." << endl << endl;
        return 0;
    }
    
    Dictionary lookupDictionary;
    List lookupList;
    
    while(!lookupFile.eof()) {
        getline(lookupFile, line); // Read the line
        
        // If line is empty, no need to take action
        if(line.empty()) break;
        
        // Create stringstream to parse with ','
        stringstream linestream(line);
        
        string read[4];
        
        // Parse the line
        getline(linestream, read[0], '\t');
        getline(linestream, read[1], '\t');
        linestream >> read[2];
        
        // Create a new BookCharacter
        BookCharacter new_book_character(read);
        
        char chr = dictionary.lookup(new_book_character);
        read[3] = chr;
        lookupDictionary.insert(new_book_character);
        
        chr = list.lookup(new_book_character);
        read[3] = chr;
        lookupList.insert(new_book_character);
    }
    lookupFile.close();
    
    return 0;
}
