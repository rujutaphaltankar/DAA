import java.util.*;

public class TSP {
    static int n, INF = 1000000000;
    static int a[][], minOut[];
    static int path[], bestPath[];
    static boolean visited[];
    static long bestCost;

    // Brute Force
    static void brute(int level, int city, long cost) {
        if (level == n) {
            if (a[city][0] != INF && cost + a[city][0] < bestCost) {
                bestCost = cost + a[city][0];
                System.arraycopy(path, 0, bestPath, 0, n);
            }
            return;
        }

        for (int i = 1; i < n; i++) {
            if (!visited[i] && a[city][i] != INF) {
                visited[i] = true;
                path[level] = i;

                brute(level + 1, i, cost + a[city][i]);

                visited[i] = false;
            }
        }
    }

    // Branch and Bound
    static void branchBound(int level, int city, long cost) {
        if (level == n) {
            if (a[city][0] != INF && cost + a[city][0] < bestCost) {
                bestCost = cost + a[city][0];
                System.arraycopy(path, 0, bestPath, 0, n);
            }
            return;
        }

        long bound = cost + minOut[city];

        for (int i = 1; i < n; i++)
            if (!visited[i])
                bound += minOut[i];

        if (bound >= bestCost) return;

        for (int i = 1; i < n; i++) {
            if (!visited[i] && a[city][i] != INF) {
                visited[i] = true;
                path[level] = i;

                branchBound(level + 1, i, cost + a[city][i]);

                visited[i] = false;
            }
        }
    }

    static void run(boolean useBB) {
        visited = new boolean[n];
        path = new int[n];
        bestPath = new int[n];
        bestCost = Long.MAX_VALUE;

        visited[0] = true;
        path[0] = 0;

        long start = System.nanoTime();

        if (useBB)
            branchBound(1, 0, 0);
        else
            brute(1, 0, 0);

        long end = System.nanoTime();

        System.out.println("\n" + (useBB ? "Branch and Bound" : "Brute Force"));

        if (bestCost == Long.MAX_VALUE) {
            System.out.println("No tour exists.");
        } 
        else {
            System.out.print("Optimal tour: ");
            for (int i = 0; i < n; i++)
                System.out.print((bestPath[i] + 1) + " -> ");
            System.out.println("1");
            System.out.println("Minimum cost: " + bestCost);
        }
        System.out.println("Time: " + (end - start) / 1000.0 + " microseconds");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of cities (2-10): ");
        n = sc.nextInt();

        if (n < 2 || n > 10) {
            System.out.println("Enter n between 2 and 10.");
            return;
        }

        a = new int[n][n];
        minOut = new int[n];

        System.out.println("Enter cost matrix (-1 for infinity):");

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
                if (a[i][j] < 0) a[i][j] = INF;
            }

        for (int i = 0; i < n; i++) {
            minOut[i] = INF;

            for (int j = 0; j < n; j++)
                if (i != j && a[i][j] < minOut[i])
                    minOut[i] = a[i][j];
        }

        run(false);
        run(true);

        sc.close();
    }
}
