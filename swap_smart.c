#include<stdio.h>

int main(){
int a, b;
int *a1, *b1;
a=10;
b=20;
a1 = &a;
b1=&b;
*a1 = *a1 + *b1;
*b1 = *a1 - *b1;
*a1 = *a1 - *b1;
printf("%d %d", *a1, *b1);
return 0;
}
