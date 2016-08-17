#include<stdio.h>


int main(){
int no = 50;
int *p;
p=&no;
printf("Address of no is %x", &no);
printf("\nAddress of p is %x", &p);
printf("\np is %x", p);
printf("\nValue at p is %d", *p);
}
