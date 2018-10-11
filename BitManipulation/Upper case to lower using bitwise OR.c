#include <stdio.h>
#include <stdlib.h>

/*
Letter    ASCII     Binary
---------------------------
A          65       1000001
a          97       1100001
There is a difference of 32. Hence we OR it with 32 to convert the case
*/
int main()
{
    char c = 'A';
    int x = 32;
    c = c | 32;
    printf("%c\n", c);
}
