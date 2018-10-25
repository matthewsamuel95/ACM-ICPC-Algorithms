#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	struct node *children[26];
	int isLeaf;
	char data;	
}node;


//This function creates a new node and sets the data value to the parameter passed.
node *create(char data){
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = data;
	newNode->isLeaf = 0;
	for(int i=0;i<26;i++)
		newNode->children[i] = NULL;
	return newNode;
}


//Inserts a new string into the trie data structure
void insert(node *root,string s){
	node *temp = root;
	for(int i=0;i<s.length();i++){
		if(temp->children[s[i]-'a'] == NULL)
			temp->children[s[i]-'a'] = create(s[i]);
		temp = temp->children[s[i]-'a'];
	}
	temp->isLeaf = 1;
}


//Searches the trie for a string and returns an appropriate return value.
string search(node *root,string s){
	node *crawl = root;
	int pos = 0;
	while(pos<s.length() && crawl!=NULL){
		crawl = crawl->children[s[pos]-'a'];
		pos++;
	}
	if(crawl == NULL)
		return "not found";
	if(crawl->isLeaf)
		return "found";
	return "not found";
}


//Lists all entries in the trie.
void listall(node *root,string a){
	if(root->isLeaf)
		cout << a << endl;
	for(int i=0;i<26;i++){
		if(root->children[i])
			listall(root->children[i],a+root->children[i]->data);
	}
	return;
}

int main(){
	node *trie = create('a');
	insert(trie,"hello");
	insert(trie,"helloworld");
	insert(trie,"held");
	insert(trie,"goodbye");
	cout << "All entries in the trie are : " << endl;
	listall(trie,"");
	cout << endl;
	cout << "String \"hello\" was " << search(trie,"hello") << endl;
	cout << "String \"helworld\" was " << search(trie,"helworld") << endl;
	return 0;
}