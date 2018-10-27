# include<stdio.h> 
  
int multiplyBySeven(unsigned int n) 
{   
    /* Note the inner bracket here. This is needed  
       because precedence of '-' operator is higher  
       than '<<' */
    return ((n<<3) - n); 
} 
  
/* Driver program to test above function */
int main() 
{ 
    unsigned int n ;
    scanf("%d",&n); 
    printf("%u", multiplyBySeven(n)); 
  
    getchar(); 
    return 0; 
} 
