#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;
int a[MAXN];
vector<int> b[320];

int main(){
    io;
    int n;
    cin >> n;
    int sqrtn = sqrt(n);
    for(int i = 0;i < n; i++){
    	cin >> a[i];
    	b[i/sqrtn].push_back(a[i]);
    }
    int numBlocks = ceil((double)n/sqrtn);
    for(int i = 0;i < numBlocks; i++)
    	sort(b[i].begin(), b[i].end());
    int q;
    cin >> q;
    int answer = 0;
    while(q--){
    	int l, r, x;
    	cin >> l >> r >> x;
    	l ^= answer;
    	r ^= answer;
    	x ^= answer;
    	if(l < 1)
    		l = 1;
    	if(r > n)
    		r = n;
    	l--;r--;
	    answer = 0;
    	if(r >= l){
	    	int leftBlock = l/sqrtn;
	    	int rightBlock = r/sqrtn;
	    	if(leftBlock == rightBlock){
	    		for(int i = l; i <= r; i++){
	    			if(a[i] > x)
	    				answer++;
	    		}
	    	}else{
	    		if(l%sqrtn != 0){
	    			leftBlock++;
	    		}
	    		int i;
	    		for(i = l; i < leftBlock*sqrtn; i++){
	    			if(a[i] > x)
	    				answer++;
	    		}
	    		while(i+sqrtn-1 <= r){
	    			int bb = i/sqrtn;
	    			answer += b[bb].end() - upper_bound(b[bb].begin(), b[bb].end(), x);
	    			i += sqrtn;
	    		}
	    		while(i <= r){
	    			if(a[i] > x)
	    				answer++;
	    			i++;
	    		}
	    	}
	    }
	    cout << answer << endl;
    }
    return 0;
}