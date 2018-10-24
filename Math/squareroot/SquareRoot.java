public class SquareRoot {


  public static void main(String[] args) {
  
    //Number for which square root is to be found
    double number = Double.parseDouble(args[0]);

    //This method finds out the square root
    System.out.println(sqrt(number));

}

/*This method finds out the square root without using
any built-in functions and displays it */

public static double sqrt(int number) {
	double t;
 
	double squareRoot = number / 2;
 
	do {
		t = squareRoot;
		squareRoot = (t + (number / t)) / 2;
	} while ((t - squareRoot) != 0);
 
	return squareRoot;
}
