//Author: Alok Kumar
// C program to check if three
// points are collinear or not
// using area of triangle.

/*Theory:

Three points lie on the straight line if the area formed by the triangle of these three points is zero. So we will check if the area formed by the triangle is zero or not
Formula for area of triangle is :
0.5 * [x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)]
where (x1,y1),(x2,y2),(x3,y3) are the coordinates of vertices of the triangle*/

#include<bits/stdc++.h>
using namespace std;

// function to check if point
// collinear or not
void collinear(int x1, int y1, int x2,
               int y2, int x3, int y3)
{
    // Calculation the area of
    // triangle. We have skipped
    // multiplication with 0.5
    // to avoid floating point
    // computations
    int a = x1 * (y2 - y3) +
            x2 * (y3 - y1) +
            x3 * (y1 - y2);

    if (a == 0)
        printf("Points are collinear");
    else
        printf("Points are non-collinear");
}

// Driver Code
int main()
{
    int x1,y1,x2,y2,x3,y3;
    cout<<"Enter coorinates of first point\n";
    cin>>x1>>y1;
    cout<<"Enter coorinates of second point\n";
    cin>>x2>>y2;
    cout<<"Enter coorinates of third point\n";
    cin>>x3>>y3;
    collinear(x1, y1, x2, y2, x3, y3);
    return 0;
}
