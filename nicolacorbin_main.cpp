/*
 * Student Name: Nicola Corbin
 * Student ID: 1709990
 *
 * Assignment: Sorting Assignment
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cstring>
#include "nicolacorbin_selectionsort.h"
#include "nicolacorbin_bubblesort.h"
#include "nicolacorbin_insertionsort.h"
#include "nicolacorbin_mergesort.h"
#include "nicolacorbin_quicksort.h"
#include "nicolacorbin_heapsort.h"

void CreateFiles();
void CreateArraysFromFiles();
void CalculateTime (int array[], int n);
void printArray(int array[], int n);

int array1000[1000];
int array4000[4000];
int array8000[8000];
int array10000[10000];
int array40000[40000];
int array80000[80000];
int array100000[100000];
int array400000[400000];
int array800000[800000];
int array1000000[1000000];

int main()
//The main function of the program used for testing sorting functions, calling
//CreateFiles and CreateArraysFromFiles functions as well as calling the
//timing function to time each of the sized arrays in the sorting functions
{

    //TEST THE SORTS USING THE TEST ARRAY PROVIDED:
    //create array for testing
    int A[] = {89, 373, 1, 783, 23, 987, 12, 65, 28, 17};

    //test sorts using a copy of the test array A and print sorted array
    int C[10];

    std::cout << "Beginning algorithm testing.";
    std::copy(A, A+10, C);
    std::cout << "\nSelection Sort Test:\n";
    SelectionSort(C, 10);
    printArray(C, 10);

    std::copy(A, A+10, C);
    std::cout << "\nBubble Sort Test:\n";
    BubbleSort(C, 10);
    printArray(C, 10);

    std::copy(A, A+10, C);
    std::cout << "\nInsertion Sort Test:\n";
    InsertionSort(C, 10);
    printArray(C, 10);

    std::copy(A, A+10, C);
    std::cout << "\nMerge Sort Test:\n";
    MergeSort(C, 10);
    printArray(C, 10);

    std::copy(A, A+10, C);
    std::cout << "\nQuick Sort Test:\n";
    QuickSort(C, 0, 9);
    printArray(C, 10);

    std::copy(A, A+10, C);
    std::cout << "\nHeap Sort Test:\n";
    Heapsort(C, 10);
    printArray(C, 10);
    std::cout << "\n";

    std::cout << "\n";

    CreateFiles();

    CreateArraysFromFiles();

    std::cout << "\n";

    std::cout << "Beginning to calculate times of sorting functions\n";
    std::cout << "1000 Integer array: \n";
    CalculateTime(array1000, 1000);
    std::cout << "4000 Integer array: \n";
    CalculateTime(array4000, 4000);
    std::cout << "8000 Integer array: \n";
    CalculateTime(array8000, 8000);
    std::cout << "10000 Integer array: \n";
    CalculateTime(array10000, 10000);
    std::cout << "40000 Integer array: \n";
    CalculateTime(array40000, 40000);
    std::cout << "80000 Integer array: \n";
    CalculateTime(array80000, 80000);
    std::cout << "100000 Integer array: \n";
    CalculateTime(array100000, 100000);
    std::cout << "400000 Integer array: \n";
    CalculateTime(array400000, 400000);
    std::cout << "800000 Integer array: \n";
    CalculateTime(array800000, 800000);
    std::cout << "1000000 Integer array: \n";
    CalculateTime(array1000000, 1000000);

}

void printArray(int array[], int n)
//Function to print an array passed into the function. Paramaters are an
//integer array and the size of the array as integer n. It assumes that
//the array is full of integers.
{
    int i;

    for (i = 0; i < n; i++)
        std::cout << array[i] << " ";
}

int *SelectionSort(int *array, int n)
//Function to use the selection sort algorithm technique to sort data in an
//array of integers. It takes an integer array and the size of the array
//as integer n as parameters. It assumes that the array is full of integers of
// size n.
{
    int indexMin;

    //loops through the array from index 0 to 1 index from the end of the array.
    for (int i = 0; i < n - 2; i++)
    {
        indexMin = i;
        //loops through the rest of the array comparing each element to find
        //the index smallest value. Assigns the index to indexMin.
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[indexMin])
            {
                indexMin = j;
            }
        }
        //swaps the indexes if it is smaller
        if (indexMin != i)
        {
            std::swap(array[i], array[indexMin]);

        }
    }
    //print array
    /*for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }*/
    return array;
}

