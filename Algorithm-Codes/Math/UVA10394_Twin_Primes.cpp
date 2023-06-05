#include<bits/stdc++.h>
using namespace std;
// 2022.06.03

bool prime[20000000+5];
vector<int> pri;

void primelist(){
    memset(prime, false, sizeof(prime));

    for(int i = 2; i <= 20000000; i++){
        if(!prime[i]){
            pri.emplace_back(i);
            // 這邊寫的不夠漂亮 應該要 i * i 但是因為會爆所以就這樣寫了
            for(long long int j = i; j <= 20000000; j += i){
                prime[j] = true;
            }
        }
    }
}

vector<pair<int, int>> tp;

void twin_prime(){
    for(int i = 1; i < pri.size(); i++){
        if(pri[i] - pri[i-1] == 2){
            tp.emplace_back(make_pair(pri[i-1], pri[i]));
        }
    }
}

int main(){
    primelist();
    twin_prime();

    int n;
    while(cin >> n){
        cout << "(" << tp[n-1].first << ", " << tp[n-1].second << ")" << endl;
    }
}