#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> allPermutations(vector<int> list)
{
    vector<vector<int>> result;
    do
    {
        // push each permutation of list into result
        // used STL next_permutation func 
        result.push_back(list);
    } while(next_permutation(list.begin(), list.end()));

    return result;
}

int main()
{
    vector<int> list = {1, 2, 3, 4};
    vector<vector<int>> permutations = allPermutations(list);

    for (vector<int> permutation : permutations)
    {
        for (int i : permutation)   cout << i << " ";
        cout << endl;
    }

    return 0;
}