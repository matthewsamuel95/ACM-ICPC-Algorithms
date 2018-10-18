public class HammingDistance{
	public static vois main(String args[]){
		System.out.println(getHammingDistance("1011101", "1001001")); # Output 2
		System.out.println(getHammingDistance("Welcome", "welcome")); # Output 0
		System.out.println(getHammingDistance("hacking", "cryptography")) # Output "String are not of equal length."
	}
	
	private static int getHammingDistance(String str1, String str2){
        int distance = 0;
        if (str1.length() != str2.length()) {
            System.out.println("String are not of equal length.");
            System.exit(0);
        } else {            
            for (int i = 0; i < str1.length(); i++) {
                if (str1.toLowerCase().charAt(i) != str2.toLowerCase().charAt(i)) {
                    distance++;
                }
            }            
        }
        return distance;
    }
}
