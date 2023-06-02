#include<bits/stdc++.h>
using namespace std;
// 2023.01.10 阿和 110-1/1020

const int maxn = 20000+5;
const int shift = 10000; // 因為要讀取負的陣列 所以把大家都平移 10000
int adv[maxn];

struct Range{
    int start;
    int end;

    bool operator < (const Range &rhs) const{
        if(end == rhs.end) return start > rhs.start;
        return end < rhs.end;
    }
}range[1000+5];

int main(){
    int t;
    cin >> t;

    bool space = false;
    while(t--){
        if(space) cout << endl;
        space = true;
        
        int k, n;
        cin >> k >> n;

        memset(range, 0, sizeof(range));
        for(int i = 0; i < n; ++i){
            cin >> range[i].start >> range[i].end;
            if(range[i].end < range[i].start) swap(range[i].end, range[i].start);
        }
        sort(range, range + n);
        
        memset(adv, 0, sizeof(adv));
        set<int> st;
        int advTotal = 0;
        for(int i = 0; i < n; ++i){
            int start = range[i].start, end = range[i].end;
            int seenAdv = 0;

            for(int j = start; j <= end; ++j){
                if(adv[j + shift]) seenAdv++;
            }

            for(int j = end; j >= start && seenAdv < k; --j){
                if(!adv[j + shift]){
                    adv[j + shift] = 1;
                    seenAdv++;
                    advTotal++;
                    st.insert(j);
                }
            }
        }

        cout << advTotal << endl;
        for(auto it = st.begin(); it != st.end(); ++it){
            cout << *it << endl;
        }
    }
}