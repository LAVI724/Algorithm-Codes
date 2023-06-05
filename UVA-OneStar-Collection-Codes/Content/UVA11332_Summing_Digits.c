#include<stdio.h>
//2021.01.28

int main(){
    int num;
    while(scanf("%d", &num)){
        if(num==0){
            break;
        }
        int total=0;
        while(num>0){
            while(num>0){
                total=total+(num%10);
                num=num/10;
            }
            if(total>0&&total<10){
                break;
            }
            else{
                num=total;
                total=0;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}