#include<stdio.h>
//2021.01.26

void change(long long int num){
    if(num>=10000000){
        change(num/10000000);
        printf(" kuti");
        num=num%10000000;
    }
    if(num>=100000){
        if(num>=100000){
            printf(" %lld lakh", num/100000);
        }
        num=num%100000;
    }
    if(num>=1000){
        if(num>=1000){
            printf(" %lld hajar", num/1000);
        }
        num=num%1000;
    }
    if(num>=100){
        if(num>=100){
            printf(" %lld shata", num/100);
        }
        num=num%100;
    }
    if(num!=0){
        printf(" %lld", num);
    }
}

int main(){
    int flag=1;
    long long int num;
    while(scanf("%lld", &num)!=EOF){
        printf("%4d.", flag);
        if(num==0){
            printf(" %d", num);
        }
        change(num);
        printf("\n");
        flag++;
    }
    return 0;
}