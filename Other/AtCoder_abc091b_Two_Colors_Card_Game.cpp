#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	string str;
	map<string, int> blue, red;

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> str;
		blue[str]++;
	}

	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> str;
		red[str]++;
	}

	int maxi = 0;
	for(auto i : blue){
		maxi = max(i.second - red[i.first], maxi);
	}

	cout << maxi << endl;
}