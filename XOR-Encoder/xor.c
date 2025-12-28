#include<stdio.h>

// a^b^b == a 
//


int main(){
// a = 69^420, b = 420^69^420
  
  int a = 69;
  int b = 420;

  printf("\n%d %d\n", a, b);  
  a ^= b;
  b ^= a;
  a ^= b;

  printf("\n%d %d\n", a, b);
  return 0;

}
