import java.util.Scanner;

public class MaximumSumIncreasingSubsequence {
    public static int MaximumSumIncreasingSubsequence(int[] A, int n) {
        int max = 0;
        int dp[] = new int[n];

        for (int i = 0; i < n; i++) {
            dp[i] = A[i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[i] < dp[j] + A[i] && A[i] > A[j]) {
                    dp[i] = dp[j] + A[i];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dp[i] > max) {
                max = dp[i];
            }
        }

        return max;
    }

    public static void main(String[] args) {
        //Dynamic Programming approach
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] A = new int[n];

        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }

        System.out.println(MaximumSumIncreasingSubsequence(A, n));
    }
}
