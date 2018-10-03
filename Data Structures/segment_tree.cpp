#include <stdio.h>

using namespace std;

#define MAX (int)10e6

int values[MAX], tree[MAX * 4];

int read(int id, int l, int r, int x, int y){
    if(l > y || r < x) return 0;
    else{
        if(l >= x && r <= y) return tree[id];
        else{
            int mid = (l+r)/2;
            int q1 = read(id*2, l, mid, x, y);
            int q2 = read(id*2+1, mid+1, r, x, y);
            return q1 + q2;
        }
    }
}

void update(int id, int l, int r, int p, int value){
    if(l == r) tree[id] = value;
    else{
        int mid = (l+r)/2;
        if(p <= mid) update(id*2, l, mid, p, value);
        else update(id*2+1, mid+1, r, p, value);
        tree[id] = tree[id*2] + tree[id*2+1];
    }
}

void build(int id, int l, int r){
    if(l == r) tree[id] = values[l];
    else{
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id] = tree[id*2] + tree[id*2+1];
    }
}

int main(){
    int n, q, x, y, opc;
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++) scanf("%d", &values[i]);
    build(1, 1, n);
    while(q--){
        scanf("%d %d %d", &opc, &x, &y);
        if(opc == 1){ //read
            printf("%d\n", read(1, 1, n, x, y));
        }else{ //update
            update(1, 1, n, x, y);
        }
    }
    return 0;
}
