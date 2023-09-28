#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void){

    // Input and Output file stream for writing and reading data
    ifstream inFile;  
    ofstream outFile; 

    double test1, test2, test3, test4, test5; // Test scores.
    double average;   // Average test score.
    // Student's first and last name.
    string firstName; 
    string lastName;  

    // Open input and output files.
    inFile.open("test.txt");
    outFile.open("testavg.out");

    // Set precision to 2 decimal places.
    outFile << fixed << showpoint; 
    outFile << setprecision(2);    
    
    // Display processing message.
    cout << "Processing data" << endl; 

    // Read student names from the input file.
    inFile >> firstName >> lastName;
    outFile << "Student name: " << firstName
            << " " << lastName << endl; 

    // Read and write five test scores.
    inFile >> test1 >> test2 >> test3
           >> test4 >> test5;
    outFile << "Test scores: " << setw(6) << test1
            << setw(6) << test2 << setw(6) << test3
            << setw(6) << test4 << setw(6) << test5
            << endl;

    // Calculate and write the average test score.
    average = (test1 + test2 + test3 + test4
              + test5) / 5.0;
            
    outFile << "Average test score: " << setw(6)
            << average << endl;

    // Close input and output files.
    inFile.close();
    outFile.close();

    return 0;
}


