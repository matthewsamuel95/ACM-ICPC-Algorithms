#include <stdio.h>

int getPower(int base, int exponent){
int result=base;
  for (int i = 1; i <= exponent; i++) {
      result=base*result;
  }
  return result;
}
int main(int argc, char const *argv[]) {
int result=getPower(5,5);

printf("Power of the given number is: %d", result);


}
