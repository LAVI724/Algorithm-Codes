#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//2021.01.25

int main(){
    char N[1000+5]; 
    int i;
    int a[1000+5]={0};
    while(scanf("%s", &N)){
        if(strlen(N)==1&&N[0]=='0'){
            break;
        }
        for(i=0; i<strlen(N); i++){
            a[i]=N[i]-'0';
        }
        int odd=0, even=0;
        if(strlen(N)%2!=0){
            for(i=0; i<strlen(N); i=i+2){
                odd=odd+a[i];
            }
            for(i=1; i<strlen(N); i=i+2){
                even=even+a[i];
            }
        }
        else{
            for(i=0; i<strlen(N); i=i+2){
                even=even+a[i];
            }
            for(i=1; i<strlen(N); i=i+2){
                odd=odd+a[i];
            }
        }
        if((odd-even)%11==0){
            printf("%s is a multiple of 11.\n", N);
        }
        else{
            printf("%s is not a multiple of 11.\n", N);
        }
    }
}