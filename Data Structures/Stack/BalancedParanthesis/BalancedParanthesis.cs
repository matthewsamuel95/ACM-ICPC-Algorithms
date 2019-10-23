using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        int t = Convert.ToInt32(Console.ReadLine());
        for(int a0 = 0; a0 < t; a0++){
            string s = Console.ReadLine();
            Console.WriteLine(CheckBalanced(s));
        }
    }
    static string CheckBalanced(string s){
        Stack<char> st=new Stack<char>();
        foreach(char c in s){
            if(c=='[' || c=='{' || c=='(')st.Push(c);
            else{
                if(st.Count==0)return "NO";
                char ch=st.Pop();
                if((ch=='(' && c==')')||(ch=='[' && c==']')||(ch=='{' && c=='}'))continue;
                else return "NO";
            }
        }
        if(st.Count!=0)return "NO";
        return "YES";
    }
}