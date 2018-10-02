#include<stdio.h>
#define int long long int
#undef int

int main()
{
        #define int long long int
        
        int n, m;
        scanf("%d %d", &n, &m);
        char s[n], s1[m];
        scanf("%s%s", s, s1);
        int flag;
        for(int i=0; i<=n-m; i++)
        {       flag=1;
                for(int j=0; j<m; j++)
                {
                        if(s[i+j]!=s1[j])
                        {
                                flag=0;
                                break;
                        }
                }
    
                if(flag==1)
                {
                    printf("yes");
                    break;
                }
        }
        
        if(flag==0)
        {
                printf("no");
        }
        
        return 0;

}
