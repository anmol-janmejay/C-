// // Macro Keyword
// #include <iostream>
// #define PI 3.14159 // Defining a constant using a macro
// using namespace std;

// int main()
// {
//     double radius = 5;
//     double area = PI * radius * radius; // Replaced with 3.14159 * radius * radius before compilation
//     cout << "Area of circle: " << area << endl;
//     return 0;
// }

// Shallow Vs Deep Copy
// 1. Shallow Copy
// #include <iostream>
// #include <cstring>

// class Student
// {
// public:
//     char *name;

//     Student(const char *n)
//     {
//         name = new char[strlen(n) + 1]; // Dynamically allocate memory
//         strcpy(name, n);
//     }

//     // Default copy constructor (shallow copy)
//     Student(const Student &s)
//     {
//         name = s.name; // Only copying the pointer, not the data
//     }

//     ~Student()
//     {
//         delete[] name; // Free memory (problem: another object might still be using it!)
//     }
// };

// int main()
// {
//     Student s1("John");
//     Student s2 = s1; // Shallow copy (s2.name points to the same memory as s1.name)

//     std::cout << "s1: " << s1.name << std::endl;
//     std::cout << "s2: " << s2.name << std::endl;

//     delete[] s1.name; // This will cause s2.name to become a dangling pointer!

//     return 0;
// }
// 2. Deep copy
#include <iostream>
#include <cstring>

class Student
{
public:
    char *name;

    Student(const char *n)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Deep copy constructor
    Student(const Student &s)
    {
        name = new char[strlen(s.name) + 1]; // Allocate new memory
        strcpy(name, s.name);                // Copy data
    }

    ~Student()
    {
        delete[] name; // Free memory safely
    }
};

int main()
{
    Student s1("John");
    Student s2 = s1; // Deep copy (s2.name has separate memory)

    std::cout << "s1: " << s1.name << std::endl;
    std::cout << "s2: " << s2.name << std::endl;

    return 0;
}
