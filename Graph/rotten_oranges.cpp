#include <iostream>
#include<queue>
using namespace std;
int c;
int r;
void check(queue< pair<int,int> > &q,int a[101][101],int &flag)
{
      pair<int,int> b=q.front();
      int x=b.first;
      int y=b.second;
      
      if(a[x-1][y]==1 && x>=0)
      {
         q.push({x-1,y});
         a[x-1][y]=2;
         if(flag==0)
         {
             flag=1;
         }
      }

      if(a[x+1][y]==1 && x<r)
      {
          q.push({x+1,y});
          a[x+1][y]=2;
          if(flag==0)
          {
              flag=1;
          }
      }

      if(a[x][y+1]==1 && y<c)
      {
          q.push({x,y+1});
          a[x][y+1]=2;
          if(flag==0)
          {
              flag=1;
          }
      }

      if(a[x][y-1]==1 && y>=0)
      {
          q.push({x,y-1});
          a[x][y-1]=2;
          if(flag==0)
          {
              flag=1;
          }
      }

}


int main() {

  ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    cin>>r;
    cin>>c;
    int a[101][101];
    queue< pair<int,int> >q;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];

        if(a[i][j]==2)
        {
            q.push({i,j});
        }

        }
       
    }
      int time=0;
      int flag=0;
      q.push({-1,-1});
      while(!q.empty())
      {
          if(q.front()!=make_pair(-1,-1))
          {
              // we will create check_function
              check(q,a,flag);
              q.pop();
          }
          else if(q.front()==make_pair(-1,-1))
          {
            time=time+flag;
            flag=0;
              q.pop();
              if(q.empty())
              {
                  break;
              }
              else if(!q.empty())
              {
                  q.push({-1,-1});
              }
          }

      }

       // now checking if no present 1
       for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
               if(a[i][j]==1)
               {
                   time=-1;
               }
           }
       }

       cout<<time<<endl;

    }
}
