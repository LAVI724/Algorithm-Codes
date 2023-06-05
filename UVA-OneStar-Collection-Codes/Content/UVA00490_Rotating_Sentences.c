#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//2021.01.28

int main(){
    char num[100][100]={0};
    int flag=0, count=0;
    int i, j, k;
    for(i=0; i<100; i++){
        if(gets(num[i])!=NULL){
            flag++;
        }
        else{
            break;
        }
    }
    for(i=0; i<flag; i++){
        if(strlen(num[i])>strlen(num[count])){
            count=i;
        }
    }
    for(i=0; i<strlen(num[count]); i++){
        for(j=flag-1; j>=0; j--){
            if(i>=strlen(num[j])){
                printf(" ");
            }
            else{
                printf("%c", num[j][i]);
            }
        }
        printf("\n");
    }
    return 0;
}