#include<bits/stdc++.h>
using namespace std;

int main(){
	string str1, str2;
	while(cin >> str1 >> str2){
		int num1[26], num2[26];

		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));

		for(int i = 0; i < str1.size(); i++){
			num1[str1[i] - 'A']++;
		}
		for(int i = 0; i < str2.size(); i++){
			num2[str2[i] - 'A']++;
		}

		sort(num1, num1 + 26);
		sort(num2, num2 + 26);

		bool flag = false;
		for(int i = 0; i < 26; i++){
			if(num1[i] != num2[i]){
				flag = true;
				break;
			}
		}

		if(flag){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}
}