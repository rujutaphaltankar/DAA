#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Linear Search
int linearSearch(int a[], int n, int key, int &cmp)
{
    cmp = 0;

    for (int i = 0; i < n; i++)
    {
        cmp++;

        if (a[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(int a[], int n, int key, int &cmp)
{
    int start = 0, end = n - 1;
    cmp = 0;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        cmp++;

        if (a[mid] == key)
            return mid;

        cmp++;

        if (key < a[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    // Creating a sorted array
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int cmp1, cmp2, pos;

    // Linear Search
    auto start = high_resolution_clock::now();

    pos = linearSearch(arr, n, key, cmp1);

    auto stop = high_resolution_clock::now();

    cout << "\nLinear Search\n";

    if (pos == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at index " << pos << endl;

    cout << "Comparisons: " << cmp1 << endl;
    cout << "Time: "
         << duration_cast<nanoseconds>(stop - start).count()
         << " ns\n";

    // Binary Search
    start = high_resolution_clock::now();

    pos = binarySearch(arr, n, key, cmp2);

    stop = high_resolution_clock::now();

    cout << "\nBinary Search\n";

    if (pos == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at index " << pos << endl;

    cout << "Comparisons: " << cmp2 << endl;
    cout << "Time: "
         << duration_cast<nanoseconds>(stop - start).count()
         << " ns\n";

    // Binary Search on Unsorted Array
    int rev[n];

    for (int i = 0; i < n; i++)
        rev[i] = arr[n - 1 - i];

    int cmp3;

    pos = binarySearch(rev, n, key, cmp3);

    cout << "\nBinary Search on Unsorted Array\n";

    if (pos == -1)
        cout << "Element not found\n";
    else
        cout << "Returned index: " << pos << endl;

    cout << "Comparisons: " << cmp3 << endl;
    cout << "Binary Search works correctly only on sorted arrays.\n";

    return 0;
}