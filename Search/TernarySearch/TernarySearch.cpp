#include<bits/stdc++.h>
using namespace std;

int ternary_search(vector<int> ar,int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        if(ar[mid1] == x)
            return mid1;
        if(ar[mid2] == x)
            return mid2;
        if(x<ar[mid1])
            return ternary_search(ar,l,mid1-1,x);
        else if(x>ar[mid2])
            return ternary_search(ar,mid2+1,r,x);
        else
            return ternary_search(ar,mid1+1,mid2-1,x);

    }
    return -1;
}


int main()
{
   vector <int>v;
   int n;
   cout<<"Enter size of list\n";
   cin>>n;
   int no,k;
   cout<<"Enter nos\n";
   while(n--)
   {
   cin>>no;
   v.push_back(no);
   } 
    cout<<"Enter number you want to search"<<endl;
   
    cin>>k;
    int l=0;
    int r=v.size()-1;
    int found = ternary_search(v,l,r,k);
    if(found == -1)
        std::cout<<"Couldn't find number"<<endl;
     else
     {cout<<"Number is found at position "<<++found;
     }   
    return 0;
}
