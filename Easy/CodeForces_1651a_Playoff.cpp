#include<bits/stdc++.h>
using namespace std;
// 2022.10.05

/*
解題觀念:
數論找規律
*/

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		long long int total = pow(2, n);
		cout << total - 1 << endl;
	}
}