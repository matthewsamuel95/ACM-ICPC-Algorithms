#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define all(v) v.begin(),v.end()
#define PI 	3.14159265358979323
#define endl '\n'
#define hashmap unordered_map<char,node*>

using namespace std;

class node{
public:
	char data;
	hashmap h;
	bool isTerminal;
	
	node(char d)
	{
	data=d;
	isTerminal=false;
	}	

};



class Trie{
	
	node *root;
	
	public:
		Trie(){
			root=new node('\0');
		}
		
		void addWord(char* word)
		{
			node * temp=root;
			
			for(int i=0;word[i]!='\0';i++)
			{
				char ch=word[i];
				if(temp->h.count(ch)==0)
				{
					node * child=new node(ch);
					temp->h[ch]=child;
					temp=child;
				}else
				temp=temp->h[ch];
			}
			temp->isTerminal=true;
		}
		
		bool search(char* word)
		{
			node * temp=root;
			
			for(int i=0;word[i]!='\0';i++)
			{
				char ch=word[i];
				if(temp->h.count(ch))
				{
					temp=temp->h[ch];
				}
				else
				return false;
			}
			
			if(temp->isTerminal)
			return true;
			else
			return false;
		}
		
};

int main(){
	//char word[10][100]={"apple","code","vinegar"};
	Trie t;
	t.addWord("vinegar");
	t.addWord("vine");
	t.addWord("cinnamon");
	
	cout<<t.search("vine")<<endl;
	cout<<t.search("ape")<<endl;
	
}


