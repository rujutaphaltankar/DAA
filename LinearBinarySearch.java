import java.util.*;

public class LinearBinarySearch {
    static int linearSearch(int a[], int n, int key, int cmp[]) {
        cmp[0] = 0;
        for (int i = 0; i < n; i++) {
            cmp[0]++;
            if (a[i] == key) return i;
        }
        return -1;
    }

    static int binarySearch(int a[], int n, int key, int cmp[]) {
        int start = 0, end = n - 1;
        cmp[0] = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            cmp[0]++;
            if (a[mid] == key) return mid;
            cmp[0]++;
            if (key < a[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }

    static void display(String name, int pos, int cmp[], long time) {
        System.out.println("\n" + name);
        if (pos == -1)
            System.out.println("Element not found");
        else
            System.out.println("Index: " + pos);

        System.out.println("Comparisons: " + cmp[0]);
        System.out.println("Time: " + time + " ns");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        System.out.print("Enter element to search: ");
        int key = sc.nextInt();

        int cmp[] = new int[1];
        long start, end, time;
        int pos;

        start = System.nanoTime();
        pos = linearSearch(arr, n, key, cmp);
        end = System.nanoTime();
        time = end - start;
        display("Linear Search", pos, cmp, time);

        start = System.nanoTime();
        pos = binarySearch(arr, n, key, cmp);
        end = System.nanoTime();
        time = end - start;
        display("Binary Search", pos, cmp, time);

        int rev[] = new int[n];

        for (int i = 0; i < n; i++)
            rev[i] = arr[n - 1 - i];

        pos = binarySearch(rev, n, key, cmp);

        System.out.println("\nBinary Search on Unsorted Array");
        System.out.println("Returned index: " + pos);
        System.out.println("Comparisons: " + cmp[0]);
        System.out.println("Binary Search works correctly only on sorted arrays.");

        sc.close();
    }
}