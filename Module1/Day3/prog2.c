#include<stdio.h>
void bitprint(unsigned int n){
unsigned int mask=1<<31;
for(int i=0;i<=31;i++){
if(n & mask){
    printf("1");
}
else{
    printf("0");
}
mask>>=1;
if ((n+1)%8==0){
    print(" ");
}
}
printf("\n");
}
void main(){
    unsigned int n;
    printf("enter number\n");
    scanf("%u",&n);
    printf("binary representation:\n")
    bitprint(n);
}
