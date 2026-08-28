#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    return binarySearch(arr, mid + 1, high, key);
}


void merge(int arr[], int low, int mid, int high) {
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}


long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}


long long sumFactorials(int n) {
    if (n == 0)
        return 0;

    return factorial(n) + sumFactorials(n - 1);
}


long long fibonacci(int n) {
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}


long long sumFibonacci(int n) {
    if (n == 0)
        return 0;

    return fibonacci(n) + sumFibonacci(n - 1);
}


int main() {
    cout << "(a) BINARY SEARCH" << endl;

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter " << n << " sorted elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;


    cout << "\n(b) MERGE SORT" << endl;

    int m;

    cout << "Enter number of elements: ";
    cin >> m;

    int data[100];

    cout << "Enter " << m << " elements: ";

    for (int i = 0; i < m; i++) {
        cin >> data[i];
    }

    cout << "Array before sorting: ";

    for (int i = 0; i < m; i++) {
        cout << data[i] << " ";
    }

    cout << endl;

    mergeSort(data, 0, m - 1);

    cout << "Array after sorting: ";

    for (int i = 0; i < m; i++) {
        cout << data[i] << " ";
    }

    cout << endl;


    cout << "\n(c) SUM OF FIRST N FACTORIALS" << endl;

    int nf;

    cout << "Enter N: ";
    cin >> nf;

    cout << "Sum = " << sumFactorials(nf) << endl;


    cout << "\n(d) SUM OF FIRST N FIBONACCI NUMBERS" << endl;

    int nFib;

    cout << "Enter N: ";
    cin >> nFib;

    cout << "Sum = " << sumFibonacci(nFib) << endl;

    return 0;
}




