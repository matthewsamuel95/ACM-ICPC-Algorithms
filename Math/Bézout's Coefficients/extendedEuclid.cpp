#include <iostream>
using namespace std;

// Returns the Bezout's coefficients of the smallest positive linear combination of a and b (Diophantine Equation).
// using the extended Euclidean algorithm. (i.e. gcd(a, b) = s.a + t.b).
// O(gcd(a, b)) = O(log(n))
pair<int, int> extendedEuclid(int a, int b) {
    if (b == 0) return { 1, 0 };

    pair<int, int> p = extendedEuclid(b, a % b); // the same as gcd

    int s = p.first;
    int t = p.second;

    return { t, s - t * (a / b) };
}

int gcd(int a, int b) { return (!b ? a : gcd(b,a%b)); }

int main(int argc, char** argv){

    if(argc != 3){
        cerr<<"Usage: extendedEuclid a b.\nWhere a & b are the variables of equation.";
        return 1;
    }

    int a = atoi(argv[1]), b = atoi(argv[2]);
    pair<int,int> ans = extendedEuclid(a,b);
    printf("%d * %d + %d * %d = %d\n", ans.first, a, ans.second, b, gcd(a,b));

    return 0;
}
