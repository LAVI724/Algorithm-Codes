#include<bits/stdc++.h>
using namespace std;
// 2022/02/12

int main(){
    int c, r;
    cin >> c >> r;

    string check = "RLF";
    string news = "ENWSE";

    int cs, rs;
    string ori, step;
    deque<pair<int, int>> die;
    while(cin >> cs >> rs >> ori >> step){
        
        bool flag = false, check = false;
        for(auto i = 0; i < step.size(); i++){ 
            
            int cx = cs, rx = rs;
            if(step[i] == 'F'){
                if(ori == "N"){
                    rx = rs + 1;
                }
                else if(ori == "E"){
                    cx = cs + 1;
                }
                else if(ori == "W"){
                    cx = cs - 1;
                }
                else{
                    rx = rs - 1;
                }
            }
            else if(step[i] == 'R'){
                if(ori == "E"){
                    ori = news[news.find_last_of(ori) - 1];
                }
                else{
                    ori = news[news.find(ori) - 1];
                }
            }
            else if(step[i] == 'L'){
                ori = news[news.find(ori) + 1];
            }
            if(cx > c || rx > r || cx < 0 || rx < 0){
                for(auto i = 0; i < die.size(); i++){
                    if(cs == die[i].first && rs == die[i].second){
                        cx = cs, rx = rs;
                        check = true;
                        break;
                    }
                }

                if(!flag && !check){
                    die.emplace_back(cs, rs);
                        flag = true;
                        break;
                }
                check = false;
            }
            else{
                flag = false;
                cs = cx, rs = rx;
            }
        }

        cout << cs << " " << rs << " " << ori;
        if(flag){
            cout << " LOST" << endl;
        }
        else{
            cout << endl;
        }
    }
}