#include <iostream>
using namespace std;

// class Car
// { // Class
// public:
//     string brand;
//     int speed;

//     void show()
//     {
//         cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
//     }
// };

// int main()
// {
//     Car car1; // Object
//     car1.brand = "Toyota";
//     car1.speed = 120;
//     car1.show();
//     return 0;
// }

// class BankAccount
// {
// private:
//     int balance;

// public:
//     void setBalance(int amount)
//     {
//         if (amount >= 0)
//             balance = amount;
//         else
//             cout << "Invalid balance!" << endl;
//     }

//     int getBalance()
//     {
//         return balance;
//     }
// };

// int main()
// {
//     BankAccount account;
//     account.setBalance(1000);
//     cout << "Balance: " << account.getBalance() << endl;
//     return 0;
// }

// class Animal
// {
// public:
//     void makeSound()
//     {
//         cout << "Some sound" << endl;
//     }
// };

// class Dog : public Animal
// {
// public:
//     void bark()
//     {
//         cout << "Woof Woof!" << endl;
//     }
// };

// int main()
// {
//     Dog d;
//     d.makeSound(); // Inherited from Animal
//     d.bark();
//     return 0;
// }

// class Animal
// {
//     // state or properties
// private:
//     int weight;

// public:
//     int age;
//     string type;
//     string name;

//     // default constructor
//     Animal()
//     {
//         cout << "Constructor Called" << endl;
//     }

//     // behaviour
//     void eat()
//     {
//         cout << "Eating" << endl;
//     }

//     void sleep()
//     {
//         cout << "Sleeping" << endl;
//     }

//     int getWeight()
//     {
//         return weight;
//     }

//     void setWeight(int w)
//     {
//         weight = w;
//     }
// };

// int main()
// {
//     // object creation

//     // static
//     // Animal paaji;
//     // paaji.name = "Suar";
//     // paaji.age = 22;
//     // cout << "Name of Paaji is: " << paaji.name << endl;
//     // cout << "Age of Paaji is: " << paaji.age << endl;

//     // paaji.eat();
//     // paaji.sleep();

//     // // To private member
//     // paaji.setWeight(69);
//     // cout << "Weight: " << paaji.getWeight() << endl;

//     // Dynamic
//     Animal *paaji = new Animal;
//     (*paaji).age = 22;
//     (*paaji).type = "Suar";

//     // Alternative iteration
//     paaji->age = 21;
//     paaji->type = "Dog";

//     return 0;
// }

#include <iostream>
using namespace std;

class Car
{
public:
    string brand;
    int speed;

    // **1. Default Constructor**
    Car()
    {
        brand = "Unknown";
        speed = 0;
        cout << "Default Constructor called!" << endl;
    }

    // **2. Parameterized Constructor**
    Car(string b, int s)
    {
        brand = b;
        speed = s;
        cout << "Parameterized Constructor called!" << endl;
    }

    // **3. Copy Constructor**
    Car(const Car &c)
    {
        brand = c.brand;
        speed = c.speed;
        cout << "Copy Constructor called!" << endl;
    }

    // Function to display car details
    void show()
    {
        cout << "Car Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }

    // **4. Destructor**
    ~Car()
    {
        cout << "Destructor called for " << brand << endl;
    }
};

int main()
{
    cout << "Creating car1 using Default Constructor...\n";
    Car car1; // Calls Default Constructor
    car1.show();

    cout << "\nCreating car2 using Parameterized Constructor...\n";
    Car car2("BMW", 200); // Calls Parameterized Constructor
    car2.show();

    cout << "\nCreating car3 using Copy Constructor...\n";
    Car car3 = car2; // Calls Copy Constructor
    car3.show();

    cout << "\nExiting program, destructors will be called...\n";
    return 0; // All destructors are automatically called here
}
