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

    ~Student() {
        cout << "Good Bye " << name << endl;
        totalStudent--;
    }
};

int Student::totalStudent = 0;

class Course {
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

    ~Course() {
        cout << "Completed Course is " << courseName << endl;
        totalCourse--;
    }
};

int Course::totalCourse = 0;

class GraduateStudent : public Student {
    string researchTopic;

public:
    GraduateStudent(string name, int age, int rollNo, string address, string topic) 
        : Student(name, age, rollNo, address), researchTopic(topic) {}

    void getGraduateStudentDetails() {
        getStudentDetails();
        cout << "Research Topic: " << researchTopic << endl;
    }
};

class TheoryCourse : public Course {
public:
    TheoryCourse(string n, string code, int c, string instr) : Course(n, code, c, instr) {}

    void getTheoryCourseDetails() {
        cout << "Theory ";
        getCourseDetails();
    }
};

class PracticalCourse : public Course {
private:
    string labAssistant;

public:
    PracticalCourse(string n, string code, int c, string instr, string assistant) 
        : Course(n, code, c, instr), labAssistant(assistant) {}

    void getPracticalCourseDetails() {
        cout << "Practical ";
        getCourseDetails();
        cout << "Lab Assistant: " << labAssistant << endl;
    }
};

int main() {
    // Demonstrating function overloading with setStudent
    Student student1;
    student1.setStudent("Sahu", 1);  // Only name and roll number
    student1.getStudentDetails();

    student1.setStudent("Sahu", 18, 1, "123 White Field"); // Full details
    student1.getStudentDetails();

    GraduateStudent gradStudent("Sahu", 18, 1, "123 White Field", "AI and ML");
    gradStudent.getGraduateStudentDetails();

    TheoryCourse theory("Problem Solving", "PSUP1", 4, "Nayan");
    PracticalCourse practical("Data Structures Lab", "DS101", 3, "Sumit", "Arjun");

    theory.getTheoryCourseDetails();
    practical.getPracticalCourseDetails();
    
    Student::totalStudents();
    Course::totalCourses();

    return 0;
}