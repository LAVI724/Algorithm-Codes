#include<stdio.h>
//2021.01.18

int main()
{
    long long int num1, num2;
    while(scanf("%lld%lld", &num1, &num2)!=EOF){
        long long int final=0;
        if(num2>num1){
            long long int tmp;
            tmp=num2;
            num2=num1;
            num1=tmp;
        }
        final=num1-num2;
        printf("%lld\n", final);
    }
    return 0;
}