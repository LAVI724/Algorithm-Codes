#include<bits/stdc++.h>
using namespace std;
// 2023.01.13 阿和 110-1/1208

struct Fishing{
    int fish;
    int dec;
    int idx;

    bool operator < (const Fishing &rhs) const{
        if(fish == rhs.fish) return idx > rhs.idx;
        return fish < rhs.fish;
    }
}fishing[25+5];

int main(){
    int n;
    bool space = false;
    while(cin >> n && n){
        if(space) cout << endl;
        space = true;

        int time;
        cin >> time;
        time *= 60/5; // 單位時間 每次 5 分鐘

        int fish[25+5], dec[25+5];
        for(int i = 0; i < n; ++i){
            cin >> fish[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> dec[i];
        }

        int trafficTime[25+5];
        trafficTime[0] = 0;
        for(int i = 1; i < n; ++i){
            cin >> trafficTime[i];
        }
        
        int maxi = -1;
        int ans[25+5];
        for(int i = 0; i < n; ++i){
            priority_queue<Fishing> pq;
            int tmpTime = time;
            for(int j = 0; j <= i; ++j){
                tmpTime -= trafficTime[j];
                if(fish[j] == 0) continue;
                pq.push({fish[j], dec[j], j});
            }

            int tmpTotal = 0, tmpLake[25+5];
            memset(tmpLake, 0, sizeof(tmpLake));
            while(tmpTime > 0 && !pq.empty()){
                Fishing now = pq.top();
                pq.pop();

                tmpTotal += now.fish;
                tmpLake[now.idx] += 5;

                tmpTime -= 1;
                if(now.fish - now.dec <= 0) continue;
                pq.push({now.fish - now.dec, now.dec, now.idx});
            }
            if(tmpTime > 0) tmpLake[0] += (tmpTime * 5);

            if(tmpTotal > maxi){
                for(int j = 0; j < n; ++j) ans[j] = tmpLake[j];
                maxi = tmpTotal;
            }
        }

        cout << ans[0];
        for(int i = 1; i < n; ++i){
            cout << ", " << ans[i];
        }
        cout << endl << "Number of fish expected: " << maxi << endl;
    }
}