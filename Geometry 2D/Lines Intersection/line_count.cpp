// CPP program to count number of straight lines
// with n total points, out of which m are
// collinear.
#include <bits/stdc++.h>

using namespace std;
int nCk(int n, int k)
{

    int C[k+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;  // nC0 is 1

    for (int i = 1; i <= n; i++)
    {

        // Compute next row of pascal triangle
        // using the previous row
        for (int j = min(i, k); j > 0; j--)

            C[j] = C[j] + C[j-1];
    }

    return C[k];
}


int count_Straightlines(int n,int m)
{

    return (nCk(n, 2) - nCk(m, 2)+1);

}

//Main Function
int main()
{

    int n,m;

    while(true)
    {

         cout<<"Enter total number of points and number of collinear points\n";
          cin>>n>>m;
          if(m>n)
          {
            cout<<"Number of collinear points cannot exceed total number of points\n";
            continue;
          }
          else
          {

              break;

          }
    }



    cout<<"Number of straight lines that can be drawn are ";
    cout << count_Straightlines(n, m);
    return 0;

}
