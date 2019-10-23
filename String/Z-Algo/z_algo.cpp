#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1e5 + 5;

// z[i] = the length of the longest substring of 's' starting at index 'i' which is at the same time a prefix of the string 's'
int z[N];

int n;

void z_func(string &s){			// l, r are the invariant variables => [l,r] is the maximum interval such that s[l,r] is a prefix substring
    int l = 0, r = 0;
    n = s.size();
    for(int i = 1; i < n; i++){
        if(i > r){				// make a new interval l,r and find the substring starting at i which is a prefix substring
            l = r = i;
            while(r < n && s[r - l] == s[r])    r++;
            r--;
            z[i] = r - l + 1;
        }else{					// try to expand the current interval by observing the value of z[k]
            int k = i - l;
            if(z[k] < r - i + 1)    z[i] = z[k];		// can't be more than z[k] since s[i..r] matches with s[k...z[k]]
            else{										// we can expand the current r since z[k] allows us to do so
                l = i;
                while(r < n && s[r - l] == s[r])    r++;
                r--;
                z[i] = r - l + 1;
            }
        }
    }
    return;
}


int main(){
	io;
	string s = "aaaaa";
	z_func(s);
	for(int i = 1; i < s.size(); i++)
		trace(i, z[i]);
	return 0;
}