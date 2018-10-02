
import java.util.Scanner;

public class nextPowerOf2 {
	
	public static int findP(int n) {
		int p = 1;
		while(p<n) {
			p*=2;
		}
		
		
		return p;
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		System.out.println(findP(n));
		scanner.close();
	}

}
