import java.util.*;

public class MasterTheorem {
    static void master(double a, double b, double k) {
        double crit = Math.log(a) / Math.log(b);   // log base b of a
        System.out.println("log_b(a) = " + crit);
        if (k < crit - 1e-9)
            System.out.println("Case 1: T(n) = Theta(n^" + crit + ")");
        else if (Math.abs(k - crit) < 1e-9)
            System.out.println("Case 2: T(n) = Theta(n^" + k + " * log n)");
        else
            System.out.println("Case 3: T(n) = Theta(n^" + k + ")");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a, b, k: ");
        double a = sc.nextDouble(), b = sc.nextDouble(), k = sc.nextDouble();
        master(a, b, k);
    }
}