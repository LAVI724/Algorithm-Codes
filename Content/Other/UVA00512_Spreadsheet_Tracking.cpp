#include<bits/stdc++.h>
using namespace std;
// 2022.09.14 & 19

const int maxn = 100000+5;

struct Inst{
    string ins;
    vector<int> v;

    int r1, c1, r2, c2;
}inst[maxn];

int main(){
    int ca = 1;
    int r, c;
    bool space = false;
    while(cin >> r >> c && r && c){
        int ins;
        cin >> ins;
        
        for(int i = 0; i < ins; ++i){
            cin >> inst[i].ins;
            inst[i].v.clear();

            if(inst[i].ins != "EX"){
                int n;
                cin >> n;

                for(int j = 0; j < n; ++j){
                    int num;
                    cin >> num;
                    inst[i].v.emplace_back(num);
                }
            }
            else{
                cin >> inst[i].r1 >> inst[i].c1 >> inst[i].r2 >> inst[i].c2;
            }
        }

        int q;
        cin >> q;

        if(!space) space = true;
        else cout << endl;
        cout << "Spreadsheet #" << ca++ << endl;
        for(int i = 0; i < q; ++i){
            int ri, ci;
            cin >> ri >> ci;

            bool flag = false;
            int orir = ri, oric = ci;
            for(int j = 0; j < ins && !flag; ++j){
                if(inst[j].ins == "DR"){
                    int tpr = ri;
                    for(int k = inst[j].v.size() - 1; k >= 0; --k){
                        if(inst[j].v[k] < tpr){
                            ri -= 1;
                        }
                        else if(inst[j].v[k] == tpr){
                            flag = true;
                            break;
                        }
                    }
                }
                else if(inst[j].ins == "DC"){
                    int tpc = ci;
                    for(int k = inst[j].v.size() - 1; k >= 0; --k){
                        if(inst[j].v[k] < tpc){
                            ci -= 1;
                        }
                        else if(inst[j].v[k] == tpc){
                            flag = true;
                            break;
                        }
                    }
                }
                else if(inst[j].ins == "IC"){
                    int tpc = ci;
                    for(int k = inst[j].v.size() - 1; k >= 0; --k){
                        if(inst[j].v[k] <= tpc){
                            ci += 1;
                        }
                    }
                }
                else if(inst[j].ins == "IR"){
                    int tpr = ri;
                    for(int k = inst[j].v.size() - 1; k >= 0; --k){
                        if(inst[j].v[k] <= tpr){
                            ri += 1;
                        }
                    }
                }
                else if(inst[j].ins == "EX"){
                    if(inst[j].r1 == ri && inst[j].c1 == ci){
                        ri = inst[j].r2;
                        ci = inst[j].c2;
                    }
                    else if(inst[j].r2 == ri && inst[j].c2 == ci){
                        ri = inst[j].r1;
                        ci = inst[j].c1;
                    }
                }
            }
            if(!flag){
                cout << "Cell data in (" << orir << "," << oric << ") moved to (" << ri << "," << ci << ")" << endl;
            }
            else{
                cout << "Cell data in (" << orir << "," << oric << ") GONE" << endl;
            }
        }
    }
}