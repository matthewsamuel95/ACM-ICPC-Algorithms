#include <bits/stdc++.h>
using namespace std;
inline int readInt_neg() {
    int x = 0;
    bool neg=false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch!='-') ch = getchar();
    if (ch=='-'){
        neg=true;
        ch=getchar();
    }
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	if (neg){
        return -x;
	}
    return x;
}
inline int readInt_non_neg() {
    int x = 0;
    bool neg=false;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
    return x;
}
// can replace getchar() with getchar_unlock() if its faster
// this is significantly faster than scanf
int main(){
    printf("%d\n",readInt_non_neg()); //use this for non negative number
    printf("%d\n",readInt_neg()); // use this for negative number
    return 0;
}
