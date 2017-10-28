#include <iostream>
using namespace std;

int count_one (int n)
    {
        while( n )
        {
        n = n&(n-1);
           count++;
        }
        return count;
}

int main()
{
  int n;
  cin >>n;
  cout << count_one(n) <<endl;
}
