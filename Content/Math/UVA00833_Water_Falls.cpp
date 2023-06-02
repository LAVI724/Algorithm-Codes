#include<bits/stdc++.h>
using namespace std;
// 2023.01.12 阿和 110-1/1103

struct Lines{
    int xlef, ylef;
    int xrig, yrig;
}lines[10000+5];

int main(){
    int t;
    cin >> t;
    bool space = false;
    while(t--){
        if(space) cout << endl;
        space = true;
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> lines[i].xlef >> lines[i].ylef >> lines[i].xrig >> lines[i].yrig;
            if(lines[i].xlef > lines[i].xrig){
                swap(lines[i].xlef, lines[i].xrig);
                swap(lines[i].ylef, lines[i].yrig);
            }
        }

        int s;
        cin >> s;
        for(int i = 0; i < s; ++i){
            int x, y;
            cin >> x >> y;

            int nowLine = -1;
            while(true){
                bool flag = false;
                int maxy = -1, nextx = x, nexty = y;

                for(int j = 0; j < n; ++j){
                    if(lines[j].xlef <= x && lines[j].xrig >= x){
                        int xlef = lines[j].xlef, xrig = lines[j].xrig;
                        int ylef = lines[j].ylef, yrig = lines[j].yrig;

                        double m = (double)(ylef - yrig) / (double)(xlef - xrig);
                        int onLiney = yrig + m * (x - xrig);
                        if(y > onLiney && onLiney > maxy){
                            flag = true;
                            maxy = onLiney;
                            nextx = (m < 0) ? max(xlef, xrig) : min(xlef, xrig);
                            nexty = min(ylef, yrig); 
                        }
                    }
                }
                x = nextx;
                y = nexty;

                if(!flag){
                    cout << x << endl;
                    break;
                }
            }
        }
    }
}