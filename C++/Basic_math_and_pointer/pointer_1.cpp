// #include <iostream>
// using namespace std;

// int main()
// {
//     int x = 5;
//     int *ptr = &x; // Pointer points to x

//     cout << "Value of x: " << x << endl;           // 5
//     cout << "Address of x: " << &x << endl;        // Memory address of x
//     cout << "Pointer value: " << ptr << endl;      // Same as &x
//     cout << "Value via pointer: " << *ptr << endl; // 5

//     *ptr = 10;                               // Modify x via the pointer
//     cout << "New value of x: " << x << endl; // 10

//     return 0;
// }

// Here are the key differences between 32-bit and 64-bit processor architectures explained in 5 points:

// 1. Data Handling Capacity:
//    - 32-bit Processor: Can handle data in chunks of 32 bits at a time. It supports a maximum of **4 GB of RAM** (2³² addresses).
//    - 64-bit Processor: Can handle data in chunks of 64 bits at a time. It supports a theoretical limit of 16 exabytes of RAM (2⁶⁴ addresses), but most modern systems support up to **256 TB** or more.

// 2. Instruction Sets:
//    - 32-bit Processor: Uses 32-bit instruction sets, meaning the processor operates on 32-bit registers, buses, and memory addresses.
//    - 64-bit Processor: Uses 64-bit instruction sets, allowing it to process more data and perform complex calculations faster.

// 3. Performance:
//    - 32-bit Processor: Suitable for basic computing tasks like word processing, web browsing, and older software.
//    -64-bit Processor: Optimized for modern applications, multitasking, video editing, gaming, and running 64-bit operating systems and software.

// 4. Operating System Compatibility:
//    - 32-bit Processor: Can only run 32-bit operating systems and 32-bit applications.
//    - 64-bit Processor: Can run both 64-bit and 32-bit operating systems and applications (with compatibility modes).

// 5. Application Support:
//    - 32-bit Processor: Limited to older software as modern applications increasingly require 64-bit systems.
//   - 64-bit Processor: Required for newer software and advanced technologies like virtualization and large-scale database systems.

// In summary, 64-bit processors are faster, more powerful, and support larger memory sizes, making them better suited for modern computing needs.