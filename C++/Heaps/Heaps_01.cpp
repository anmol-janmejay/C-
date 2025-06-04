#include <vector>
#include <iostream>
using namespace std;

// // Code for Child and Parent Navigation
// class HeapNavigator
// {
// public:
//     static int parent(int i)
//     {
//         return (i - 1) / 2; // Integer division automatically floors
//     }

//     static int leftChild(int i)
//     {
//         return 2 * i + 1;
//     }

//     static int rightChild(int i)
//     {
//         return 2 * i + 2;
//     }

//     static bool hasParent(int i)
//     {
//         return i > 0;
//     }

//     static bool hasLeftChild(int i, size_t heapSize)
//     {
//         return leftChild(i) < heapSize;
//     }

//     static bool hasRightChild(int i, size_t heapSize)
//     {
//         return rightChild(i) < heapSize;
//     }
// };

// int main()
// {
//     vector<int> maxHeap = {9, 5, 4, 1, 1, 3}; // Example max-heap

//     // Navigate from parent to children
//     int parentIdx = 1;
//     cout << "Parent (" << maxHeap[parentIdx] << ") has children: ";
//     if (HeapNavigator::hasLeftChild(parentIdx, maxHeap.size()))
//     {
//         cout << maxHeap[HeapNavigator::leftChild(parentIdx)] << " ";
//     }
//     if (HeapNavigator::hasRightChild(parentIdx, maxHeap.size()))
//     {
//         cout << maxHeap[HeapNavigator::rightChild(parentIdx)];
//     }
//     cout << "\n";

//     // Navigate from child to parent
//     int childIdx = 4;
//     cout << "Child (" << maxHeap[childIdx] << ") has parent: "
//          << maxHeap[HeapNavigator::parent(childIdx)] << "\n";

//     return 0;
// }

// class Heap
// {
// private:
//     int arr[101]; // Index 1 to 100
//     int size;

// public:
//     Heap() : size(0)
//     {
//         arr[0] = -1; // Sentinel value
//     }

//     void insert(int value)
//     {
//         if (size >= 100)
//         {
//             throw runtime_error("Heap is full");
//         }

//         size++;
//         int index = size;
//         arr[index] = value;

//         // Heapify up
//         while (index > 1)
//         {
//             int parentIndex = index / 2;
//             if (arr[index] > arr[parentIndex])
//             {
//                 swap(arr[index], arr[parentIndex]);
//                 index = parentIndex;
//             }
//             else
//             {
//                 break;
//             }
//         }
//     }

//     int removeMax()
//     {
//         if (size == 0)
//         {
//             throw runtime_error("Heap is empty");
//         }

//         int max = arr[1];
//         arr[1] = arr[size];
//         size--;

//         // Heapify down
//         int index = 1;
//         while (true)
//         {
//             int left = 2 * index;
//             int right = 2 * index + 1;
//             int largest = index;

//             if (left <= size && arr[largest] < arr[left])
//             {
//                 largest = left;
//             }
//             if (right <= size && arr[largest] < arr[right])
//             {
//                 largest = right;
//             }

//             if (largest == index)
//             {
//                 break;
//             }

//             swap(arr[index], arr[largest]);
//             index = largest;
//         }
//         return max;
//     }

//     void printHeap()
//     {
//         cout << "Heap: ";
//         for (int i = 1; i <= size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     Heap h;

//     // Insert initial values
//     h.insert(100);
//     h.insert(50);
//     h.insert(60);
//     h.insert(40);
//     h.insert(45);

//     cout << "Initial heap:" << endl;
//     h.printHeap();
//     cout << endl;

//     // Insert more values
//     h.insert(50);
//     h.insert(30);
//     h.insert(70);
//     h.insert(40);
//     h.insert(80);
//     h.insert(100);

//     cout << "After insertions:" << endl;
//     h.printHeap();
//     cout << endl;

//     h.insert(110);
//     cout << "After inserting 110:" << endl;
//     h.printHeap();
//     cout << endl;

//     // Remove and show max
//     cout << "Removed max: " << h.removeMax() << endl;
//     cout << "Heap after removal:" << endl;
//     h.printHeap();

//     return 0;
// }

void heapify(int arr[], int n, int i)
{
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = index;

    if (leftIndex <= n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }
    if (rightIndex <= n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if (index != largest)
    {
        // left ya right child meh se koi > hogya currentNode se
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        swap(arr[1], arr[n--]);
        heapify(arr, n, 1);
    }
}

int main()
{
    int arr[] = {-1, 12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = 11;
    buildHeap(arr, n);

    cout << "Printing the Heap: " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << endl
         << "Printing the Heap " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}