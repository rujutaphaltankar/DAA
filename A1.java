import java.util.*;

public class A1 {
    static void bubble(int[] a) {
        for (int i = 0; i < a.length - 1; i++)
            for (int j = 0; j < a.length - i - 1; j++)
                if (a[j] > a[j + 1]) { int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }
    }

    static void selection(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            int m = i;
            for (int j = i + 1; j < a.length; j++)
                if (a[j] < a[m]) m = j;
            int t = a[i]; a[i] = a[m]; a[m] = t;
        }
    }

    static void insertion(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int key = a[i], j = i - 1;
            while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; j--; }
            a[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter N: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        Random r = new Random();
        for (int i = 0; i < n; i++) a[i] = r.nextInt(10000);
        int[] b = a.clone(), c = a.clone();

        long t = System.nanoTime();
        bubble(a);
        System.out.println("Bubble    : " + (System.nanoTime() - t) / 1e6 + " ms");
        t = System.nanoTime();
        selection(b);
        System.out.println("Selection : " + (System.nanoTime() - t) / 1e6 + " ms");
        t = System.nanoTime();
        insertion(c);
        System.out.println("Insertion : " + (System.nanoTime() - t) / 1e6 + " ms");

        sc.close();
    }
}
