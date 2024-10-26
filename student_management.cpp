#include <iostream>
#include <string>
using namespace std;

// Abstract Class Person
class Person {
public:
    // Pure virtual function
    virtual void displayDetails() const = 0;
};

class Student : public Person {
private:
    string name;  
    int age;      
    int rollNo;
    string address; 
    
public:
    static int totalStudent; 

    // Default Constructor
    Student() { 
        name = "Unknown";
        age = 0;
        rollNo = 0;
        address = "Not Provided";
        totalStudent++; 
    }
    
    // Parameterized Constructor
    Student(string n, int a, int r, string addr) {
        name = n;
        age = a;
        rollNo = r;
        address = addr;
        totalStudent++;
    }

    // Overloaded setter function for full details
    void setStudent(string n, int a, int r, string addr) {
        name = n;
        age = a;
        rollNo = r;
        address = addr;
    }

    // Overloaded setter function for name and roll number only
    void setStudent(string n, int r) {
        name = n;
        rollNo = r;
    }

    string getName() { return name; }
    int getAge() { return age; }
    int getRollNo() { return rollNo; }
    string getAddress() { return address; }

    void getStudentDetails() {
        cout << "Name: " << getName() << ", Age: " << getAge() << ", Roll No: " << getRollNo() << ", Address: " << getAddress() << endl;
    }

    void updateAge(int newAge) {
        age = newAge;
        cout << "Updated Age: " << age << endl;
    }

    static void totalStudents() {
        cout << "Total Students: " << totalStudent << endl;
    }

    // Overriding virtual function
    void displayDetails() const override {
        cout << "Student Name: " << name << ", Roll No: " << rollNo << endl;
    }

    ~Student() {
        cout << "Good Bye " << name << endl;
        totalStudent--;
    }
};

int Student::totalStudent = 0;

class Course : public Person {
private:
    string courseName; 
    string courseCode; 
    int credits;       
    string instructor; 

public:
    static int totalCourse;

    Course() { 
        courseName = "Unknown";
        courseCode = "";
        credits = 0;
        instructor = "";
        totalCourse++;
    }
        
    Course(string n, string code, int c, string instr) {
        courseName = n;
        courseCode = code;
        credits = c;
        instructor = instr;
        totalCourse++;
    }

    void setCourse(string n, string code, int c, string instr) {
        courseName = n;
        courseCode = code;
        credits = c;
        instructor = instr; 
    }

    string getCourseName() { return courseName; }
    string getCourseCode() { return courseCode; }
    int getCredits() { return credits; }
    string getInstructor() { return instructor; }

    void getCourseDetails() {
        cout << "Course: " << getCourseName() << ", Code: " << getCourseCode() << ", Credits: " << getCredits() << ", Instructor: " << getInstructor() << endl;
    }

    void updateCredits(int newCredits) {
        credits = newCredits;
        cout << "Updated Credits: " << credits << endl;
    }

    static void totalCourses() {
        cout << "Total Courses: " << totalCourse << endl;
    }

    // Overriding virtual function
    void displayDetails() const override {
        cout << "Course Name: " << courseName << ", Course Code: " << courseCode << endl;
    }

    ~Course() {
        cout << "Completed Course is " << courseName << endl;
        totalCourse--;
    }
};

int Course::totalCourse = 0;

int main() {
    // Demonstrating function overloading with setStudent
    Student student1;
    student1.setStudent("Sahu", 1);  // Only name and roll number
    student1.getStudentDetails();

    student1.setStudent("Sahu", 18, 1, "123 White Field"); // Full details
    student1.getStudentDetails();

    // Using pointers to demonstrate polymorphism with abstract class
    Person* person1 = new Student("John", 20, 101, "Main Street");
    Person* person2 = new Course("Data Structures", "DS101", 3, "Dr. Smith");

    person1->displayDetails(); // Calls Student's displayDetails
    person2->displayDetails(); // Calls Course's displayDetails

    // Clean up
    delete person1;
    delete person2;

    return 0;
}
