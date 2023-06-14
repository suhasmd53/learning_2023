<<<<<<< HEAD
#include<stdio.h>
int big(int a,int b)
{
    if(a>b){
        printf("%d is bigger than %d",a,b);
    }
    else if(b>a){
        printf("%d is bigger than %d",b,a);
    }
    else{
        printf("both are equal");
    }
    return 0;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    big(a,b);
    return 0;
}
=======
#include<stdio.h>
int big(int a,int b)
{
    if(a>b){
        printf("%d is bigger than %d",a,b);
    }
    else if(b>a){
        printf("%d is bigger than %d",b,a);
    }
    else{
        printf("both are equal");
    }
    return 0;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    big(a,b);
    return 0;
}
>>>>>>> dee4349e6f748db3f59c432f947da2f5e1ef879e