int *BubbleSort(int *array, int n)
//Function to use the bubble sort algorithm technique to sort data in an array
//of integers. It takes an integer array and the size of the array as integer
//n as parameters. It assumes the array is full of integers of size n.
{
    //loops through the array from index 0 to 1 fro the end. Inner loop loops
    //through from index 0 to 2 from the end. Moves the bigger value to the end
    //of the array.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j+1], array[j]);
            }
        }
    }
    //print array
    /*for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }*/
    return array;
}


int *InsertionSort(int *array, int n)
//Function to use the insertion sort algorithm technique to sort data in an
//array of integers. It takes an array of integers and the size of the array
//integer n as parameters. Assumes that the array is full of integers of size
//n.
{
    int value;

    //loop through the array from element 1 to the end.
    for (int i = 1; i < n; i++)
    {
        value = array[i];
        int space = i;

        //Move elements of the array, that are greater than the value, to one
        //element ahead of their current position
        while (space > 0 && array[space-1] > value)
        {
            array[space] = array[space-1];
            space = space - 1;
        }
        array[space] = value;
    }
    /*//print out array
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }*/
    return array;
}


void Merge(int leftArray[], int leftLength, int rightArray[], int rightLength,
           int array[])
//Function to put all of the separated arrays together in a sorted manner
//The "conquer" of the mergesort algorithm. Takes 3 integer arrays and size of
//the left array and right array as parameters. It assumes that the arrays are
//full of integers of size rightLength and leftLength.
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < leftLength && j < rightLength)
    {
        //copy the smaller value into the array
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
            k++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
            k++;
        }
    }
    //copy the rest of the elements in leftarray
    while (i < leftLength)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    //copy the rest of the elements in the right array
    while (j < rightLength)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void MergeSort(int array[], int n)
//Function to divide all of the data from and unsorted integer array until it
//is only 1 element using recursion and passing it into the merge function. It
//taken an array of integers and integer n as size of the array as parameters.
// It assumes that the array is full of integers of size n.
{
    int midValue = 0;
    int leftN = 0;
    int rightN = 0;

    //base case when the array is only one element
    if (n <= 1) {
        return;
    }
    else{
        //find the middle
        midValue = n / 2;
        //assign the middle value to the left array size
        leftN = midValue;
        //assign the right array size with the remaining element size from the
        //original array
        rightN = n - midValue;
        //initialize left array
        int* leftArray = new int[leftN];
        //Initialize array to zeros
        memset( leftArray, 0, leftN*sizeof(int) );
        //initialize right array
        int* rightArray = new int[rightN];
        // Initialize array to zeros
        memset( rightArray, 0, rightN*sizeof(int) );

        //copy the values from the array to the left half
        for (int i = 0; i < midValue; i++) {
            leftArray[i] = array[i];
        }

        //copy the values from the array to the right half
        for (int j = midValue; j <= n - 1; j++) {
            rightArray[j - midValue] = array[j];
        }

        //call mergesort for the left half
        MergeSort(leftArray, leftN);
        //call mergesort for the right half
        MergeSort(rightArray, rightN);
        //merge the 2 halves
        Merge(leftArray, leftN, rightArray, rightN, array);

    }
}

int Partition(int array[], int start, int end)
//A function that is part of the quicksort function used to find the partition
//index of the array. It takes the array of integers, the start index and the
//end index as parameters. It assumes that the array is full of integers and
//the start and end index coincide with the array.
{
    //sets pivot index as the last element
    int p = end;
    int pIndex = start;

    //compares the pivot index with the element at i and swaps the smallest
    //element with the element at the pIndex and increments it for each swap
    for (int i = start; i <= end - 1; i++) {
        if (array[i] <= array[p]) {
            std::swap(array[i], array[pIndex]);
            pIndex++;
        }
    }
    //swaps the element at the pivot index with the element at the pIndex
    std::swap(array[p], array[pIndex]);

    return pIndex;
}

void QuickSort(int array[], int left, int right)
//A function that divides an array into right and left halves based on the
//partition index found in the partition function. This function takes an
//array of integers as input, as well as left and right integer values. It
//assumes that the partition function is created and the array is full of
//integers.
{
    int p;

    if (left < right) {
        //find the partition index
        p = Partition(array, left, right);
        //divide the array into left and right halves based on p
        QuickSort(array, left, p - 1);
        QuickSort(array, p + 1, right);
    }
}

