#include<bits/stdc++.h>
using namespace std;
// 2022.05.12

int output_num;
bool larger[26][26];
char output_string[26];
map<int, int> alphabet;

void dfs(int depth){

    if(depth == output_num){
        for(int i = 0; i < depth; i++){
            cout << output_string[i];
        }
        cout << endl;

        return;
    }

    map<int, int>::iterator it;
    for(it = alphabet.begin(); it != alphabet.end(); it++){
        
        bool flag = false;
        for(int i = 0; i < depth; i++){
            // 只要目前已湊成的字串中 有一個字母比現在要新增的字母大 就不符合
            if(larger[output_string[i] - 'a'][it->first]){
                flag = true;
                break;
            }
        }

        if(!flag){
            output_string[depth] = it->first + 'a';
            dfs(depth + 1);
        }
    }
}

int main(){

    string str;
    bool space = false;
    while(getline(cin, str)){

        // 控制換行
        if(space){
            cout << endl;
        }

        memset(larger, true, sizeof(larger));
        output_num = 0;

        for(int i = 0; i < str.size(); i++){
            if(isalpha(str[i])){
                alphabet[str[i] - 'a']++;
                output_num++;
            }
        }
        
        // 把兩兩之間設定成沒有關係 (預設是兩兩之間彼此大於彼此)
        map<int, int>::iterator it;
        map<int, int>::iterator iter;
        for(it = alphabet.begin(); it != alphabet.end(); it++){
            for(iter = alphabet.begin(); iter != alphabet.end(); iter++){
                if(it->first != iter->first){
                    larger[it->first][iter->first] = false;
                    larger[iter->first][it->first] = false;
                }
            }
        }

        getline(cin, str);

        stringstream ss;
        char fir, sec;
        ss << str;
        // 轉換 string 成 stringstream
        // 每兩個兩個輸出 他會自動判斷用空白切割
        while(ss >> fir >> sec){
            larger[sec - 'a'][fir - 'a'] = true;
        }

        dfs(0);

        alphabet.clear();
        space = true;
    }
}