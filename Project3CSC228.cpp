#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Function to calculate the letter grade based on average score
char calculateLetterGrade(double average) {
    if (average >= 90.0) {
        return 'A';
    } else if (average >= 80.0) {
        return 'B';
    } else if (average >= 70.0) {
        return 'C';
    } else if (average >= 60.0) {
        return 'D';
    } else {
        return 'F';   
    }
}

int main(void) {
    ifstream inputFile("input.txt");    // Open the input file
    ofstream outputFile("output.txt");  // Open the output file

    // Check if the input file can be opened
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Check if the output file can be opened
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    int numStudents;
    inputFile >> numStudents;   // Read the number of student records from input file

    // Write the header line to the output file with formatting
    outputFile << setw(15) << left << "Student" << setw(6) << "Gr1" << setw(6) << "Gr2" << setw(6) << "Gr3" << setw(6) << "Avg." << setw(6) << "Grade" << endl;
    outputFile << fixed << setprecision(2);  // Set the output precision

    for (int i = 0; i < numStudents; ++i) {
        string firstName, lastName;
        double grade1, grade2, grade3;

        // Read student data from input file
        inputFile >> firstName >> lastName >> grade1 >> grade2 >> grade3;

        // Calculate the average grade for the student
        double average = (grade1 + grade2 + grade3) / 3.0;

        // Calculate the letter grade using the calculateLetterGrade function
        char letterGrade = calculateLetterGrade(average);

        // Write student information and grades to the output file with formatting
        outputFile << setw(15) << left << (firstName + " " + lastName) << setw(6) << grade1 << setw(6) << grade2 << setw(6) << grade3 << setw(6) << average << setw(6) << letterGrade << endl;
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    cout << "Processing completed. Results written to output.txt." << endl;

    return 0;
}

