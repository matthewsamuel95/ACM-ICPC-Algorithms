#include <bits/stdc++.h> 
using namespace std; 

struct Job 
{ 
    int start, finish, profit; 
}jobs[100005]; 
  

bool comp(Job a, Job b) 
{ 
    return a.finish < b.finish; 
} 
 
int binarySearch(int index) 
{ 
    int l= 0, h = index - 1; 
    int ans = -1;
    while (l<=h) 
    { 
        int m = (l+h)/2; 
        if (jobs[m].finish <= jobs[index].start) 
        { 
            ans = m;
            l = m+1;
        } 
        else
            h = m-1; 
    } 
    return ans; 
} 
  
//Main function which computes optimal profit
int weighted_job(int n) 
{ 

    sort(jobs, jobs+n, comp); 
    
    int dp[n];

    dp[0] = jobs[0].profit;

    for (int i=1; i<n; i++) 
    { 
        dp[i] = jobs[i].profit; 
        int ind = binarySearch(i); 
        if (ind != -1) 
            dp[i]+=dp[ind]; 
  
        dp[i] = max(dp[i] , dp[i-1]); 
    } 
    return dp[n-1]; 
} 

int main() 
{ 
    int n; //Number of jobs
    cin>>n;
    //Enter the jobs start time,finish time and profit of the job.
    for(int i = 0;i<n;i++){
        cin>>jobs[i].start>>jobs[i].finish>>jobs[i].profit;
    }    
    cout<<"Maximum profit will be "<<weighted_job(n)<<endl;
    return 0; 
} 
