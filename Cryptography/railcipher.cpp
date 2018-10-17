//It is the code of the Rail Fence Cipher where you will enter the string you want to encypt and also the height of the fence
// and it will Encrypt and decrypt both according to the height of the fence.
//The rail fence cipher (also called a zigzag cipher) is a form of transposition cipher. It derives its name from the way in which it is encoded.
//Author: Mayank a.k.a gozmit
#include <bits/stdc++.h> 
using namespace std; 

// function to encrypt the string and return the result
string encrypt(string s,int n) 
{ 
    int k=s.size();
	string result="";

	char arr[n][k]; // to make the 2D Fence
	for(int i=0;i<n;i++) 
		for(int j=0;j<k;j++) 
			arr[i][j]= '\n'; 
	bool direction=false; 
	int row=0,col=0; 
	for(int i=0;i<k;i++) 
	{ 
		if(row==0||row==n-1) 
			direction = !direction; 
		arr[row][col++] = s[i]; 
		if(direction)
		 row++;
		else
		 row--; 
	} 
	for(int i=0;i<n;i++) 
		for (int j=0;j<k;j++) 
			if (arr[i][j]!='\n') 
				result+=arr[i][j]; 
	return result; 
} 

//function to decrypt the string mentioned in the code
string decrypt(string s, int n) 
{ 
    
    int k=s.size();
	string result="";
	char arr[n][k];  
	for (int i=0;i<n;i++) 
		for (int j=0;j<k;j++) 
			arr[i][j] = '\n'; 
	bool direction; 
	int row = 0, col = 0; 
	for(int i=0;i<k;i++) 
	{ 
		if (row == 0) 
			direction = true; 
		if (row == n-1) 
			direction = false; 
		arr[row][col++] = '*'; 
		if(direction)
		row++;
		else
		row--;
	} 
	int index = 0; 
	for (int i=0;i<n;i++) 
		for(int j=0;j<k;j++) 
			if(arr[i][j] == '*' && index<k) 
				arr[i][j] = s[index++]; 
	row = 0, col = 0; 
	for (int i=0; i< k; i++) 
	{ 
		if (row == 0) 
			direction = true; 
		if (row == n-1) 
			direction = false; 
		if (arr[row][col] != '*') 
			result += arr[row][col++]; 
		if(direction)
		row++;
		else
		row--;
	} 
	return result; 
} 
int main() 
{
    string s,d;
    int n;
    cout<<"Enter the String you want to Cipher:";
    cin>>s;
    cout<<"Enter the height of the tree:";
    cin>>n;
    d=encrypt(s,n);
    cout<<d<<"\n";
    cout<<decrypt(d,n)<<"\n"; 
    return 0; 
} 
