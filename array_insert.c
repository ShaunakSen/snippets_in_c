#include<stdio.h>
int main(){
int myArray[] = {1,3,5,7,8};
int item = 6;
int k = 2;
int n = 5;
int i, j;
for(i=0;i<n;++i){
printf("\nmyArray[%d] = %d", i, myArray[i]);
}
j=n;
while(k<=j){
myArray[j]=myArray[j-1];
j--;
}
myArray[k] = item;
for(i=0;i<n+1;++i){
printf("\nmyArray[%d] = %d", i, myArray[i]);
}
}
