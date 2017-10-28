//code for linear Search
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int i,e,in,n;
    vector <int> v;
  
    cout<<"Enter the Number of elements to be inserted in Array : ";
    cin>>n;

    for(i=0;i<n;i++)
        {
            cin>>in;
            v.push_back(in);
        }

    cout<<"Enter the Element to be Search : ";
    cin>>e;

    // implementation of linear search
    for (i = 0; i < v.size(); i++)
    {
        if (e == v[i])
        {
            cout << "Element "<<e<<" at position : " << i + 1 <<endl;
            return 0;
        }
    }
    cout<<"Sorry, Element is not present ";
    return 0;
}
