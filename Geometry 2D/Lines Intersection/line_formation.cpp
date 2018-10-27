//Author: Alok Kumar
//Refrences:Geeks for Geeks
// C++ Implementation to find the line passing
// through two points
#include <bits/stdc++.h>
using namespace std;

// This pair is used to store the X and Y
// coordinate of a point respectively
#define pdd pair<double, double>

// Function to find the line given two points
void lineFromPoints(pdd P, pdd Q)
{
    double a = Q.second - P.second;
    double b = P.first - Q.first;
    double c = a*(P.first) + b*(P.second);

    if(b<0)
    {
     cout << "The line passing through points P and Q is: "
         << a << "x " << b << "y = " << c << endl;
    }
    else
    {
     cout << "The line passing through points P and Q is: "
         << a << "x + " << b << "y = " << c << endl;
    }
}

// Driver code
int main()
{
    int x1,y1,x2,y2;
    cout<<"Enter the coordinates of first point\n";
    cin>>x1>>y1;
    cout<<"Enter the coordinates of second point\n";
    cin>>x2>>y2;
    pair<double, double>P;
    pair<double,double>Q;
    P = make_pair(x1, y1);
    Q = make_pair(x2, y2);
    lineFromPoints(P, Q);
    return 0;
}
