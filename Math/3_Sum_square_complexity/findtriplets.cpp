#include<bits/stdc++.h>
#include<tr1/unordered_set>
#include <string>
#include <sstream>
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
using namespace std;
struct triplet{
    int first, second, third;
};

int findtriplets(int nums[], int n)
{
    int i, j, k;
    vector <triplet> triplets;
    std::tr1::unordered_set <string> uniqTriplets;
    triplet newTriplet;
    sort(nums, nums + n);
    string temp;
    for(i = 0; i < n - 2; i++){

        j = i + 1;

        k = n - 1;

        while(j < k){

            if(nums[i] + nums[j] + nums[k] == 0)
            {
                temp = patch::to_string(nums[i]) + " : "
                     + patch::to_string(nums[j]) + " : "
                             + patch::to_string(nums[k]);
                if(uniqTriplets.find(temp) ==
                                uniqTriplets.end())
                {
                    uniqTriplets.insert(temp);
                    newTriplet.first = nums[i];
                    newTriplet.second = nums[j];
                    newTriplet.third = nums[k];
                    triplets.push_back(newTriplet);
                }

                j++;
                k--;
            }


            else if(nums[i] + nums[j] +
                                 nums[k] > 0)
                k--;


            else
                j++;
        }
    }


    if(triplets.size() == 0)
        return 0;

    for(i = 0; i < triplets.size(); i++)
    {
        cout << "[" << triplets[i].first
            << ", " << triplets[i].second
          << ", " << triplets[i].third <<"], ";
    }
}
int main()
{
    int n;
    cout<<"Number of elements?"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    findtriplets(arr, n);

}
