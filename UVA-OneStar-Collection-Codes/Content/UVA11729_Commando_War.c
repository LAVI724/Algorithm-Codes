#include<stdio.h>

int main(){
    int N;
    int X=1;
    while(scanf("%d", &N)){
        if(N==0){
            break;
        }
        int B[10000+5];
        int J[10000+5];
        int Y=0;
        int i, k;
        int brief=0, longest=0;
        for(i=0; i<N; i++){
            scanf("%d", &B[i]);
            scanf("%d", &J[i]);
            Y=Y+B[i];
        }
        for(i=0; i<N; i++){
            for(k=i; k<N; k++){
                if(J[k]>J[i]){
                    int tmp;
                    tmp=J[k];
                    J[k]=J[i];
                    J[i]=tmp;

                    tmp=B[k];
                    B[k]=B[i];
                    B[i]=tmp;
                }
            }
        }  
        longest=J[0]-(Y-B[0]);
        for(i=0; i<N; i++){
            brief=brief+B[i];
            if(J[i]-(Y-brief)>longest){
                longest=J[i]-(Y-brief);
            }
        }
        printf("Case %d: %d\n", X, Y+longest);
        X=X+1;
    }
    return 0;
}