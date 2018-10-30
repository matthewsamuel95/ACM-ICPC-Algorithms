

import java.util.Stack;

public class MinimumSwapOfBracket {

	public static void main(String[] args) {
		
		String s = "[[][]]";
		boolean bool = isBalanced(s);
		System.out.println(bool);
		

	}
	
	public static boolean isBalanced (String s) {
		Stack<Character> stack = new Stack<>();
		
		for(int i=0 ; i < s.length() ;i++) {
			char ch = s.charAt(i);
			if(ch=='[' || ch== '{' || ch=='(') {
				stack.push(ch);
			}

			if (ch == '}' || ch == ')' || ch == ']')
	          {
	                  
	             if (stack.isEmpty())
	               {
	                   return false;
	               } 
	      
	             else if ( !isMatchingPair(stack.pop(), ch) )
	               {
	                   return false;
	               }
	          }
				
				
				
			}
			
		
		if(stack.isEmpty()) {
			return true;
			
		}else 
			return false;
		
		
	}
	
	public  static boolean isMatchingPair(char character1, char character2)
    {
       if (character1 == '(' && character2 == ')')
         return true;
       else if (character1 == '{' && character2 == '}')
         return true;
       else if (character1 == '[' && character2 == ']')
         return true;
       else
         return false;
    }

}