void Max_heapify(int array[], int i, int n)
//Make sure the heap has correct order of roots and children and swaps elements
//to make sure the largest is at the root. It takes an array of integers, the
//root element, i as an intger, and the size of the array n as an intger as
//parameters. It assumes that the array is full of integers of size n.
{
    //initializes left node
    int left = 2 * i + 1;
    //initializes right node
    int right = (2 * i) + 2;
    //initializes root node as the largest
    int largest = i;

    //checks to see if the left child is larger than the root and assigns
    //largest to the child if so
    if (left < n && array[left] > array[largest]) {
        largest = left;
    }
    //checks to see if the right child is larger than the root and assigns
    //largest to the child if so
    if (right < n && array[right] > array[largest]) {
        largest = right;
    }
    //if the largest is not the root then it swaps the root with the largest
    if (largest != i)
    {
        std::swap(array[i], array[largest]);
        //calls this function recursively to check the next nodes
        Max_heapify(array, largest, n);
    }

}

void Build_max_heap(int array[], int n)
//A function to build the heap. It takes the an array of integers and an
//integer value n, which is the size of the array. It assumes that max_heapify
//function is complete
{
    //rearranges the array using max_heapify to perform node swaps
    for (int i = n / 2 - 1; i >= 0; i--) {
        Max_heapify(array, i, n);
    }
}

void Heapsort(int array[], int n)
//A function that performs the heapsort. It takes an array of integers and the
//size of the array as an integer as input. It assumes that Build_max_heap
//and Max_heapify functions are complete and the array is full of integers of
//size n.
{
    //builds the heap
    Build_max_heap(array, n);


    for (int i = n - 1; i >= 0; i--) {
        //swaps the root
        std::swap(array[i], array[0]);

        //make sure the root and children are in correct position
        Max_heapify(array, 0, i);
    }
}

void CreateFiles()
//a function to generate 10 unique dataset files of unsorted integers separated
//by a comma. This function does not take any parameters. It assumes that
//<fstream> has been included for file management.
{
    //an array of the size of data for each file
    int fileNums[] = {1000, 4000, 8000, 10000, 40000, 80000, 100000, 400000,
                      800000, 1000000};
    //variable for opening file
    std::ofstream createFile1;
    //number of elements in the file
    int fileArraySize;

    //loops through for each of the 10 files to be created
    for (int j = 0; j < 10; j++)
    {
        //gets the file size from the array
        fileArraySize = fileNums[j];
        //converts this to a string
        std::string fileNumsString = std::to_string(fileArraySize);
        //creates the file name
        std::string fileName = "nicolacorbin_" + fileNumsString + ".txt";
        //creates and opens the file
        createFile1.open(fileName);

        if (createFile1.is_open())
        {
            //adds the correct number of random integers to the file
            for (int i = 0; i < fileArraySize; i++)
            {
                int randNum = rand() % 1000000 + 1;
                createFile1 << randNum << ", ";
            }
            //closes the file
            createFile1.close();
        } else
        {
            std::cout << "Unable to create file\n";
        }
    }

    std::cout << "File creation complete.\n";

}

