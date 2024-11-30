#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& arr, int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int s = arr.size();
    vector<int> B(s);

    while (i <= mid && j <= h) {
        if (arr[i] < arr[j]) {
            B[k] = arr[i];
            i++;
        } else {
            B[k] = arr[j];
            j++;
        }
        k++;
    }
    //

    while (i <= mid) {
        B[k] = arr[i];
        i++;
        k++;
    }

    while (j <= h) {
        B[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 1; x <=h; x++) {
        arr[x] = B[x];
    }
}

void Merge_Sort(vector<int>& arr, int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        // Recursively sort the first half
        Merge_Sort(arr, l, mid);
        // Recursively sort the second half
        Merge_Sort(arr, mid + 1, h);
        // Merge the two sorted halves
        Merge(arr, l, mid, h);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Merge_Sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
