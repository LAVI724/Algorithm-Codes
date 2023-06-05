#include<iostream>
using namespace std;

int main(){
    int N, Q;
    int X=1;
    while(cin>>N>>Q && (N || Q)){
        // if(N==0&&Q==0){
        //     break;
        // }
        int n[10000+5]={0};
        int q[10000+5]={0};
        int i, j;
        for(i=0; i<N; i++){
            cin>>n[i];
        }
        for(i=0; i<Q; i++){
            cin>>q[i];
        }
        for(i=0; i<N; i++){
            for(j=i; j<N; j++){
                if(n[i]>n[j]){
                    int tmp;
                    tmp=n[i];
                    n[i]=n[j];
                    n[j]=tmp;
                }
            }
        }
        printf("CASE# %d:\n", X);
        X++;
        int flag=0;
        for(i=0; i<Q; i++){
            for(j=0; j<N; j++){
                if(q[i]==n[j]){
                    printf("%d found at %d\n", q[i], j+1);
                    flag=0;
                    break;
                }
                else{
                    flag=1;
                }
            }
            if(flag){
                printf("%d not found\n", q[i]);
            }
        }
    }
    return 0;
}