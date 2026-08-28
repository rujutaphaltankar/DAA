#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons;

// Swap two elements
void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Choose pivot
int choosePivot(int low, int high, int choice) {
    if (choice == 1)
        return low;                       // First element

    if (choice == 2)
        return high;                      // Last element

    if (choice == 3)
        return (low + high) / 2;          // Middle element

    return low + rand() % (high - low + 1); // Random element
}

// Partition
int partition(int a[], int low, int high, int choice) {
    int pivotIndex = choosePivot(low, high, choice);

    // Move pivot to last position
    swapElements(a[pivotIndex], a[high]);

    int pivot = a[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        // Key comparison
        comparisons++;

        if (a[j] < pivot) {
            i++;
            swapElements(a[i], a[j]);
        }
    }

    // Put pivot in correct position
    swapElements(a[i + 1], a[high]);

    return i + 1;
}

// Quick Sort
void quickSort(int a[], int low, int high, int choice) {
    if (low < high) {
        int p = partition(a, low, high, choice);

        quickSort(a, low, p - 1, choice);

        quickSort(a, p + 1, high, choice);
    }
}

// Copy array
void copyArray(int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

// Create random array
void createRandomArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100000;
    }
}

// Create already sorted array
void createSortedArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
}

// Create reverse sorted array
void createReverseArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = n - i;
    }
}

// Test one pivot strategy
void test(int original[], int n, int choice) {
    int a[100000];

    int totalComparisons = 0;
    double totalTime = 0;

    // Three runs
    for (int run = 1; run <= 3; run++) {
        // Fresh copy of the same input
        copyArray(original, a, n);

        comparisons = 0;

        // Start timer immediately before Quick Sort
        clock_t t1 = clock();

        quickSort(a, 0, n - 1, choice);

        // Stop timer immediately after Quick Sort
        clock_t t2 = clock();

        double timeTaken =
            (double)(t2 - t1) / CLOCKS_PER_SEC * 1000000;

        totalComparisons = totalComparisons + comparisons;
        totalTime = totalTime + timeTaken;
    }

    // Average of 3 runs
    cout << totalComparisons / 3 << "\t\t";
    cout << totalTime / 3 << endl;
}

int main() {
    srand(time(0));

    int n;

    cout << "Enter input size n: ";
    cin >> n;

    if (n <= 0 || n > 100000) {
        cout << "Enter n between 1 and 100000." << endl;
        return 0;
    }

    int randomArray[100000];
    int sortedArray[100000];
    int reverseArray[100000];

    // Create the three types of input
    createRandomArray(randomArray, n);
    createSortedArray(sortedArray, n);
    createReverseArray(reverseArray, n);

    cout << "\n============================================";
    cout << "\nQuick Sort Experiment";
    cout << "\nInput Size n = " << n;
    cout << "\n============================================";

    // RANDOM INPUT
    cout << "\n\nRANDOM INPUT";
    cout << "\nPivot\t\tComparisons\tTime (microseconds)";
    cout << "\n------------------------------------------------";

    cout << "\nFirst\t\t";
    test(randomArray, n, 1);

    cout << "Last\t\t";
    test(randomArray, n, 2);

    cout << "Middle\t\t";
    test(randomArray, n, 3);

    cout << "Random\t\t";
    test(randomArray, n, 4);

    // ALREADY SORTED INPUT
    cout << "\n\nALREADY-SORTED INPUT";
    cout << "\nPivot\t\tComparisons\tTime (microseconds)";
    cout << "\n------------------------------------------------";

    cout << "\nFirst\t\t";
    test(sortedArray, n, 1);

    cout << "Last\t\t";
    test(sortedArray, n, 2);

    cout << "Middle\t\t";
    test(sortedArray, n, 3);

    cout << "Random\t\t";
    test(sortedArray, n, 4);

    // REVERSE SORTED INPUT
    cout << "\n\nREVERSE-SORTED INPUT";
    cout << "\nPivot\t\tComparisons\tTime (microseconds)";
    cout << "\n------------------------------------------------";

    cout << "\nFirst\t\t";
    test(reverseArray, n, 1);

    cout << "Last\t\t";
    test(reverseArray, n, 2);

    cout << "Middle\t\t";
    test(reverseArray, n, 3);

    cout << "Random\t\t";
    test(reverseArray, n, 4);

    return 0;
}