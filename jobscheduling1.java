import java.util.*;

public class jobscheduling1 {
    static void schedule(char id[], int deadline[], int profit[], int n) {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (profit[i] < profit[j]) {
                    int p = profit[i];
                    profit[i] = profit[j];
                    profit[j] = p;

                    int d = deadline[i];
                    deadline[i] = deadline[j];
                    deadline[j] = d;

                    char c = id[i];
                    id[i] = id[j];
                    id[j] = c;
                }

        int max = 0;
        for (int i = 0; i < n; i++)
            max = Math.max(max, deadline[i]);

        char slot[] = new char[max];
        Arrays.fill(slot, '-');
        int total = 0;

        for (int i = 0; i < n; i++)
            for (int j = deadline[i] - 1; j >= 0; j--)
                if (slot[j] == '-') {
                    slot[j] = id[i];
                    total += profit[i];
                    break;
                }

        System.out.print("Scheduled Jobs: ");
        for (int i = 0; i < max; i++)
            if (slot[i] != '-')
                System.out.print(slot[i] + " ");

        System.out.println("\nMaximum Profit: " + total);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of jobs: ");
        int n = sc.nextInt();

        char id[] = new char[n];
        int deadline[] = new int[n];
        int profit[] = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter job ID, deadline, profit: ");
            id[i] = sc.next().charAt(0);
            deadline[i] = sc.nextInt();
            profit[i] = sc.nextInt();
        }
        schedule(id, deadline, profit, n);
        sc.close();
    }
}