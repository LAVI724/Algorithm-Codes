#include<bits/stdc++.h>
using namespace std;
// 2022.10.05

int main(){
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;

    	int num[100+5];
    	memset(num, 0, sizeof(num));

    	for(int i = 1; i <= n; ++i){
    		cin >> num[i];
    	}

    	int land = 1, sta = 1;
    	for(int i = n; i > 1 ; --i){
    		if(num[i-1] == 0){
    			land = i;
    			break;
    		}
    	}
    	for(int i = 1; i < n; ++i){
    		if(num[i+1] == 0){
    			sta = i;
    			break;
    		}
    	}
    	cout << land - sta << endl;
    }
}