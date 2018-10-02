#include<stdio.h>
int main()
{
    int n;//Total numbers;
    scanf("%d",&n);
    int i,count,majorityNo;
    // Majority number is that number which repeats strictly greater than n/2 times in a sequence
    for(i=0;i<n;i++)
    {
	int num;
	scanf("%d",&num);
	//scanning each number
	if(i==0)
	{
	    // first element
	    majorityNo=num;
	    count=1;
	    continue;
	}
	if(num==majorityNo)
	    count++;
	else
	    count--;

	if(count==0)
	{
	    majorityNo=num;
	    count=1;
	}
    }
    printf("Majority No is : %d\n",majorityNo);
    return 0;
}
