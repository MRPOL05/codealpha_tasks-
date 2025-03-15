#include <iostream>
#include <vector>
using namespace std;

struct Course {
    string name;
    double grade;
    int credits;
};

double calculateGPA(vector<Course> &courses) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (const auto &course : courses) {
        totalGradePoints += course.grade * course.credits;
        totalCredits += course.credits;
    }

    return (totalCredits == 0) ? 0.0 : totalGradePoints / totalCredits;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter details for course " << i + 1 << "\n";
        cout << "Course Name: ";
        cin >> courses[i].name;
        cout << "Grade (on a 4.0 scale): ";
        cin >> courses[i].grade;
        cout << "Credit Hours: ";
        cin >> courses[i].credits;
    }

    double cgpa = calculateGPA(courses);

    cout << "\nIndividual Course Details:\n";
    cout << "---------------------------------\n";
    for (const auto &course : courses) {
        cout << "Course: " << course.name << ", Grade: " << course.grade << ", Credits: " << course.credits << "\n";
    }

    cout << "---------------------------------\n";
    cout << "Total CGPA: " << cgpa << "\n";

    return 0;
}
