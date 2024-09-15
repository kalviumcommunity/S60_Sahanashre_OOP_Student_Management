#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;  
    int age;      
    int rollNo;
    string address; 
    
public:
    //Initialize static variable
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

    // Setter function 
    void setStudent(string n, int a, int r, string addr){
        name = n;
        age = a;
        rollNo = r;
        address = addr;
    }

    // Getter function for name
    string getName() { return name; }

    // Getter function for age
    int getAge() { return age; }

    // Getter function for roll number
    int getRollNo() { return rollNo; }

    // Getter function for address
    string getAddress() { return address; }

    // Function to print student details
    void getStudentDetails() {
        cout << "Name: " << getName() << ", Age: " << getAge() << ", Roll No: " << getRollNo() << ", Address: " << getAddress() << endl;
    }

    // Mutator function to update student's age
    void updateAge(int newAge) {
        age = newAge;
        cout << "Updated Age: " << age << endl;
    }
    
    // Static function to print total number of students
    static void totalStudents() {
        cout << "Total Students: " << totalStudent << endl;
    }
    
    // Destructors
    ~Student(){
        cout<<"Good Bye "<<name<<endl;
        totalStudent--;
    }
};

// Initialize static variable
int Student::totalStudent = 0;

class Course {
private:
    string courseName; 
    string courseCode; 
    int credits;       
    string instructor; 

public:
    static int totalCourse; // Static variable

    // Default Constructor
    Course() { 
        courseName = "Unknown";
        courseCode = "";
        credits = 0;
        instructor = "";
        totalCourse++;
        }
        
    // Parameterized Constructor
    Course(string n, string code, int c, string instr) {
        courseName = n;
        courseCode = code;
        credits = c;
        instructor = instr;
        totalCourse++;
    }

    // Setter function
    void setCourse(string n, string code, int c, string instr) {
        courseName = n;
        courseCode = code;
        credits = c;
        instructor = instr; 
    }

    // Getter function for course name
    string getCourseName() { return courseName; }

    // Getter function for course code
    string getCourseCode() { return courseCode; }

    // Getter function for credits
    int getCredits() { return credits; }

    // Getter function for instructor
    string getInstructor() { return instructor; }

    // Function to print course details
    void getCourseDetails() {
        cout << "Course: " << getCourseName() << ", Code: " << getCourseCode() << ", Credits: " << getCredits() << ", Instructor: " << getInstructor() << endl;
    }

    // Mutator function to update course credits
    void updateCredits(int newCredits) {
        credits = newCredits;
        cout << "Updated Credits: " << credits << endl;
    }
    
    // Static function to print total number of courses
    static void totalCourses() {
        cout << "Total Courses: " << totalCourse << endl;
    }
    
    // Destructors
    ~Course(){
        cout<<"Completed Course is "<<courseName<<endl;
        totalCourse--;
    }
};

// Initialize static variable
int Course::totalCourse = 0;

int main() {
    // Create array of Student objects and set their details
    Student students[2];
    students[0].setStudent("Sahu", 18, 1, "123 White Field");
    students[1].setStudent("Sasdi", 14, 2, "456 Oak Avenue");

    // Print details of each student
    for (int i = 0; i < 2; i++) {
        students[i].getStudentDetails();
    }

    // Update age of the first student
    students[0].updateAge(19);

    // Create array of Course objects and send their details using parameterized constructors
    Course courses[2] = {
    Course("Problem Solving", "PSUP1", 4, "Nayan"),
    Course("Data Structures", "DS101", 3, "Sumit")
    };
    
    // Print details of each course
    for (int i = 0; i < 2; i++) {
        courses[i].getCourseDetails();
    }

    // Update credits of the first course
    courses[0].updateCredits(5);
    
    // Print total number of students and courses
    Student::totalStudents();
    Course::totalCourses();

    return 0;
}
