/*
   Binomial Coeff
 */

#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;

int fact(int);
int coeff(int, int);
bool check(char **, char **);
bool isNum(char *c);

int main(int argc, char *argv[])
{

  if (argc != 3 || check(&argv[1], &argv[2]))
  {
    cout << "How to use\n\t$ ./bc n k\nwith n,k positive integer and n >= k." << endl;
    return -1;
  }

  int n = atoi(argv[1]);
  int k = atoi(argv[2]);

  cout << "With n = " << n
       << " and k = " << k
       << " the binomial coeffivients is "
       << coeff(n, k)
       << endl;

  return 0;
}

int fact(int n)
{
  if (n == 1 || n == 0)
  {
    return 1;
  }
  return n * fact(n - 1);
}

int coeff(int n, int k)
{
  return fact(n) / (fact(k) * fact(n - k));
}

bool check(char **n, char **k)
{
  if ((!isNum(*n) || !isNum(*k)) || atoi(*n) < atoi(*k) || (atoi(*n) < 0 || atoi(*k) < 0))
  {
    return true;
  }
  return false;
}

bool isNum(char *c)
{
  for (int i = 0; c[i]; i++)
  {
    if (!isdigit(c[i]))
    {
      return false;
    }
  }
  return true;
}
