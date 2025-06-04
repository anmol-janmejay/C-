// #include <iostream>
// using namespace std;

// int main()
// {
//     int a = 5;
//     int *p = &a;
//     int **q = &p;

//     cout << a << endl;
//     cout << &a << endl;
//     cout << p << endl;
//     cout << &p << endl;
//     cout << *p << endl;
//     cout << q << endl;
//     cout << &q << endl;
//     cout << *q << endl;
//     cout << **q << endl;

//     return 0;
// }

// Reference variable
#include <iostream>
using namespace std;

int main()
{
    int x = 10;   // Original variable
    int &ref = x; // Reference variable for x

    cout << "Original x: " << x << endl;
    cout << "Using reference ref: " << ref << endl;

    ref = 20; // Changing value through reference
    cout << "After modifying ref, x: " << x << endl;

    return 0;
}
