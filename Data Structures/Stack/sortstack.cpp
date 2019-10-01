#include<iostream>
#include<vector>
using namespace std;
template <typename T>
class stack{
    vector<T> v;
public:
    bool isEmpty(){
        return v.size()==0;
    }
    int size(){
        return v.size();
    }
    void push(T data){
        v.push_back(data);
        return;
    }
    void pop(){
        if(!isEmpty()){
            v.pop_back();
        }
        return;
    }
    T top(){
        if(!isEmpty()){
            return v[v.size()-1];
        }
        return NULL;
    }
};
void sort(stack<int>&s){
    if(s.size()==0){
        return;
    }
    if(s.size()==1){
        return;
    }
    int x=s.top();
    s.pop();
    int y=s.top();
    s.pop();
    int max;
    if(x>y){
        max=x;
        s.push(y);
    }else{
        max=y;
        s.push(x);
    }
    sort(s);
    s.push(max);
    return;
}
int main(){
    stack<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    for(int i=0;i<n;i++){
        sort(s);
    }
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

