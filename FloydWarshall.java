import java.util.*;

public class FloydWarshall{
    static final int INF = 999999;

    static void floyd(int[][] d, int V) {
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of offices and lines: ");
        int V = sc.nextInt(), E = sc.nextInt();
        int[][] d = new int[V][V];
        for (int i = 0; i < V; i++) {
            Arrays.fill(d[i], INF);
            d[i][i] = 0;
        }
        System.out.println("Enter each line as: office1 office2 cost");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt(), v = sc.nextInt(), c = sc.nextInt();
            d[u][v] = d[v][u] = c;                     // lines work both ways
        }
        floyd(d, V);
        System.out.println("Minimum cost between all pairs of offices:");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                System.out.print((d[i][j] == INF ? "INF" : d[i][j]) + "\t");
            System.out.println();
        }
        sc.close();
    }
}