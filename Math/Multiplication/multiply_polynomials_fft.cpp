//C++ program to multiply two polynomials. It can also be used to multiply two strings in O(n logn) time.
//The below is the implementation of idea and code provided here : https://cp-algorithms.com/algebra/fft.html

#include <iostream>
#include <complex>
#include <vector>
using namespace std;

const double PI = acos(-1);

//If invert is false, the function computes the fft of given polynomial
//If invert is true, the function computes the inverse fft of given polynomial
void fft(vector< complex<double> >& A, bool invert)
{
    //Size of the vector whose fft is to be computed
    int n = A.size();
    if(n == 1) return;

    vector< complex<double> > A0(n/2), A1(n/2);
    for(int i=0; i*2 < n; i++)
    {
        A0[i] = A[i<<1];
        A1[i] = A[i<<1|1];
    }

    //Recursively compute the fft of polynomial obtained by diving the parent polynomial into two parts
    fft(A0, invert);
    fft(A1, invert);

    double ang = 2*PI/n *(invert ? -1 : 1);
    complex<double> w(1), wn(cos(ang),sin(ang));

    for(int i=0; i*2 < n; i++)
    {
        A[i] = A0[i] + w*A1[i];
        A[i+n/2] = A0[i] - w*A1[i];

        w *= wn;
    }

    if(invert)
    {
        for(int i=0; i<n; i++) A[i]/=2;
    }
}

// The idea is to compute the fft of two polynomial vectors
// and then mulitply the two obtained vectors
// and then convert them back using inverse fft
vector<int> multiply(vector<int> & v1, vector<int>& v2)
{
    int n = 1;
    //max degree of polynomial is equal to product of their highest non zero terms,
    //so for any two polynomails it will always be less than sum of their maximum power
    int max_degree_term = v1.size()+v2.size()-1;

    // find the largest number that is power of two and 
    // which is not smaller than size of any polynomial and store it in 'n'
    while(v1.size()+v2.size() >n) n *= 2;

    //initialize the vectors f1 and f2 with given polynomials
    vector< complex<double> > f1(v1.begin(),v1.end());
    vector< complex<double> > f2(v2.begin(),v2.end());
    //resize both the polynomials to size of 'n' 
    f1.resize(n);
    f2.resize(n);

    //compute the fft of both the polynomials
    fft(f1,0);
    fft(f2,0);

    //multiply both the polynomials using convultion
    for(int i=0;i<n;i++) 
    {
        f1[i] = f1[i]*f2[i];
    }

    //find the inverse fft of polyynomial obtained from multiplication
    fft(f1,1);

    //normalize the co-efficient 
    vector<int> f(n);
    for(int i=0; i<n; i++)
    {
        f[i]=round(f1[i].real());
    }

    //since initially we resized both polynomials to size to power of 2,
    //but all terms greater than max_degree_term is zero so we can resize it
    f.resize(max_degree_term);
    return f;
}

int main()
{
    //max degree of two polynomials
    //the last term in vector is constant, the second last is of degree 1 and so on
    //e.g x^3 + 1 is (1, 0, 0, 1) 
    int n,m;
    cin>>n>>m;

    //input the terms of both the polynomials
    vector<int> v1(n+1), v2(m+1);
    for(int i=0; i<=n; i++) cin>>v1[i];
    for(int i=0; i<=m; i++) cin>>v2[i];

    //perform the multiplication
    vector<int> v = multiply(v1,v2);

    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
}
