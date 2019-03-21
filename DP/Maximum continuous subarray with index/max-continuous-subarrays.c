#include <stdio.h>
int max(int x,int y){
    return x>y? x:y;
}
int main() {
    int n,i,j;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int all_max=arr[0], curr_max=arr[0]; //initial
    int templ,tempr,a_i,l=0,r=0; //initial
    templ=0,tempr=0;
    for(i=1;i<n;i++){
        // curr_max = max(arr[i], curr_max+arr[i]);
        if(arr[i]>curr_max+arr[i]){
            templ=i;
            tempr=i;
            curr_max=arr[i];
        }else{
            tempr++;
            curr_max=curr_max+arr[i];
        }
        // all_max = max(all_max, curr_max);
        if(curr_max>all_max){
            l=templ;
            r=tempr;
            all_max=curr_max;
        }
    }
    printf("%d %d %d", all_max,l,r);
}