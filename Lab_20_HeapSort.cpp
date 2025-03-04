#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void heapyfi(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[largest] < arr[l])
    {
        largest = l;
    }
    if (r < n && arr[largest] < arr[r])
    {
        largest = r;
    }
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapyfi(arr, n, largest);
    }
}
void heap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapyfi(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapyfi(arr, i, 0);
    }
}
int main()
{
    int n;
    cout << "Enter number" << endl;
    cin >> n;
    cout << "Enter array element" << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    heap(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}