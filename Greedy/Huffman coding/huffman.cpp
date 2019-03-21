#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    
    char value;
    float freq;
    node* right;
    node* left;
};

struct compare{
    bool operator()(const node &n1, const node &n2) const{
        return n1.freq>n2.freq;
    }
};


//IS CORRECT
node * mergeNodes(node *n1, node *n2){
    
    node *n=new node;
    n->freq=n1->freq+n2->freq;
    n->right=n2;
    n->left=n1;
    n->value='~';
    
    return n;
}
void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
    cout<<endl;
}

void codes(node *root, int arr[], int top){
    if(root->left!=NULL){
        arr[top]=0;
        codes(root->left, arr, top+1);
    }
    if(root->right!=NULL){
        arr[top]=1;
        codes(root->right, arr, top+1);
    }
    
    if(root->left==NULL && root->left==NULL){
        
        cout<<root->value<<"\t : ";
        printArr(arr, top);
    }
    
}

int main(){
    
    string s;
    cout<<"Enter String: ";
    cin>>s;
    int n=s.length();
    priority_queue<node, vector<node>, compare> pq;
    
    
    for(int i=0; i<n; i++){
        float count=1;
        if(s[i]!='~'){
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]){
                    count++;
                    s[j]='~';
                }
            }
            node nd;
            nd.value=s[i];
            nd.left=NULL;
            nd.right=NULL;
            nd.freq= (count/float(n));
            
            pq.push(nd);
        }
    }
    
    node *n1, *n2;
    node *root;
    while(pq.size()>1){
        n1=new node;
        n2=new node;
        *n1=pq.top();
        pq.pop();
        *n2=pq.top();
        pq.pop();
        root=mergeNodes(n1,n2);
        pq.push(*root);
    }
    int *arr=new int[100];
    codes(root, arr, 0);
    
    return 0;
}