/* log2 example */
#include <stdio.h>      /* printf */
#include <math.h>       /* log2 */

int main ()
{
  double param, result;
  param = 1024.0;
  result = log2 (param);
  printf ("log2 (%f) = %f.\n", param, result );
  return 0;
}