#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    unordered_map<int,int> mapp;
    vector<int> v;
    int n,temp,m;
    bool answer = true;
    cout<<"number of elements in the first array";
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>temp;
        mapp[temp]=1;
    }
    cout<<"number of elements in the second array";
    cin>>m;

    for(int i=0;i<m;i++){
        cin>>temp;
        v.push_back(temp);
    }
    for(int i=0;i<v.size();i++){
        if(mapp[v[i]] == 0){
            answer = false;
            break;
        }
    }
    if(answer == false){
        cout<<"no"<<endl;
    } else {
        cout<<"yes"<<endl;
    }

    return 0;
}