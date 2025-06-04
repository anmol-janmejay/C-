// Array 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int main() {
//     // Declaring the Array 
//   string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
// //   Printing the Oth index word 
//   cout << cars[1];
//   return 0;
// }

// Change Array Element
// int main() {
//     // Declaring the Array 
//   string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
// //   Changing the Oth index word
//   cars[0] = "Eicher";
// // Again printing the 0 index
//   cout << cars[0];
//   return 0;
// }


// Loop in an array
// int main(){
//   string cars[5] = {"Volvo","BMW","Nissan","Tata","Kia"};
//   // Loop through Strings
//   for(int i = 0; i < 5; i++){
//   cout << cars[i] << "\n";
//   }
// }


// Vectors: For operation for adding and removing element in an array Vector is used
// The Size of vector is Dynamic, meaning it can grow and shrink as we needed 

// int main(){
//   vector<string> cars = {"Volvo", "Eicher", "Nissan", "Kia", "BMW"};

//   // adding another element to the Vector
//   cars.push_back("Tesla");
//   // Printing all the Element
//   for(int i = 0; i < 6; i++){
//     cout << cars[i] << endl;
//   }
// }


// C++ Array Size 
// int main (){
// int myNumber[5] = {10, 20, 30, 40, 50};
// int getArrayLength = sizeof(myNumber)/ sizeof(myNumber[0]);
// cout << getArrayLength;
// }


// Real life Example of Averaging age of Children
// int main()
// {
//   // An array storing different ages
//   int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};

// float avg, sum = 0;
// int i;

// // Get length of an Array
// int length = sizeof(ages)/sizeof(ages[0]);
// // cout << length;

// for(int age:ages)
//   {
//    sum += age;
//   }

//   // calculating the Average by Dividing the sum by length 
//   avg = sum / length;

//   // Print the Average
//   cout << "The Average is: " << avg << endl;
// }


// To find the lowest age 
// int main()
// {
//   int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};

//   int i;

//  int lowestAge = ages[0];
//  // Loop through the elements of the ages array to find the lowest age
// for (int age : ages){
//   if (lowestAge > age)
//   {
//     lowestAge = age;
//   }
// }
// // Print the Lowest ages
// cout << "The Lowest Age is: " << lowestAge << endl; 
// }

int main()
{
  vector<int> arr(10,-1);
  //  vector<int> arr; properly declares a vector of integers, while vector<int> arr(); declares a function that returns a vector.
  cout << "size of arr " << arr.size() << endl;
  cout << "Capacity of arr " << arr.capacity() << endl;
 
//  This code will tell us what all is stored in our Vector
  for(int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}