#include<bits/stdc++.h>
using namespace std;
// 2022.09.28

/*
解題觀念:
數論

將問題簡化為求1~m 0的總數，以及1~n 0的總數，然後最後再相減
求1~n 0的總數，要將n分別算每個位數0的個數，舉例如30324：

先從右邊第一位'4'開始，其左邊為3032，表示1~30320在"第一位"總共有3032*1=3032個0
換第二位數'2'，其左邊為303，表示總共有303*10(右邊有1位)=3030個0
再換第三位數也是一樣，30*100=3000個0，
注意第四位數為'0'，因此原本應該是3*1000，但第3個1000其實只到324而以，所以為2*1000+324+1=2325個0 (+1是因為別忘了0~324是325個)
最後一位'3'，它是最高位數，因此不會有0
所以總共為3032+3030+3000+2325=11387

因此，此演算法從最低位(i==1)開始到最高位(i==k)結束，如果第i位不為0，直接左邊數字x10^(i-1)，如果第i位為0，那麼(左邊數字-1)x10^(i-1)+右邊數字+1，最後把每位數的0總數加起來即可

參考資料:
http://programming-study-notes.blogspot.com/2014/01/uva-11038-how-many-0s.html
*/

int main(){
    long long int n, m;
    while(cin >> n >> m && (n >= 0) && (m >= 0)){
        long long int total1 = 0, total2 = 0;

        long long int ten = 1;
        long long int tmp = n-1;
        while(tmp >= 10){
            if(tmp % 10 == 0){
                tmp /= 10;
                total1 += (tmp - 1) * ten + ((n-1) % ten) + 1;
            }
            else{
                tmp /= 10;
                total1 += tmp * ten;
            }
            ten *= 10;
        }
        

        ten = 1;
        tmp = m;
        while(tmp >= 10){
            if(tmp % 10 == 0){
                tmp /= 10;
                total2 += (tmp - 1) * ten + (m % ten) + 1;
            }
            else{
                tmp /= 10;
                total2 += tmp * ten;
            }
            ten *= 10;
        }

        if(n == 0) total1--;

        cout << total2 - total1 << endl;
    }
}