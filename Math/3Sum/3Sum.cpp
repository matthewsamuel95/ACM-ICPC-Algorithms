#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if(num.size()<3) return ans;
        		
		sort(num.begin(), num.end());

		for (size_t i = 0; i < num.size() - 2; i++) {
            if(i && num[i]==num[i-1]) continue;
			
            size_t a = i + 1, b = num.size() - 1;
			while (a < b) {
                if(a>i+1 && num[a]==num[a-1])           { a++; continue; }
                if(b<num.size()-1 && num[b]==num[b+1])  { b--; continue; }
				
                int sum2 = num[a] + num[b];
				if (sum2 == -num[i]) {
					int sol[3] = { num[i], num[a], num[b] };
					ans.push_back(vector<int> (sol, sol + 3));
					a++, b--;
				} else if (sum2 < -num[i])
					a++;
				else if (sum2 > num[i])
					b--;
			}
		}
		return ans;
	}
};
