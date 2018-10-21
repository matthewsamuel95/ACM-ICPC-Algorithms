//A simple implementation of DJS using map data structure.
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct node
{
    int data;
    int rank;
    node* parent;
};


map<int,node*> m;

void make_set(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->rank = 0;
    temp->parent = temp;
    m.insert(make_pair(data,temp));
}

node* find_set(node* temp)
{
    if(temp->parent == temp)
        return temp->parent;
    temp->parent = find_set(temp->parent);
    return temp->parent;
}

void union_set(int d1,int d2)
{
    node* t1 = find_set(m[d1]);
    node* t2 = find_set(m[d2]);

    if(t1->data==t2->data)
        return ;
    if(t1->rank>=t2->rank)
    {
        t1->rank = (t1->rank==t2->rank)?(t1->rank+1):(t1->rank);
        t2->parent = t1;
    }
    else
        t1->parent = t2;
}

int main()
{
    int i=0;
    for(i=0;i<=9;i++)
    {
        make_set(i+1);
    }
    union_set(2,1);
    union_set(2,3);
    union_set(3,4);
    union_set(5,6);
    union_set(7,8);
    union_set(3,8);
    union_set(6,8);
    union_set(5,9);

    cout<<find_set(m[9])->data<<" ";
	return 0;
}

