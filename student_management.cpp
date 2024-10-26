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
    
    // Destructor
    ~Student(){
        cout << "Good Bye " << name << endl;
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
    static int totalCourse; 

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
    
    // Destructor
    ~Course(){
        cout << "Completed Course is " << courseName << endl;
        totalCourse--;
    }
};

// Initialize static variable
int Course::totalCourse = 0;

// Single inheritance: GraduateStudent inherits from Student
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

// Hierarchical Inheritance: TheoryCourse and PracticalCourse inherit from Course
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
    // Create GraduateStudent object
    GraduateStudent gradStudent("Sahu", 18, 1, "123 White Field", "AI and ML");
    gradStudent.getGraduateStudentDetails();

    // Create TheoryCourse and PracticalCourse objects
    TheoryCourse theory("Problem Solving", "PSUP1", 4, "Nayan");
    PracticalCourse practical("Data Structures Lab", "DS101", 3, "Sumit", "Arjun");

    // Display course details
    theory.getTheoryCourseDetails();
    practical.getPracticalCourseDetails();
    
    // Print total number of students and courses
    Student::totalStudents();
    Course::totalCourses();

    return 0;
}
