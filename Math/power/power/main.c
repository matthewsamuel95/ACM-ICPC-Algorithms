#include <stdio.h>
#include <stdlib.h>

float power(float x, unsigned int y)
{

	if (y == 0)
		return 1;
	else if (y%2 == 0)
		return power(x, y/2)*power(x, y/2);
	else
		return x*power(x, y/2)*power(x, y/2);
}
int main()
{
  float x ;
	 int y ;

	 scanf("%f",&x);
	 scanf("%d",&y);

    if(y<0)
    {
        y=-1*y;
        x=1/x;
    }
	printf("%f", power(x, y));
	return 0;
    return 0;
}
