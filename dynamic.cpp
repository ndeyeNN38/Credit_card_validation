#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // To make sure that the user provided two command line arguments
    if (argc != 3) {
        cerr << argv[0] << " You must provide two command line arguments!!" << endl;
        return 1;
    }

    ifstream in_file(argv[1]);

    // Make sure that we are able to read the file or not
    if (in_file.fail()) {
        cout << "We are not able to read the file" << endl;
        return 1;
    }

    string line;
    int count = 0;
    int student_grades = 0;
    string top_student;
    double highest_grade = -1.0; // Initialize to a low value

    // Extract each name and grade, after counting the number of students and total grades
    while (getline(in_file, line)) {
        istringstream textfile(line);
        string name;
        textfile >> name;

        if (!name.empty()) {
            count++;
        }

        float grade;
        while (textfile >> grade) {
            student_grades++;
        }
    }

    // Dynamic arrays allocations for names and grades.
    string* studentNames = new string[count];
    float* gradeAverages = new float[count];
    int* gradeCounts = new int[count];

    float threshold;
    stringstream thresholdStream(argv[2]);
    thresholdStream >> threshold;

    int studentsAboveThreshold = 0;
    double sum = 0;
    int total_grade = 0;

    cout << "All Students and Grades: " << endl;

    // We are reading the file and populating arrays
    int index = 0;
    in_file.clear();              // Clear EOF flag
    in_file.seekg(0, ios::beg);   // Reset to the beginning of the file

    while (getline(in_file, line)) {
        istringstream textfile(line);
        string name;
        textfile >> name;

        studentNames[index] = name;

        double gradeSum = 0;
        int gradeCount = 0;
        float grade;

        // Extract the grades for the current student
        while (textfile >> grade) {
            gradeSum += grade;
            gradeCount++;
        }

        // Calculation of the average for the current student
        if (gradeCount == 0) {
            cout << name << " has no grades!" << endl;
            gradeAverages[index] = 0;
            gradeCounts[index] = 0;
        } else {
            double average = gradeSum / gradeCount;
            gradeAverages[index] = average;
            gradeCounts[index] = gradeCount;
            cout << name << ": " << fixed << setprecision(1) << average << endl;

            sum += gradeSum;
            total_grade += gradeCount;

            // Check if the student's average is above the threshold
            if (average > threshold) {
                studentsAboveThreshold++;
            }

            // Student with highest grade calculations
            if (average > highest_grade) {
                highest_grade = average;
                top_student = name;
            }
        }
        index++;  // Increment index here
    }
      
     cout<<" " <<endl; // for space between the outputs.
    // Output the total number of students above the threshold
    cout << "Number of students above the threshold (" << threshold << "): " << studentsAboveThreshold << endl;
    cout<<" " <<endl;

    // If we have at least one grade, calculate and output the overall class average
    if (total_grade > 0) {
        double classAverage = sum / total_grade;
        cout << "Class average: " << fixed << setprecision(2) << classAverage << endl;
    } else {
        cout << "You should provide grades!!" << endl;
    }
    
        cout<<" " <<endl;

    // To display the student with the highest grade
    if (highest_grade >= 0) {
        cout << "Student with the highest grade is: " <<endl;
        cout<< top_student <<": "<< fixed << setprecision(1) << highest_grade << endl;
    } else {
        cout << "No grades available to determine the highest grade." << endl;
    }

    // Delete the memory allocation 
    delete[] studentNames;
    delete[] gradeAverages;
    delete[] gradeCounts;

    in_file.close(); // Close the file
    return 0;
}
