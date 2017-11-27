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
#include <vector> // vector

#include "p3char.cpp"
#include "p3dict.cpp"
#include "p3list.cpp"

using namespace std;

void writeToOutputFile(string fileName, vector<BookCharacter> data);

int main() {
    ifstream inputFile("ds-set-input.txt", ifstream::in); // Read
    
    if (!inputFile.is_open()) {
        cout << endl << "Error opening input file." << endl << endl;
        return 0;
    }
    
    string line;
    Dictionary dictionary;
    List list;
    
    int numberOfCollisions = 0;
    int numberOfItems = 1;
    float avgCollisionsFor3 = 0.0;
    float avgCollisionsFor4 = 0.0;
    float avgCollisionsFor5 = 0.0;
    float avgCollisionsOverall = 0.0;
    
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
        numberOfItems++;
        
        // Create a new BookCharacter
        BookCharacter new_book_character(read);
        numberOfCollisions += dictionary.insert(new_book_character);
        
        if(numberOfItems == 1000)
            avgCollisionsFor3 = static_cast<float>(static_cast<float>(numberOfCollisions) / static_cast<float>(numberOfItems));
        
        if(numberOfItems == 10000)
            avgCollisionsFor4 = static_cast<float>(static_cast<float>(numberOfCollisions) / static_cast<float>(numberOfItems));
        
        if(numberOfItems == 100000)
            avgCollisionsFor5 = static_cast<float>(static_cast<float>(numberOfCollisions) / static_cast<float>(numberOfItems));
        
        list.insert(new_book_character);
    }
    inputFile.close();
    
    avgCollisionsOverall = static_cast<float>(static_cast<float>(numberOfCollisions) / static_cast<float>(numberOfItems));
    
    ifstream lookupFile("ds-set-lookup.txt", ifstream::in); // Read
    
    if (!lookupFile.is_open()) {
        cout << endl << "Error opening lookup file." << endl << endl;
        return 0;
    }

    vector<BookCharacter> lookupDictionary;
    vector<BookCharacter> lookupList;
    
    while(!lookupFile.eof()) {
        getline(lookupFile, line); // Read the line
        
        // If line is empty, no need to take action
        if(line.empty()) break;
        
        // Create stringstream to parse with ','
        stringstream linestream(line);
        
        string read[3];
        
        // Parse the line
        getline(linestream, read[0], '\t');
        getline(linestream, read[1], '\t');
        linestream >> read[2];
        
        // Create a new BookCharacter
        BookCharacter new_book_character(read);
        
        char chr = dictionary.lookup(new_book_character);
        new_book_character.setCharacter(chr);
        lookupDictionary.push_back(new_book_character);
        
        chr = list.lookup(new_book_character);
        lookupList.push_back(new_book_character);
    }
    lookupFile.close();
    
    writeToOutputFile("ds-set-output-dict.txt", lookupDictionary);
    writeToOutputFile("ds-set-output-list.txt", lookupList);
    
    cout << endl << "\tDICTIONARY" << endl;
    cout << setprecision(5) << "\tInsertion finished after " << " seconds" << endl << endl;
    cout << setw(46) << left << "\tAverage number of collisions (first 1,000)" << "|";
    cout << setprecision(5) << setw(7) << right << avgCollisionsFor3 << endl;
    cout << setw(46) << left << "\tAverage number of collisions (first 10,000)" << "|";
    cout << setw(7) << right << avgCollisionsFor4 << endl;
    cout << setw(46) << left << "\tAverage number of collisions (first 100,000)" << "|";
    cout << setw(7) << right << avgCollisionsFor5 << endl;
    cout << setw(46) << left << "\tAverage number of collisions (overall)" << "|";
    cout << setw(7) << right <<avgCollisionsOverall << endl;
    cout << "\tLookup finished after " << " seconds." << endl;
    
    cout << endl << "\tLIST" << endl;
    cout << "\tInsertion finished after " << " seconds" << endl;
    cout << "\tLookup finished after " << " seconds." << endl << endl;
    return 0;
}

void writeToOutputFile(string fileName, vector<BookCharacter> data) {
    ofstream output(fileName, ofstream::out); // Write
    
    if (!output.is_open()) {
        cout << endl << "Error opening output file: " << fileName << endl << endl;
        return;
    }
    
    // Write the sorted segment values
    for (int counter = 0; counter < data.size(); counter++) {
        output << data[counter].getPageNo() << '\t';
        output << data[counter].getLineNo() << '\t';
        output << data[counter].getIndex()<< '\t';
        output << data[counter].getCharacter() << endl;
    }
    
    // Close the output file since it is no longer needed
    output.close();
}
