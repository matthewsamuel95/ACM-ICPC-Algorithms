#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct node
{
    bool word_end;
    map<char,node*> m;
};
node* getnode(){
    node* temp = new node;
    temp->word_end =false;
    temp->m = map<char,node*>();
    return temp;
}
node* insert(node* start,string s){
    int i=0,n=s.size();
    for(i=0;i<n;i++)
    {
        map<char,node*>::iterator it = start->m.find(s[i]);
        if(it==start->m.end())
        {
            node* temp = getnode();
            start->m.insert(make_pair(s[i],temp));
            start = temp;
        }
        else
            start = (*it).second;
    }
    start->word_end = true;
}
bool find(node* start,string s){
    int i=0,n=s.size();
    for(i=0;i<n;i++)
    {
        map<char,node*>::iterator it = start->m.find(s[i]);
        if(it==start->m.end())
            return false;
        start = (*it).second;
    }
    if(start->word_end==true)
        return true;
    else 
        return false;
}
bool delete_util(node* start,string s,int begin,int end){
    if(begin==end)
    {
        if(!start->word_end)
            return false;
        else
        {
            if(!start->m.size())
            {
                free(start);
                return true;
            }
            else
                start->word_end = false;
        }
    }
    else
    {
        map<char,node*>::iterator it = start->m.find(s[begin]);
        if(it==start->m.end())
            return false;
        bool temp = delete_util((*it).second,s,begin+1,end);
        if(temp==false)
            return false;
        else
        {
            start->m.erase(s[begin]);
            if(start->m.size()==0)
            {
                free(start);
                return true;
            }
            else
                return false;
        }
    }
}
void delete_node(node* start,string s){
    delete_util(start,s,0,s.size());
}
void level_order(node* start){
    queue<node*> q;
    q.push(start);
    q.push(getnode());
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp->m.size()==0)
        {
            if(q.empty())
                break;
            cout<<"\n";
            q.push(temp);
        }
        else
        {
            map<char,node*>::iterator it = temp->m.begin();
            for(it;it!=temp->m.end();it++)
            {
                cout<<(*it).first;
                node* t = (*it).second;
                if(t->m.size()>0)
                    q.push(t);
            }
            cout<<" ";
        }
    }
}
void print_words(node* start,string s){
    if(start->m.size()==0){
        if(s.size()!=0)
            cout<<s<<"  ";
    }
    for(map<char,node*>::iterator it=start->m.begin();it!=start->m.end();it++)
        print_words((*it).second,s+(*it).first);
}
int main() 
{
    node* start = getnode();
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        insert(start,s);
    }
    //level_order(start);
	
    //To find a something in the trie
	//cout<<find(start,"william")<<"\n";
	
	//To delete from trie
    //delete_node(start,"wilsoni");
    
	//To print all the data from trie
	//print_words(start,"");
	
	return 0;
}

