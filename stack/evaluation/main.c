#include "expression.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Test 1: %d \n",
         eval(convert("((1+2)*3-2^2)"))); // 結果: (1+2)=3 → 3*3=9 → 9-4=5
  printf("Test 2: %d \n",
         eval(convert("(4+5*2)^2"))); // 結果: 5*2=10 → 4+10=14 → 14^2=196
  printf("Test 3: %d \n", eval(convert("7+3*2"))); // 結果: 3*2=6 → 7+6=13
  printf("Test 4: %d \n", eval(convert("1-(3+2)*2")));
  printf("Test 5: %d \n",
         eval(convert("2^3^2"))); // 結果: 3^2=9 → 2^9=512（右結合）
  printf("Test 6: %d \n",
         eval(convert(
             "((8/2)+(3*4))-5"))); // 結果: 8/2=4, 3*4=12 → 4+12=16 → 16-5=11
  printf("Test 7: %d \n", eval(convert("8/(3*(2+1))")));
  printf("Test 8: %d \n",
         eval(convert("((2+3)*(4+1))"))); // 結果: 2+3=5, 4+1=5 → 5*5=25
  printf("Test 9: %d \n",
         eval(convert(
             "5+((1+2)*(3+4))"))); // 結果: 1+2=3, 3+4=7 → 3*7=21 → 5+21=26
  printf("Test 10: %d \n",
         eval(convert("((3+5)/2)^2"))); // 結果: 3+5=8 → 8/2=4 → 4^2=16

  return 0;
}
