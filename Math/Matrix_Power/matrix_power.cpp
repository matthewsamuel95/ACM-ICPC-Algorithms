#include <iostream>
using namespace std;

const int MaxSize = 2; //It depends on the problem (2 for computing Fibonacci series)
const int mod = 1e9+7; //It depends on the problem as you may don't need it

struct Matrix{
    long long mat[MaxSize][MaxSize];
};

Matrix matMul(Matrix a , Matrix b)
{
    Matrix ans; int k;
    for(int i = 0 ; i < MaxSize ; i++)
        for(int j = 0 ; j < MaxSize ; j++){
           for(ans.mat[i][j] = k = 0 ; k < MaxSize ; k++){
               long long sum = (a.mat[i][k] * b.mat[k][j]) % mod;
               ans.mat[i][j] = (ans.mat[i][j] + sum) % mod;
           }
        }
    return ans;
}

Matrix Identity(){
    Matrix res;
    for(int i = 0 ; i < MaxSize ; i++)
        for(int j = 0 ; j < MaxSize ; j++)
            res.mat[i][j] = (i == j);
    return res;
}
Matrix Power(Matrix base, long long pw)
{
    Matrix ans = Identity();
    while(pw){
        if(pw & 1) ans = matMul(ans , base);
        base = matMul(base, base);
        pw >>= 1;
    }
    return ans;
}

int main(){

    // Matrix Power is a technique not a specific problem
    // So I wrote just the template of its code.


    return 0;
}
