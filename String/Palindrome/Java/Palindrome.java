import java.util.Scanner;

public class Palindrome
{
    int isPalindrome(String st)
    {
        String tmp="";
        int len = st.length();
        for(int i = (len-1); i >= 0 ; i--)
        {
            tmp += st.charAt(i);
        }
        if(st.equals(tmp))
            return 1;
        else
            return 0;
    }
	public static void main(String[] args) {
	    
	    Palindrome m = new Palindrome();
	    int a = 0;
	    Scanner scan = new Scanner(System.in);
	    System.out.println("Enter a String : ");
	    String s = scan.nextLine();
	    a = m.isPalindrome(s);
	    if(a == 0)
	        System.out.println(s + " is not a Palindrome.");
	    else
	        System.out.println(s + " is a Palindrome.");
	}
}
