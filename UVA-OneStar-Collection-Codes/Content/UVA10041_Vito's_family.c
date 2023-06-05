#include<stdio.h>
#include<stdlib.h>
//2021.01.18

int compare(const void*a, const void *b){
    return(*(int*)a-*(int*)b);
}
int main(){
    int num1, num2, num3;
    int i, j;
    scanf("%d", &num1);
    for(i=0; i<num1; i++){
        int address[500+5]={0};
        int median=0, total=0;
        scanf("%d", &num2);
        for(num3=0; num3<num2; num3++){
            scanf("%d", &address[num3]);
        }
        qsort(address, num2, sizeof(int), compare);
        if(num2%2==0){
            median=(address[num2/2-1]+address[num2/2])/2;
        }
        else{
            median=address[num2/2];
        }
        for(j=0; j<num2; j++){
            total=total+abs(median-address[j]);
        }
        printf("%d\n", total);
    }
    return 0;
}