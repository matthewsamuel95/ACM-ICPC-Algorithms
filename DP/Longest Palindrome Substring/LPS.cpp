#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1010;

int memo[MAX][MAX]; 
int lps(const string& s, int i, int j)
{

    if (i > j)
        return 0;

    if (memo[i][j] > -1)
        return memo[i][j];

    if (s[i] == s[j])
    {
        int equalCharacters = 2 - (i == j);
        return memo[i][j] = equalCharacters + lps(s, i + 1, j - 1);
    }
    return memo[i][j] = max( lps(s, i + 1, j), lps(s, i, j - 1) );
}

int longest_palindrome(const string& s)
{

    memset(memo, -1, sizeof memo);
    return lps(s, 0, s.length() - 1);
}

int main()
{

    cout << longest_palindrome("bbabcbcab") << '\n';
    cout << longest_palindrome("abbaab") << '\n';
    cout << longest_palindrome("opengenus") << '\n'; 

    return 0;
}
