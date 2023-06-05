#include<stdio.h>
#include<string.h>
//2021.01.28

int main(){
    char str1[1000+5]={0};
    char str2[1000+5]={0};

    while(scanf("%s %s", &str1, &str2)!=EOF){
        int i, j;
        int abc1[26]={0}, abc2[26]={0};
        for(i=0; i<strlen(str1); i++){
            abc1[str1[i]-'a']++;
        }
        for(i=0; i<strlen(str2); i++){
            abc2[str2[i]-'a']++;
        }
        for(i=0; i<26; i++){
            if(abc1[i]!=0&&abc2[i]!=0){
                if(abc1[i]>abc2[i]){
                    for(j=0; j<abc2[i]; j++){
                        printf("%c", i +'a');
                    }
                }
                else{
                    for(j=0; j<abc1[i]; j++){
                        printf("%c", i +'a');
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}