#include<stdio.h>
//2021.01.18

int main(){
    int i, j;
    while(scanf("%d%d", &i, &j)!=EOF){
        int k;
        printf("%d %d", i, j);
        if(i>j){
            int tmp;
            tmp=i;
            i=j;
            j=tmp;
        }
        int largest=0;
        for(k=i; k<=j; k++){
            int count=k;
            int flag=0;
            while(count!=1){
                if(count%2!=0){
                    count=count*3+1;
                    flag++;
                }
                else{
                    count=count/2;
                    flag++;
                }
            }
            if(count==1){
                flag++;
                if(flag>largest){
                    largest=flag;
                }
                continue;
            }
        }
        printf(" %d\n", largest);
    }
    return 0;
}