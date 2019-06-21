#include<bits/stdc++.h>
using namespace std;
void dicepermute(int dice);
void dicehelper(int dice,vector<int>&vec);
void dicehelper2(int dice,int sumsofar,int required_sum, vector<int>&vec);
int totalcalls=0;
//Program to print all the permutations of dice rolling
void dicepermute(int dice)
{
    vector<int>vec;
    dicehelper(dice,vec);
}
void dicepermutetosum(int dice,int required_sum)
{   int sumsofar=0;
    vector<int>vec;
    dicehelper2(dice,0,required_sum,vec);
}

void dicehelper(int dice,vector<int>&vec)
{
    totalcalls++;
    if(dice==0)
    {
        for(auto i=vec.begin();i!=vec.end(); i++)
            cout<<(*i)<<" ";
        cout<<endl;
    }

    else{
        for(int i=1;i<=6;i++)
        {
            vec.push_back(i); //Choose
            dicehelper(dice-1,vec); //Explore
            vec.pop_back();  //Unchoose
        }
    }
}


void dicehelper2(int dice,int sumsofar,int required_sum, vector<int>&vec)
{
    totalcalls++;
    if(sumsofar==required_sum) // NOT needed as it will be the last branch of the tree
    {
        for(auto i=vec.begin();i!=vec.end(); i++)
            cout<<(*i)<<" ";
        cout<<endl;
    }

    else{
        for(int i=1;i<=6;i++)
        {
            //too small & too big avoiding  Minimum is less than or equal to required sum
            if(((sumsofar+i+(dice-1)*1)<=required_sum) && (sumsofar+i+(dice-1)*6)>=required_sum ){
            vec.push_back(i);
            dicehelper2(dice-1,sumsofar+i,required_sum,vec);
            vec.pop_back();
            }
        }
    }
}

int main()
{
    int dice=4;
    //dicepermute(dice);
    int requsum=10;
    dicepermutetosum(dice,requsum);
    cout<<"Total calls:"<<totalcalls;


    return 0;
}
