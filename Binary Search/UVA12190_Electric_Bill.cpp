#include<bits/stdc++.h>
using namespace std;
// 2022.08.06

/*
解題觀念:
binary search

參考資料:
https://mypaper.pchome.com.tw/zerojudge/post/1324931212
*/

int A, B;

// 計算電量錢
long long bill(long long energy){
    long long consume = 0;

    if(energy <= 100){
        return consume + energy * 2;
    }
    consume += 100 * 2;

    if(energy <= 10000){
        return consume + (energy - 100) * 3;
    }
    consume += (10000 - 100) * 3;

    if(energy <= 1000000){
        return consume + (energy - 10000) * 5;
    }
    consume += (1000000 - 10000) * 5;

    return consume + (energy - 1000000) * 7;
}

// 利用二分搜找出對應能量價錢剛好為 A
long long int binary_search_bill(long long int lef, long long int rig){
    if(lef > rig) return 0x3f3f3f3f;

    long long int mid = (lef + rig) >> 1;
    long long int tmp = bill(mid);
    if(tmp == A){
        return mid;
    }
    else if(tmp > A){
        return binary_search_bill(lef, mid - 1);
    }
    else{
        return binary_search_bill(mid + 1, rig);
    }
}

// 利用二分搜尋找出對應能量價錢差剛好為 B
void binary_search_energy(long long int lef, long long int rig, long long int total){
    if(lef > rig) return;

    long long int mid = (lef + rig) >> 1;
    long long int X = bill(mid), Y = bill(total - mid);
    if(Y - X == B){
        cout << X << endl;
        return;
    }
    else if(X > Y || Y - X < B){
        return binary_search_energy(lef, mid - 1, total);
    }
    else{
        return binary_search_energy(mid + 1, rig, total);
    }
}

int main(){
    while(cin >> A >> B && A && B){
        long long int total = binary_search_bill(0, A);
        binary_search_energy(0, total, total);
    }
}