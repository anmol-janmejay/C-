#include <iostream>
using namespace std;

// 1> Encapsulation

// class BankAccount
// {
// private:
//     int balance; // Private data

// public:
//     // Constructor
//     BankAccount(int amount)
//     {
//         if (amount >= 0)
//             balance = amount;
//         else
//             balance = 0;
//     }

//     // Public method to access private data
//     void deposit(int amount)
//     {
//         if (amount > 0)
//             balance += amount;
//     }

//     int getBalance()
//     {
//         return balance;
//     }
// };

// int main()
// {
//     BankAccount acc(1000);
//     acc.deposit(500); // Allowed
//     cout << "Balance: " << acc.getBalance() << endl;

//     // acc.balance = 5000;  // ❌ Not allowed (private data)
//     return 0;
// }

// 2> Inheritance(Code Reusability)
// class Animal
// { // Parent class
// public:
//     void eat()
//     {
//         cout << "Eating..." << endl;
//     }
// };

// // Dog class inherits from Animal class
// class Dog : public Animal
// {
// public:
//     void bark()
//     {
//         cout << "Barking..." << endl;
//     }
// };

// int main()
// {
//     Dog d;
//     d.eat();  // Inherited from Animal
//     d.bark(); // Defined in Dog
//     return 0;
// }

// 3> PolyMorphism
// class Math
// {
// public:
//     int add(int a, int b)
//     {
//         return a + b;
//     }

//     double add(double a, double b)
//     {
//         return a + b;
//     }
// };

// int main()
// {
//     Math obj;
//     cout << "Sum (int): " << obj.add(5, 3) << endl;
//     cout << "Sum (double): " << obj.add(5.5, 3.2) << endl;
//     return 0;
// }

// 4> Abstraction(Hiding Implementation Detail)
// class Shape
// {
// public:
//     virtual void draw() = 0; // Pure virtual function (Interface)
// };

// class Circle : public Shape
// {
// public:
//     void draw() override
//     {
//         cout << "Drawing Circle" << endl;
//     }
// };

// int main()
// {
//     Shape *s;
//     Circle c;
//     s = &c;
//     s->draw(); // Calls Circle's draw()
//     return 0;
// }

// class fruit
// {
// public:
//     string name;
// };

// class mango : public fruit
// {
// public:
//     int weight;
// };

// class alphonso : public mango
// {
// public:
//     int sugarLevel;
// };

// int main()
// {
//     alphonso a;
//     cout << a.name << " " << a.weight << " " << a.sugarLevel << endl;
//     return 0;
// }

// Multiple inheritance
// class A
// {
// public:
//     int physics;
// };
// class B
// {
// public:
//     int chemistry;
// };
// class C : public A, public B
// {
// public:
//     int maths;
// };

// int main()
// {
//     C obj;
//     cout << obj.physics << " " << obj.chemistry << " " << obj.maths << endl;
//     return 0;
// }

class param
{
public:
    int val; // Public integer variable to store a value

    // Overloading the + operator
    void operator+(param &obj2)
    {
        int value1 = this->val;            // Get value of current object (object1)
        int value2 = obj2.val;             // Get value of passed object (object2)
        cout << (value2 - value1) << endl; // Print difference (value2 - value1)
    }
};

int main()
{
    param object1, object2;

    object1.val = 7;
    object2.val = 2;

    // This should print the difference between them
    object1 + object2;
    return 0;
}
