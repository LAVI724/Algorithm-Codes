#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//2021.01.26

int cmp(const void *a, const void *b){
    return strcmp((char*)a,(char*)b);
}

int main(){
    int num;
    int i;
    scanf("%d", &num);
    getchar();  //吃enter

    char country[2000+5][75];
    char name[75];
    for(i=0; i<num; i++){
        scanf("%s", country[i]);
        gets(name);  //name不會用到 直接吃
    }
    qsort(country, num, sizeof(char)*75, cmp);  //qsort 排列各國家(按A~Z開頭)
    
    printf("%s", country[0]);
    int count=1;
    for(i=1; i<num; i++){
        if(strcmp(country[i],country[i-1])){
            //如果兩個國家不同 會回傳1 if會執行
            printf(" %d\n", count);
            count=1;
            printf("%s", country[i]);
        }
        else{
            count++;
        }
    }
    printf(" %d", count);
    return 0;
}