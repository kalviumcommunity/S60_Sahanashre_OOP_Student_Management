#include <iostream>
#include <string>
using namespace std;

// Abstract Class Person
class Person {
public:
    // Pure virtual function
    virtual void displayDetails() const = 0;
};

// Separate display class for Student
class StudentDisplay {
public:
    static void display(class Student &student);
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

    void setStudent(string n, int a, int r, string addr) {
        name = n;
        age = a;
        rollNo = r;
        address = addr;
    }

    string getName() { return name; }
    int getAge() { return age; }
    int getRollNo() { return rollNo; }
    string getAddress() { return address; }

    void updateAge(int newAge) {
        age = newAge;
        cout << "Updated Age: " << age << endl;
    }

    static void totalStudents() {
        cout << "Total Students: " << totalStudent << endl;
    }

    void displayDetails() const override {
        StudentDisplay::display(*(Student*)this);
    }

    ~Student() {
        cout << "Goodbye " << name << endl;
        totalStudent--;
    }
};

int Student::totalStudent = 0;

void StudentDisplay::display(Student &student) {
    cout << "Student Name: " << student.getName() << ", Age: " << student.getAge()
         << ", Roll No: " << student.getRollNo() << ", Address: " << student.getAddress() << endl;
}

// Separate display class for Course
class CourseDisplay {
public:
    static void display(class Course &course);
};

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

    void updateCredits(int newCredits) {
        credits = newCredits;
        cout << "Updated Credits: " << credits << endl;
    }

    static void totalCourses() {
        cout << "Total Courses: " << totalCourse << endl;
    }

    void displayDetails() const override {
        CourseDisplay::display(*(Course*)this);
    }

    ~Course() {
        cout << "Completed Course: " << courseName << endl;
        totalCourse--;
    }
};

int Course::totalCourse = 0;

void CourseDisplay::display(Course &course) {
    cout << "Course Name: " << course.getCourseName() << ", Course Code: " << course.getCourseCode()
         << ", Credits: " << course.getCredits() << ", Instructor: " << course.getInstructor() << endl;
}

// New Teacher Class
class TeacherDisplay {
public:
    static void display(class Teacher &teacher);
};

class Teacher : public Person {
private:
    string name;
    string department;
    string designation;

public:
    Teacher() {
        name = "Unknown";
        department = "Not Provided";
        designation = "Not Provided";
    }

    Teacher(string n, string dept, string desig) {
        name = n;
        department = dept;
        designation = desig;
    }

    string getName() { return name; }
    string getDepartment() { return department; }
    string getDesignation() { return designation; }

    void displayDetails() const override {
        TeacherDisplay::display(*(Teacher*)this);
    }

    ~Teacher() {
        cout << "Goodbye " << name << endl;
    }
};

void TeacherDisplay::display(Teacher &teacher) {
    cout << "Teacher Name: " << teacher.getName() << ", Department: " << teacher.getDepartment()
         << ", Designation: " << teacher.getDesignation() << endl;
}

int main() {
    // Demonstrating function overloading with setStudent
    Student student1;
    student1.setStudent("Sahu", 18, 1, "123 White Field");
    student1.displayDetails();

    // Using parameterized constructor to create Course objects
    Course course1("Data Structures", "DS101", 3, "Dr. Smith");
    course1.displayDetails();

    // Using parameterized constructor to create Teacher objects
    Teacher teacher1("Dr. Green", "Computer Science", "Professor");
    teacher1.displayDetails();

    // Using pointers to demonstrate polymorphism with abstract class
    Person* person1 = new Student("John", 20, 101, "Main Street");
    Person* person2 = new Course("Algorithms", "ALG202", 4, "Dr. Brown");
    Person* person3 = new Teacher("Dr. White", "Mathematics", "Lecturer");

    person1->displayDetails();  
    person2->displayDetails();  
    person3->displayDetails();  

    // Clean up
    delete person1;
    delete person2;
    delete person3;

    return 0;
}
