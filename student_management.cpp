#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    int rollNo;

public:
    static int totalStudent;
    Student() {totalStudent++;} 

    void setStudent(string n, int a, int r){
        name = n;
        age = a;
        rollNo = r;
    }
    
    string getName() { return name; }
    int getAge() { return age; }
    int getRollNo() { return rollNo; }

    void getStudentDetails() {
        cout << "Name: " << getName() << ", Age: " << getAge() << ", Roll No: " << getRollNo() << endl;
    }

    void updateAge(int newAge) {
        age = newAge;
        cout << "Updated Age: " << age << endl;
    }
    
    static void totalStudents(){
        cout<<"Total Students: " << totalStudent << endl;
    }
};
int Student::totalStudent=0;

class Course {
private:
    string courseName;
    string courseCode;
    int credits;

public:
    static int totalCourse;
    Course() {totalCourse++;}  

    void setCourse(string n, string code, int c){
        courseName = n;
        courseCode = code;
        credits = c;
    }

    string getCourseName() { return courseName; }
    string getCourseCode() { return courseCode; }
    int getCredits() { return credits; }

    void getCourseDetails() {
        cout << "Course: " << getCourseName() << ", Code: " << getCourseCode() << ", Credits: " << getCredits() << endl;
    }

    void updateCredits(int newCredits) {
        credits = newCredits;
        cout << "Updated Credits: " << credits << endl;
    }
    
    static void totalCourses(){
        cout<<"Total Courses: "<<totalCourse<<endl;
    }
    
};

int Course::totalCourse=0;
int main() {
    Student students[2];
        students[0].setStudent("Sahu", 18, 1);
        students[1].setStudent("Sasdi", 14, 2);

    for (int i = 0; i < 2; i++) {
        students[i].getStudentDetails();
    }

    students[0].updateAge(19);

    Course courses[2];
        courses[0].setCourse("Problem Solving", "PSUP1", 4);
        courses[1].setCourse("Data Structures", "DS101", 3);
    
    for (int i = 0; i < 2; i++) {
        courses[i].getCourseDetails();
    }

    courses[0].updateCredits(5);
    
    Student::totalStudents();
    Course::totalCourses();

    return 0;
}