//Lauren Shugrue
//C++ program to sort an array using different methods

#include <iostream>
#include <cstdlib>


using namespace std;
//function prototypes
int bubbleSort(int array[], int size);
void swap(int &a, int &b);
int selectionSort(int array[], int size);
int insertionSort(int array[], int size);
void printArray(int array[], int size);
//declare constant
const int SIZE = 20;

int main()
{
    int numbers[SIZE] = {26,45,56,12,78,74,39,22,5,90,87,32,28,11,93,62,79,53,22,51};//declare array contents

    //call functions
    printArray(numbers, SIZE);
    bubbleSort(numbers, SIZE);

    printArray(numbers, SIZE);
    selectionSort(numbers, SIZE);

    printArray(numbers, SIZE);
    insertionSort(numbers, SIZE);

    system("Pause");
    return 0;
}//end main

void printArray(int array[], int size)//function to loop and print each item in array
{
    cout << "Original order: "<< endl; //display text heading
    for ( int i = 0; i < size; i++ )
    {
        cout << array[i] <<' ';
    }
    cout << endl;
}//end printArray()

int bubbleSort(int array[], int size)//module using bubble sort on an array
{
    int maxElement;  // Marks the last element to compare
    int index;       // Index of an element to compare
    int swapCount = 0;//set counter to 0

    for (maxElement = size - 1; maxElement >= 0; maxElement--)
    {
        for (index = 0; index <= maxElement - 1; index++)
        {
            if (array[index] > array[index + 1])
            {
                swap(array[index], array[index + 1]);
                swapCount++;
            }
        }
    }
    cout << "Bubble Sorted: "<<endl;//display sorted array
    for (int i = 0; i < size; i++)
       {
         cout << array[i] <<' ';
       }
    cout << "\nNumber of location swaps: "<<swapCount<< endl;//display number of swaps for bubble sort
    cout << endl;
    return 0;
}  //end bubbleSort()

int selectionSort(int array[], int size)//module using selection sort on an array
{
    int startScan;   // Starting position of the scan
    int index;       // To hold a subscript value
    int minIndex;    // Element with smallest value in the scan
    int minValue;    // The smallest value found in the scan
    int swapCount = 0;//Initialize counter to 0

    for (startScan = 0; startScan < (size-1); startScan++)//begin scan loop
    {
        minIndex = startScan;
        minValue = array[startScan];

        for(index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[startScan]);
        swapCount++;
    }//end scan loop
    cout << "Selection Sorted: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] <<' ';
    }
    cout << "\nNumber of location swaps: "<<swapCount<< endl;//display number of swaps for selection sort
    cout << endl;
    return 0;
}  //end selectionSort()

int insertionSort(int array[], int size)//module using insertion sort on an array
{
    int unsortedValue;  // The first unsorted value
    int scan;           // Used to scan the array
    int swapCount = 0;  //Initialize counter to 0

    for (int index = 1; index < size; index++)//begin scanning loop
    {
        unsortedValue = array[index];
        scan = index;

        while (scan > 0 && array[scan-1] > unsortedValue)
        {
            array[scan] = array[scan - 1];
            scan--;
        }
        array[scan] = unsortedValue;
        swapCount++;
    }//end scanning loop

    cout << "Insertion Sorted: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] <<' ';
    }
    cout << "\nNumber of location swaps: "<<swapCount<< endl;//display number of swaps for insertion sort
    cout << endl;
    return 0;
}  //end insertionSort()

void swap(int &a, int &b)//module for swap
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}  //end swap()


