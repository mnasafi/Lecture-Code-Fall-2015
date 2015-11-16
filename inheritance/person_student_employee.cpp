#include <string>
#include <iostream>
using namespace std;


// base class for class Person and class Employee
class Person{
    public:
        Person(string name);
        virtual void print()=0;   // pure virtual function

    // Protected so class that inherit me can access it.
    protected:
        string m_name;

};

Person::Person(string name){
    m_name = name;
}

//If Person isn't pure virtual could implement print
/*
Person::void print(){
    cout << "Person's name is: " << m_name << endl;
}*/

// class Student inherits class Person
class Student : public Person{
    public:
        Student(string name, int age);
        void print();
    protected:
        int m_age;
};

// the ": Person(name)" calls class Person's constructor
Student::Student(string name, int age) : Person(name){
    m_age = age;
}

// print() is a virtual function in class Person
void Student::print(){
    cout << "Student: " << m_name << " is " << m_age << "." << endl;
}

// class Employee inherits class Person
class Employee : public Person{
    public:
        Employee(string name, string ss_num);
        void print();
    protected:
        string m_ss_num;
};


// the ": Person(name)" calls class Person's constructor
Employee::Employee(string name, string ss_num) : Person(name){
    m_ss_num = ss_num;
}

// print() is a virtual function in class Person
void Employee::print(){
    cout << "Employee: " << m_name << ", ss number = " << m_ss_num << "." << endl;
}

class Child : protected Person{
    public:
        Child(string name, string school);
    private:
        string m_school;
};

Child::Child(string name, string school) : Person(name){
    m_school = school;
}

int main(){
    // Child *my_child = new Child("Fred", "Chico High");

    Person *everyone[6];

    // Since Student and Employee inherit Person, legal to do the following
    everyone[0] = new Student("Joe", 19);
    everyone[1] = new Student("Sally", 18);
    everyone[2] = new Student("Sam", 21);
    everyone[3] = new Employee("Tim", "555-55-1234");
    everyone[4] = new Employee("Tom", "555-55-1235");
    everyone[5] = new Employee("Ted", "555-55-1236");

    // print() is a virtual function in Person.
    // Student and Employee provide their own version of print()
    // it is the Student's and Employee's version of print() called below
    for (int i = 0; i < 6; i++){
        everyone[i]->print();
    }
}

/***** the above program produces the following output

Student: Joe is 19.
Student: Sally is 18.
Student: Sam is 21.
Employee: Tim, ss number = 555-55-1234.
Employee: Tom, ss number = 555-55-1235.
Employee: Ted, ss number = 555-55-1236.

******/
