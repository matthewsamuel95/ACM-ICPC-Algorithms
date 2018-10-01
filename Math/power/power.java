public class power{
	//driver function
	public static void main(String args[]){
		int base,power;	//base and power values can be replaced by user input
		base = 4;
		power = 3;
		System.out.println(calcPower(base,power));
	}

	private static long calcPower(int base,int power){
		long result = base;
		if(power==0)
		return 1;
		if(power==1)
		return base;
		for(int i=2;i<=power;i++){
			result = result*base;
		}
		return result;
	}
}