void CreateArraysFromFiles()
//A function that generates 10 unsorted arrays from the data of files that
//contain integers. No parameters are taken. It assumes that the global integer
//arrays have been declared with adequate size to place the data into. It also
//assumes that <string> and <fstream> have been included.
{
    std::ifstream readFile;
    std::string numComma;
    //std::string delimiter = ",";
    //std::string noComma;
    int num;

    //open the 1000 integer file
    readFile.open("nicolacorbin_1000.txt");
    if (readFile.is_open())
    {
        for (int i = 0; i < 1000; i++)
        {
            //read each number with the comma from the file
            readFile >> numComma;
            //convert string to integer
            num = stoi(numComma);
            //add integer to the array
            array1000[i] = num;
        }
        readFile.close();
    } else
    {
        std::cout << "Error opening file\n";
    }

    //open the 4000 integer file
    readFile.open("nicolacorbin_4000.txt");
    if (readFile.is_open())
    {
        for (int i = 0; i < 4000; i++)
        {
            //read each number with the comma from the file
            readFile >> numComma;
            //convert string to integer
            num = stoi(numComma);
            //add integer to the array
            array4000[i] = num;
        }
        readFile.close();
    } else
    {
        std::cout << "Error opening file\n";
    }

    //open the 8000 integer file
    readFile.open("nicolacorbin_8000.txt");
    if (readFile.is_open())
    {
        for (int i = 0; i < 8000; i++)
        {
            //read each number with the comma from the file
            readFile >> numComma;
            //convert string to integer
            num = stoi(numComma);
            //add integer to the array
            array8000[i] = num;
        }
        readFile.close();
    } else
    {
        std::cout << "Error opening file\n";
    }

    //open the 10000 integer file
    readFile.open("nicolacorbin_10000.txt");
    if (readFile.is_open())
    {
        for (int i = 0; i < 10000; i++)
        {
            //read each number with the comma from the file
            readFile >> numComma;
            //convert string to integer
            num = stoi(numComma);
            //add integer to the array
            array10000[i] = num;
        }
        readFile.close();
    } else
    {
        std::cout << "Error opening file\n";
    }

    //open the 40000 integer file
    readFile.open("nicolacorbin_40000.txt");
    if (readFile.is_open())
    {
        for (int i = 0; i < 40000; i++)
        {
            //read each number with the comma from the file
            readFile >> numComma;
            //convert string to integer
            num = stoi(numComma);
            //add integer to the array
            array40000[i] = num;
        }
        readFile.close();
    } else
    {
        std::cout << "Error opening file\n";
    }

    //open the 80000 integer file
    readFile.open("nicolacorbin_80000.txt");
    if (readFile.is_open())
    {
        for (int i = 0; i < 80000; i++)
        {
            //read each number with the comma from the file
            readFile >> numComma;
            //convert string to integer
            num = stoi(numComma);
            //add integer to the array
            array80000[i] = num;
        }
        readFile.close();
    } else
    {
        std::cout << "Error opening file\n";
    }

    //open the 100000 integer file
    readFile.open("nicolacorbin_100000.txt");
    if (readFile.is_open())
    {
        for (int i = 0; i < 100000; i++)
        {
            //read each number with the comma from the file
            readFile >> numComma;
            //convert string to integer
            num = stoi(numComma);
            //add integer to the array
            array100000[i] = num;
        }
        readFile.close();
    } else
    {
        std::cout << "Error opening file\n";
    }

    //open the 400000 integer file
    readFile.open("nicolacorbin_400000.txt");
    if (readFile.is_open())
    {
        for (int i = 0; i < 400000; i++)
        {
            //read each number with the comma from the file
            readFile >> numComma;
            //convert string to integer
            num = stoi(numComma);
            //add integer to the array
            array400000[i] = num;
        }
        readFile.close();
    } else
    {
        std::cout << "Error opening file\n";
    }

    //open the 800000 integer file
    readFile.open("nicolacorbin_800000.txt");
    if (readFile.is_open())
    {
        for (int i = 0; i < 800000; i++)
        {
            //read each number with the comma from the file
            readFile >> numComma;
            //convert string to integer
            num = stoi(numComma);
            //add integer to the array
            array800000[i] = num;
        }
        readFile.close();
    } else
    {
        std::cout << "Error opening file\n";
    }

    //open the 1000000 integer file
    readFile.open("nicolacorbin_1000000.txt");
    if (readFile.is_open())
    {
        for (int i = 0; i < 1000000; i++)
        {
            //read each number with the comma from the file
            readFile >> numComma;
            //create string without the comma
            //noComma = numComma.substr(0, numComma.find(delimiter));
            //convert string to integer
            num = stoi(numComma);
            //add integer to the array
            array1000000[i] = num;
        }
        readFile.close();
    } else
    {
        std::cout << "Error opening file\n";
    }
    std::cout << "Unsorted array generation complete.\n";
}

