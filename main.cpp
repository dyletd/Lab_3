// Project_Lab_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct inputData {
	string mode;
	string algorithm_name;
	int size;
	string output_para;
};

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int main()
{
	clock_t start, end;
    double time_run;
	inputData inputString;
	cin >> inputString.mode >> inputString.algorithm_name >> inputString.size >> inputString.output_para;
	if (inputString.mode == "-c")
		return 0;
	else
	{
		cout << "ALGORITHM MODE \n";
		cout << "Algorithm: " << inputString.algorithm_name << "\n";
		cout << "Input size: " << inputString.size << "\n";

        int* arr = new int[inputString.size];
        for (int i = 0; i < inputString.size; i++)
        {
            *(arr + i) = rand() % (10000 - 3 + 1) + 3;
        }
        start = clock();
        cout << "Before sort: ";
        for (int i = 0; i < inputString.size; i++)
        {
            cout << "[" << *(arr + i) << "] ";
        }
        quickSort(arr, 0, inputString.size - 1);
        cout << "After sort: ";
        for (int i = 0; i < inputString.size; i++)
        {
            cout << "[" << *(arr + i) << "] ";
        }
        cout << "\n";
        end = clock();
        time_run = (double)(end - start)/CLOCKS_PER_SEC;
        cout << "-------------------------------------\n";
        cout << "Running Time (if required): " << time_run << "\n";
        cout << "Comparison (if required): \n";
        return 0;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
