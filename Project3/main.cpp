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
    ifstream input("ds-set-input.txt", ifstream::in); // Read
    
    if (!input.is_open()) {
        cout << endl << "Error opening input file." << endl << endl;
        return 0;
    }
    
    string line;
    Dictionary dictionary;
    
    while(!input.eof()) {
        getline(input, line); // Read the line
        
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
        
        // Create a new BookCharacter and insert it to
        BookCharacter new_book_character(read);
        dictionary.insert(new_book_character);
    }
    
    input.close();
    return 0;
}
