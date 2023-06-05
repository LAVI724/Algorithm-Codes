#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	int n;

	cin >> n;
	cin.ignore();
	while(n--){
		deque<char> dq;	
		getline(cin, str);
		// cin.ignore();

		for(int i = 0; i < str.size(); i++){
			if(str[i] == ']'){
				if(!dq.empty() && dq.back() == '['){
					dq.pop_back();
				}
				else{
					dq.push_back(str[i]);
				}
			}
			else if(str[i] == ')'){
				if(!dq.empty() && dq.back() == '('){
					dq.pop_back();
				}
				else{
					dq.push_back(str[i]);
				}
			}
			else{
				dq.push_back(str[i]);
			}
		}

		if(!dq.empty()){
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
		}
	}
}