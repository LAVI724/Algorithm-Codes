#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//2021.02.05

int main(){
    char str[2000][1000];
    int i, j, k;
    int flag=0;
    for(j=0; j<2000; j++){
        if(gets(str[j])!=NULL){
            j++;
            gets(str[j]);
        }
        else
        break;
    }
        for(k=0; k<j; k++){
            for(i=0; i<strlen(str[k]); i++){
                if(str[k][i]=='"'){
                    if(flag==0){
                       printf("``");
                        flag=1;
                    }
                    else{
                        printf("''");
                        flag=0;
                    }
                }
                else{
                    printf("%c", str[k][i]);
                }
            }
            printf("\n");
        }   
    return 0;
}