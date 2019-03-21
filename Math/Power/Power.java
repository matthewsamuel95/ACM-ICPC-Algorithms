import java.util.Scanner;

public class Power {
    public static double power (double x, int n) {
        if (n == 0) {
            return 1.00;
        }
        if (n == 1) {
            return x;
        }
        double ans = power(x, n / 2);
        
        if (n % 2 == 0) {
            return ans * ans;
        } else if (n < 0) {
            return ans * ans / x;
        } else {
            return ans * ans * x;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double n = sc.nextDouble(); int p = sc.nextInt();
        double ans = power(n, p);

        System.out.println(ans);
    }
}
