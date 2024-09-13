#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    int rollNo;

public:
    Student() {} 

    Student(string name, int age, int rollNo) {
        this->name = name;
        this->age = age;
        this->rollNo = rollNo;
    }

    void getStudentDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Roll No: " << rollNo << endl;
    }

    void updateAge(int newAge) {
        age = newAge;
        cout << "Updated Age: " << age << endl;
    }
};

class Course {
private:
    string courseName;
    string courseCode;
    int credits;

public:
    Course() {}  

    Course(string courseName, string courseCode, int credits) {
        this->courseName = courseName;
        this->courseCode = courseCode;
        this->credits = credits;
    }

    void getCourseDetails() {
        cout << "Course: " << courseName << ", Code: " << courseCode << ", Credits: " << credits << endl;
    }

    void updateCredits(int newCredits) {
        credits = newCredits;
        cout << "Updated Credits: " << credits << endl;
    }
};

int main() {
    Student students[2] = {
        Student("Sahu", 18, 1),
        Student("Sasdi", 14, 2)
    };

    for (int i = 0; i < 2; i++) {
        students[i].getStudentDetails();
    }

    students[0].updateAge(19);

    Course courses[2] = {
        Course("Problem Solving", "PSUP1", 4),
        Course("Data Structures", "DS101", 3)
    };

    for (int i = 0; i < 2; i++) {
        courses[i].getCourseDetails();
    }

    courses[0].updateCredits(5);

    return 0;
}
