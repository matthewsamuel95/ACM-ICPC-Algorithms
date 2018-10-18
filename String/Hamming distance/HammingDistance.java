/**
 *
 * @author ibnahmad
 */
public class HammingDistance {
    public static void main(String args[]) throws Exception{
        
        System.out.println(compareThem("1011101", "1001001")); // Output 2
        System.out.println(compareThem("Welcome", "welcome")); // Output 0
        System.out.println(compareThem("hacking", "cryptography")); // Output "String are not of equal length."
        
    }
        
    
    /**
     *
     * @param strOne
     * @param strTwo
     * @return
     * @throws Exception
     */
    public static int compareThem(String strOne, String strTwo) throws Exception {
        int distance = 0;
        
        if(strOne.length() != strTwo.length()) throw new Exception("String are not of the same length");
        
        if(strOne.equalsIgnoreCase(strTwo)) return distance;
                
        for(int i = 0; i < strOne.length(); i ++ ) {
            if(strOne.charAt(i) != strTwo.charAt(i)) distance++;
        }
        
        return distance;
    }
}
