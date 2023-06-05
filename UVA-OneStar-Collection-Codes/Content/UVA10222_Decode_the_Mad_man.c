#include<stdio.h>
#include<string.h>
//2021.01.27

int main(){
    char num[1000+5];
    while(gets(num)){
        int i, j;
        for(i=0; i<strlen(num); i++){
            if(num[i]=='e'){
                num[i]='q';
            }
            else if(num[i]=='r'){
                num[i]='w';
            }
            else if(num[i]=='t'){
                num[i]='e';
            }
            else if(num[i]=='y'){
                num[i]='r';
            }
            else if(num[i]=='u'){
                num[i]='t';
            }
            else if(num[i]=='i'){
                num[i]='y';
            }
            else if(num[i]=='o'){
                num[i]='u';
            }
            else if(num[i]=='p'){
                num[i]='i';
            }
            else if(num[i]=='['){
                num[i]='o';
            }
            else if(num[i]==']'){
                num[i]='p';
            }
            else if(num[i]=='\\'){
                num[i]='[';
            }
            else if(num[i]=='d'){
                num[i]='a';
            }
            else if(num[i]=='f'){
                num[i]='s';
            }
            else if(num[i]=='g'){
                num[i]='d';
            }
            else if(num[i]=='h'){
                num[i]='f';
            }
            else if(num[i]=='j'){
                num[i]='g';
            }
            else if(num[i]=='k'){
                num[i]='h';
            }
            else if(num[i]=='l'){
                num[i]='j';
            }
            else if(num[i]==';'){
                num[i]='k';
            }
            else if(num[i]=='\''){
                num[i]='l';
            }
            else if(num[i]=='c'){
                num[i]='z';
            }
            else if(num[i]=='v'){
                num[i]='x';
            }
            else if(num[i]=='b'){
                num[i]='c';
            }
            else if(num[i]=='n'){
                num[i]='v';
            }
            else if(num[i]=='m'){
                num[i]='b';
            }
            else if(num[i]==','){
                num[i]='n';
            }
            else if(num[i]=='.'){
                num[i]='m';
            }
            else if(num[i]==' '){
                num[i]=' ';
            }
            else if(num[i]=='2'){
                num[i]='`';
            }
            else if(num[i]=='3'){
                num[i]='1';
            }
            else if(num[i]=='4'){
                num[i]='2';
            }
            else if(num[i]=='5'){
                num[i]='3';
            }
            else if(num[i]=='6'){
                num[i]='4';
            }
            else if(num[i]=='7'){
                num[i]='5';
            }
            else if(num[i]=='8'){
                num[i]='6';
            }
            else if(num[i]=='9'){
                num[i]='7';
            }
            else if(num[i]=='0'){
                num[i]='8';
            }
            else if(num[i]=='-'){
                num[i]='9';
            }
            else if(num[i]=='='){
                num[i]='0';
            }
            else if(num[i]=='/'){
                num[i]=',';
            }
        }
        printf("%s", num);
        printf("\n");
    }
    return 0;
}