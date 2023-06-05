#include<stdio.h>
#include<string.h>
//2020.12.27.01
//uva10062_tell_me_the_frequencies

int main()
{
    char a[1000]={0};
    int flag=0;

    while(gets(a))
    {
        if(flag==1)
        {
            printf("\n");
        }

        int count[1000]={0};
        
        for(int i=32; i<128; i++)
        {
            for(int j=0; j<=strlen(a); j++)
            {
                if(a[j]==i)
                {
                    count[i]++;
                }
            }
        }
        for(int i=1; i<=strlen(a); i++)
        {
            for(int j=127; j>=32; j--)
            {
                if(count[j]==i)
                {    
                    printf("%d %d\n", j, count[j]);
                    count[j]=0;
                }
            }    
        }

        flag=1;
    }
    return 0;
}