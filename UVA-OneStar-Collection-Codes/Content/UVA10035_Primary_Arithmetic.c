#include<stdio.h>
//2021.01.18

int main()
{
    int num1, num2;
    while(scanf("%d%d", &num1, &num2)!=EOF){
        int new1=num1, new2=num2;
        int carry=0, flag=0;
        if(num1==0&&num2==0){
            break;
        }
        while(new1>0||new2>0){
            if(new1%10+new2%10+carry>9){
            flag++;
            carry=1;
            }
            else
            carry=0;
            new1=new1/10;
            new2=new2/10;
        }
        if(flag==0){
            printf("No carry operation.\n");
        }
        if(flag==1){
            printf("1 carry operation.\n");
        }
        if(flag>1){
            printf("%d carry operations.\n", flag);
        }
    }
    return 0;
}