// Implementation of Next Power of 2
#include <stdio.h>
#include <math.h>

int nextpow(int n){
    int i=0;
    while(1){
        if(pow(2,i)>=n){
            return pow(2,i);
        }
        else{
            i++;
        }
    }
}

int main()
{
    int n,answer;
    printf("Next Power of 2\n");
    
    // Accept n
    scanf("%d",&n);
    
    answer = nextpow(n);
    
    printf("%d", answer);

    return 0;
}
