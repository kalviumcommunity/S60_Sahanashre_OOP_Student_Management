#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
    string name;
    int age;
    int rollNo;
    public:
    Student(string name, int age, int rollNo){
        this->name = name;
        this->age = age;
        this->rollNo = rollNo;
    }
    void getStudentDetails(){
        cout<<"Name: "<< name << ", Age: " << age << ", Student Roll No: "<< rollNo << endl;
    }
    void updateAge(int newAge){
        age = newAge;
        cout<<"Updated Age: " << age << endl;
    }
};

class Course {
private:
    string courseName;
    string courseCode;
    int credits;

public:
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
    Student student1("Sahu", 18, 1);
    student1.getStudentDetails();  
    student1.updateAge(19); 

    Course course1("Problem Solving", "PSUP1", 4);
    course1.getCourseDetails();  
    course1.updateCredits(5);    

    return 0;
}
