/* C++ implementation to convert infix expression to postfix, system takes infix expression from the user as an input */

#include<bits/stdc++.h>
#include <stack>
#include <string>
using namespace std; 

//Function to return precedence of operators 
int prec(char c) 
{ 
	if(c == '$') 
	return 4;
  else if(c == '^') 
	return 3;
	else if(c == '*' || c == '/') 
	return 2; 
	else if(c == '+' || c == '-') 
	return 1; 
	else
	return -1; 
} 

// The main function to convert infix expression 
//to postfix expression 
void infixToPostfix(string s) 
{ 
	stack<char> st; 
	st.push('N'); 
	int l = s.length(); 
	string ns; 
	for(int i = 0; i < l; i++) 
	{ 
		// If the scanned character is an operand, add it to output string. 
		if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
		ns+=s[i]; 

		// If the scanned character is an ‘(‘, push it to the stack. 
		else if(s[i] == '(') 
		
		st.push('('); 
		
		// If the scanned character is an ‘)’, pop and to output string from the stack 
		// until an ‘(‘ is encountered. 
		else if(s[i] == ')') 
		{ 
			while(st.top() != 'N' && st.top() != '(') 
			{ 
				char c = st.top(); 
				st.pop(); 
			ns += c; 
			} 
			if(st.top() == '(') 
			{ 
				char c = st.top(); 
				st.pop(); 
			} 
		} 
		
		//If an operator is scanned 
		else{ 
			while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) 
			{ 
				char c = st.top(); 
				st.pop(); 
				ns += c; 
			} 
			st.push(s[i]); 
		} 

	} 
	//Pop all the remaining elements from the stack 
	while(st.top() != 'N') 
	{ 
		char c = st.top(); 
		st.pop(); 
		ns += c; 
	} 
	
	cout << ns << endl; 

} 

//Driver program to test above functions 
int main() 
{ 
    
	string exp;
	cout << "Please enter the infix expression you need to convert: \n";
	getline (cin,exp);// Get the infrix expression as an input from the user
  /* EXAMPLE OF SOME INFIX EXPRESSIONS : 
  a+b
  (a+b)*c
  (A+B)*(C+D)
  */
	infixToPostfix(exp); 
	return 0; 
} 
 
