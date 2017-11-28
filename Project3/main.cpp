/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 01.12.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 main.cpp -o proj3
 
 * * * * * * * * * * * * * * * * * */

#include <chrono> // high_resolution_clock
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
using namespace chrono;

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
    
    // Initialize necessary variables
    float numberOfCollisions = 0; // Use float to avoid static_cast
    float numberOfItems = 1; // Use float to avoid static_cast
    float avgCollisionsFor3 = 0.0;
    float avgCollisionsFor4 = 0.0;
    float avgCollisionsFor5 = 0.0;
    float avgCollisionsOverall = 0.0;
    
    float dictInsertionTime = 0.0;
    float listInsertionTime = 0.0;
    
    while(!inputFile.eof()) {
        getline(inputFile, line); // Read the line
        
        // If line is empty, no need to take action
        if(line.empty()) break;
        
        // Create stringstream to parse with '\t'
        stringstream linestream(line);
        
        string read[4];
        
        // Parse the line
        getline(linestream, read[0], '\t'); // Page no
        getline(linestream, read[1], '\t'); // Line no
        getline(linestream, read[2], '\t'); // Index
        linestream >> read[3]; // Character
        numberOfItems++;
        
        // Create a new BookCharacter
        BookCharacter new_book_character(read);
        
        auto dictInsertionStart = high_resolution_clock::now(); // Begin time stamp
        // Insert function of the dictionary return number of collisions
        numberOfCollisions += dictionary.insert(new_book_character); // Insert into dictionary
        auto dictInsertionEnd = high_resolution_clock::now(); // End time stamp
        // Get the elapsed time in unit microseconds
        dictInsertionTime += duration_cast<microseconds>(dictInsertionEnd - dictInsertionStart).count();
        
        // Calculate average number of collisions for 1.000, 10.000, 100.000
        if(numberOfItems == 1000)
            avgCollisionsFor3 = numberOfCollisions / numberOfItems;
        
        if(numberOfItems == 10000)
            avgCollisionsFor4 = numberOfCollisions / numberOfItems;
        
        if(numberOfItems == 100000)
            avgCollisionsFor5 = numberOfCollisions / numberOfItems;
        
        auto listInsertionStart = high_resolution_clock::now(); // Begin time stamp
        list.insert(new_book_character); // Insert into list
        auto listInsertionEnd = high_resolution_clock::now(); // End time stamp
        // Get the elapsed time in unit microseconds
        listInsertionTime += duration_cast<microseconds>(listInsertionEnd - listInsertionStart).count();
    }
    inputFile.close(); // Close the input file
    
    // Overall number of collisions
    avgCollisionsOverall = numberOfCollisions / numberOfItems;
    
    // Convert durations from microsecond to second
    dictInsertionTime /= 1000000;
    listInsertionTime /= 1000000;
    
    ifstream lookupFile("ds-set-lookup.txt", ifstream::in); // Read
    
    if (!lookupFile.is_open()) {
        cout << endl << "Error opening lookup file." << endl << endl;
        return 0;
    }

    vector<BookCharacter> lookupDictionary;
    vector<BookCharacter> lookupList;
    
    float dictLookupTime = 0.0;
    float listLookupTime = 0.0;
    
    while(!lookupFile.eof()) {
        getline(lookupFile, line); // Read the line
        
        // If line is empty, no need to take action
        if(line.empty()) break;
        
        // Create stringstream to parse with ','
        stringstream linestream(line);
        
        string read[4];
        
        // Parse the line
        getline(linestream, read[0], '\t'); // Page no
        getline(linestream, read[1], '\t'); // Line np
        linestream >> read[2]; // Index
        read[3] = '\0'; // Null character since it is not provided in the file
        
        // Create a new BookCharacter
        BookCharacter new_book_character(read);
        
        auto dictLookupStart = high_resolution_clock::now(); // Begin time stamp
        // Lookup from dictionary
        char chr = dictionary.lookup(new_book_character);
        // Set the new character looked up from the dictionary
        new_book_character.setCharacter(chr);
        auto dictLookupEnd = high_resolution_clock::now(); // End time stamp
        // Get the elapsed time in unit microseconds
        dictLookupTime += duration_cast<microseconds>(dictLookupEnd - dictLookupStart).count();
        
        // Add to the vector for dictionary lookups
        lookupDictionary.push_back(new_book_character);
        
        auto listLookupStart = high_resolution_clock::now(); // Begin time stamp
        // Lookup from list
        chr = list.lookup(new_book_character);
        // Set the new character looked up from the dictionary
        new_book_character.setCharacter(chr);
        auto listLookupEnd = high_resolution_clock::now(); // End time stamp
        // Get the elapsed time in unit microseconds
        listLookupTime += duration_cast<microseconds>(listLookupEnd - listLookupStart).count();
        
        // Add to the vector for list lookups
        lookupList.push_back(new_book_character);
    }
    lookupFile.close(); // Close the lookup file
    
    // Convert durations from microsecond to second
    dictLookupTime /= 1000000;
    listLookupTime /= 1000000;
    
    // Write lookup characters to output file
    writeToOutputFile("ds-set-output-dict.txt", lookupDictionary);
    writeToOutputFile("ds-set-output-list.txt", lookupList);
    
    cout << fixed << setprecision(2); // Set format for floating point numbers
    cout << endl << "\tDICTIONARY" << endl;
    cout << "\tInsertion finished after " << dictInsertionTime << " seconds." << endl << endl;
    cout << setw(46) << left << "\tAverage number of collisions (first 1,000)" << "|";
    cout << setw(7) << right << avgCollisionsFor3 << endl;
    cout << setw(46) << left << "\tAverage number of collisions (first 10,000)" << "|";
    cout << setw(7) << right << avgCollisionsFor4 << endl;
    cout << setw(46) << left << "\tAverage number of collisions (first 100,000)" << "|";
    cout << setw(7) << right << avgCollisionsFor5 << endl;
    cout << setw(46) << left << "\tAverage number of collisions (overall)" << "|";
    cout << setw(7) << right <<avgCollisionsOverall << endl << endl;
    cout << "\tLookup finished after " << dictLookupTime << " seconds." << endl;
    
    cout << endl << "\tLIST" << endl;
    cout << "\tInsertion finished after " << listInsertionTime << " seconds." << endl;
    cout << "\tLookup finished after " << listLookupTime << " seconds." << endl << endl;
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
