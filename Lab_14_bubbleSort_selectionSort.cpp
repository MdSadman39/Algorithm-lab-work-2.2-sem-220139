#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;

// Bubble Sort Function
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort Function
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[MAX_SIZE];
    int n, choice;

    cout << "Enter the size of Array: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Choose sorting method:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        bubbleSort(arr, n);
        cout << "Array sorted using Bubble Sort: ";
    }
    else if (choice == 2)
    {
        selectionSort(arr, n);
        cout << "Array sorted using Selection Sort: ";
    }
    else
    {
        cout << "Invalid choice!" << "\n";
        return 1;
    }

    printArray(arr, n);
    return 0;
}
