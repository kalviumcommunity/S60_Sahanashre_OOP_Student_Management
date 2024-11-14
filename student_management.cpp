#include <iostream>
#include <string>
using namespace std;

// Abstract Class Person
class Person {
public:
    virtual void displayDetails() const = 0;  // Pure virtual function
    virtual ~Person() {}  // Virtual destructor for proper cleanup
};

// Separate display logic for Student, Course, and Teacher
class StudentDisplay {
public:
    static void display(const class Student &student);
};

class CourseDisplay {
public:
    static void display(const class Course &course);
};

class TeacherDisplay {
public:
    static void display(const class Teacher &teacher);
};

class Student : public Person {
private:
    string name;
    int age;
    int rollNo;
    string address;

public:
    static int totalStudent;

    // Constructors
    Student() : name("Unknown"), age(0), rollNo(0), address("Not Provided") {
        totalStudent++;
    }

    Student(string n, int a, int r, string addr) : name(n), age(a), rollNo(r), address(addr) {
        totalStudent++;
    }

    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
    int getRollNo() const { return rollNo; }
    string getAddress() const { return address; }

    // Override displayDetails to respect LSP without downcasting
    void displayDetails() const override {
        StudentDisplay::display(*this);
    }

    ~Student() {
        cout << "Goodbye " << name << endl;
        totalStudent--;
    }
};

int Student::totalStudent = 0;

void StudentDisplay::display(const Student &student) {
    cout << "Student Name: " << student.getName() << ", Age: " << student.getAge()
         << ", Roll No: " << student.getRollNo() << ", Address: " << student.getAddress() << endl;
}

class Course : public Person {
private:
    string courseName;
    string courseCode;
    int credits;
    string instructor;

public:
    static int totalCourse;

    // Constructors
    Course() : courseName("Unknown"), courseCode(""), credits(0), instructor("") {
        totalCourse++;
    }

    Course(string n, string code, int c, string instr) : courseName(n), courseCode(code), credits(c), instructor(instr) {
        totalCourse++;
    }

    // Getters
    string getCourseName() const { return courseName; }
    string getCourseCode() const { return courseCode; }
    int getCredits() const { return credits; }
    string getInstructor() const { return instructor; }

    // Override displayDetails to respect LSP without downcasting
    void displayDetails() const override {
        CourseDisplay::display(*this);
    }

    ~Course() {
        cout << "Completed Course: " << courseName << endl;
        totalCourse--;
    }
};

int Course::totalCourse = 0;

void CourseDisplay::display(const Course &course) {
    cout << "Course Name: " << course.getCourseName() << ", Course Code: " << course.getCourseCode()
         << ", Credits: " << course.getCredits() << ", Instructor: " << course.getInstructor() << endl;
}

class Teacher : public Person {
private:
    string name;
    string department;
    string designation;

public:
    Teacher() : name("Unknown"), department("Not Provided"), designation("Not Provided") {}

    Teacher(string n, string dept, string desig) : name(n), department(dept), designation(desig) {}

    // Getters
    string getName() const { return name; }
    string getDepartment() const { return department; }
    string getDesignation() const { return designation; }

    // Override displayDetails to respect LSP without downcasting
    void displayDetails() const override {
        TeacherDisplay::display(*this);
    }

    ~Teacher() {
        cout << "Goodbye " << name << endl;
    }
};

void TeacherDisplay::display(const Teacher &teacher) {
    cout << "Teacher Name: " << teacher.getName() << ", Department: " << teacher.getDepartment()
         << ", Designation: " << teacher.getDesignation() << endl;
}

int main() {
    // Using base class pointers to demonstrate LSP
    Person* person1 = new Student("Sahu", 18, 1, "123 White Field");
    Person* person2 = new Course("Data Structures", "DS101", 3, "Nayan Kumar");
    Person* person3 = new Teacher("Siva Subramaniyan", "Computer Science", "Professor");

    // Display details for each object without downcasting
    person1->displayDetails();  
    person2->displayDetails();  
    person3->displayDetails();  

    // Clean up
    delete person1;
    delete person2;
    delete person3;

    return 0;
}
