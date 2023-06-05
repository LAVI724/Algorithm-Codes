#include<stdio.h>
#include<string.h>
//2021.01.27

int main(){
    int num, a[123]={0};
    char n[1000+5][1000+5];
    int i, j, k;
    scanf("%d", &num);
    getchar();
    for(i=0; i<num; i++){
        gets(n[i]);
    }
    for(i=0; i<num; i++){
        for(j=0; j<strlen(n[i]); j++){
            for(k=65; k<91; k++){
                if(n[i][j]==k){
                    a[k]++;
                }
            }
            for(k=97; k<123; k++){
                if(n[i][j]==k){
                    a[k-32]++;
                }
            }
        }
    }
    int count[91]={0};
    for(i=65; i<91; i++){
        count[i]=i;
    }
    for(i=65; i<91; i++){
        for(k=i; k<91; k++){
            if(a[i]>a[k]){
                int tmp1;
                tmp1=count[i];
                count[i]=count[k];
                count[k]=tmp1;
                int tmp2;
                tmp2=a[i];
                a[i]=a[k];
                a[k]=tmp2;
            }
        }
    }
    for(i=90; i>64; i--){
        for(k=i; k>64; k--){
            if(a[i]==a[k]){
                if(count[i]>count[k]){
                    int tmp1;
                    tmp1=count[i];
                    count[i]=count[k];
                    count[k]=tmp1;
                    int tmp2;
                    tmp2=a[i];
                    a[i]=a[k];
                    a[k]=tmp2;
                }
            }
        }
    }
    for(k=90; k>64; k--){
        if(a[k]!=0){
            printf("%c %d\n", count[k], a[k]);
        }
    }
    return 0;
}