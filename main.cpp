#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Define the structure for a course
struct Course {
    string number;                     // Course number
    string title;                      // Course title
    vector<string> prerequisites;     // List of prerequisites
};

// Global map to store course number → Course object
map<string, Course> courses;

// Helper function to remove leading/trailing whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

// Convert any string to uppercase for consistent key handling
string toUpper(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Function to load course data from a CSV file into the map
void loadData(string fileName) {
    ifstream file(fileName);
    string line;

    // Read each line in the file
    while (getline(file, line)) {
        stringstream ss(line);
        string number, title, prereq;

        // Read the course number and title
        getline(ss, number, ',');
        getline(ss, title, ',');

        Course course;
        course.number = trim(number);
        course.title = trim(title);

        // Read remaining fields as prerequisites
        while (getline(ss, prereq, ',')) {
            course.prerequisites.push_back(trim(prereq));
        }

        // Store the course in the map using uppercase as the key
        courses[toUpper(course.number)] = course;
    }

    cout << "Courses loaded successfully!" << endl;
}

// Function to print all courses in alphanumeric order
void printAllCourses() {
    cout << "Here is a sample schedule:" << endl;

    // Create a sorted list of course numbers
    vector<string> sortedKeys;
    for (auto const& pair : courses) {
        sortedKeys.push_back(pair.first);
    }
    sort(sortedKeys.begin(), sortedKeys.end());

    // Print course number and title
    for (string const& key : sortedKeys) {
        cout << courses[key].number << ", " << courses[key].title << endl;
    }
}

// Function to print course details including prerequisites
void printCourse(string input) {
    string courseKey = toUpper(trim(input)); // Normalize input
    if (courses.find(courseKey) != courses.end()) {
        Course c = courses[courseKey];
        cout << c.number << ", " << c.title << endl;

        // Print prerequisites or "None" if empty
        if (!c.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (size_t i = 0; i < c.prerequisites.size(); ++i) {
                cout << c.prerequisites[i];
                if (i < c.prerequisites.size() - 1) cout << ", ";
            }
            cout << endl;
        }
        else {
            cout << "Prerequisites: None" << endl;
        }
    }
    else {
        cout << "Course not found." << endl;
    }
}

// Main menu loop
void menu() {
    int choice = 0;
    string fileName;

    while (choice != 9) {
        // Display menu options
        cout << "\n1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            // Ask user for CSV file name and load data
            cout << "Enter file name: ";
            cin >> fileName;
            loadData(fileName);
            break;
        case 2:
            // Print sorted list of courses
            printAllCourses();
            break;
        case 3:
            // Lookup specific course info
            cout << "What course do you want to know about? ";
            {
                string courseInput;
                cin >> courseInput;
                printCourse(courseInput);
            }
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;
        default:
            // Handle invalid menu options
            cout << choice << " is not a valid option." << endl;
        }
    }
}

// Program entry point
int main() {
    menu(); // Start menu loop
    return 0;
}