void CalculateTime (int array[], int n) {
//A function that calculates the time taken to run an array through each
//sorting algorithm three times and calculates the average time. This can also
//print the arrays, but this is commented out. It takes an integer array and
//size of the array, integer n, as parameters. It assumes that <chrono> has
//been included for time keeping, all of the sorting algorithms are complete,
//and the array is full of integers of size n.
    long cumulativeTime = 0;
    int arrayB[n];

    //selectionSort
    for (int i = 0; i < 3; i++)
    {
        //copy original array into another array to pass into function
        std::copy(array, array + n, arrayB);
        //start timer
        auto start = std::chrono::high_resolution_clock::now();
        //call function
        SelectionSort(arrayB, n);
        //stop timer
        auto stop = std::chrono::high_resolution_clock::now();
        //get duration of function
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
                (stop - start).count();
        //cumulate the time
        cumulativeTime = cumulativeTime + duration;
        std::cout << "Selection sort function time " << i + 1 << ": "
        << duration << "\n";
    }
    //print the sorted array:
    //printArray(arrayB, n);

    long average = 0;
    //calculate the average over 3 runs
    average = cumulativeTime / 3;
    std::cout << "Average: " << average << " milliseconds\n\n";

    cumulativeTime = 0;

    //bubbleSort
    for (int i = 0; i < 3; i++)
    {
        //copy original array into another array to pass into function
        std::copy(array, array + n, arrayB);
        //start timer
        auto start = std::chrono::high_resolution_clock::now();
        //call function
        BubbleSort(arrayB, n);
        //end timer
        auto stop = std::chrono::high_resolution_clock::now();
        //calculate function duration
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
                (stop - start).count();
        //cumulate the time
        cumulativeTime = cumulativeTime + duration;
        std::cout << "Bubble sort function time " << i + 1 << ": " << duration
        << "\n";
    }
    //print the sorted array:
    //printArray(arrayB, n);

    average = 0;
    //calculate average over 3 runs
    average = cumulativeTime / 3;
    std::cout << "Average: " << average << " milliseconds\n\n";

    cumulativeTime = 0;

    //insertionSort
    for (int i = 0; i < 3; i++)
    {
        //copy original array into another array to pass into function
        std::copy(array, array + n, arrayB);
        //start timer
        auto start = std::chrono::high_resolution_clock::now();
        //call function
        InsertionSort(arrayB, n);
        //stop timer
        auto stop = std::chrono::high_resolution_clock::now();
        //calculate function duration
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
                (stop - start).count();
        //cumulate the time
        cumulativeTime = cumulativeTime + duration;
        std::cout << "Insertion sort function time " << i + 1 << ": " << duration
        << "\n";
    }
    //print the sorted array:
    //printArray(arrayB, n);

    average = 0;
    //calculate the average over 3 runs
    average = cumulativeTime / 3;
    std::cout << "Average: " << average << " milliseconds\n\n";

    cumulativeTime = 0;

    //MergeSort
    for (int i = 0; i < 3; i++)
    {
        //copy original array into another array to pass into function
        std::copy(array, array + n, arrayB);
        //start timer
        auto start = std::chrono::high_resolution_clock::now();
        //call function
        MergeSort(arrayB, n);
        //stop timer
        auto stop = std::chrono::high_resolution_clock::now();
        //calculate function duration
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
                (stop - start).count();
        //cumulate the time
        cumulativeTime = cumulativeTime + duration;
        std::cout << "Merge sort function time " << i + 1 << ": " << duration
        << "\n";
    }

    //print the sorted array:
    //printArray(arrayB, n);
    average = 0;
    //calculate the average over 3 runs
    average = cumulativeTime / 3;
    std::cout << "Average: " << average << " milliseconds\n\n";

    cumulativeTime = 0;

    //QuickSort
    for (int i = 0; i < 3; i++)
    {
        //copy original array into another array to pass into function
        std::copy(array, array + n, arrayB);
        //start timer
        auto start = std::chrono::high_resolution_clock::now();
        //call function
        QuickSort(arrayB, 0, n-1);
        //stop timer
        auto stop = std::chrono::high_resolution_clock::now();
        //calculate function duration
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
                (stop - start).count();
        //cumulate the time
        cumulativeTime = cumulativeTime + duration;
        std::cout << "Quick sort function time " << i + 1 << ": " << duration
        << "\n";
    }

    //print the sorted array:
    //printArray(arrayB, n);
    average = 0;
    //calculate the average over 3 runs
    average = cumulativeTime / 3;
    std::cout << "Average: " << average << " milliseconds\n\n";

    cumulativeTime = 0;


    //HeapSort
    for (int i = 0; i < 3; i++)
    {
        //copy original array into another array to pass into function
        std::copy(array, array + n, arrayB);
        //start timer
        auto start = std::chrono::high_resolution_clock::now();
        //call function
        Heapsort(arrayB, n);
        //stop timer
        auto stop = std::chrono::high_resolution_clock::now();
        //calculate function duration
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
                (stop - start).count();
        //cumulate the time
        cumulativeTime = cumulativeTime + duration;
        std::cout << "Heap sort function time " << i + 1 << ": " << duration
        << "\n";
    }
    //print the sorted array:
    //printArray(arrayB, n);

    average = 0;
    //calculate the average over 3 runs
    average = cumulativeTime / 3;
    std::cout << "Average: " << average << " milliseconds\n\n";

}