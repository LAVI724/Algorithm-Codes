#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n;
	while(cin >> n){
		deque<long long int> st;
		deque<long long int> q;
		priority_queue<long long int> pq;

		long long int iss = 0, isq = 0, ispq = 0;
		while(n--){
			long long int a, b;
			cin >> a >> b;
			if(a == 1){
				st.push_back(b);
				q.push_back(b);
				pq.push(b);
			}
			else{

				if(st.empty()){
					iss = 1;
				}
				else if(b != st.back()){
					iss = 1;
				}

				if(q.empty()){
					isq = 2;
				}
				else if(b != q.front()){
					isq = 2;
				}

				if(pq.empty()){
					ispq = 4;
				}
				else if(b != pq.top()){
					ispq = 4;

				}

				if(!st.empty()){
					st.pop_back();
				}
				if(!q.empty()){
					q.pop_front();
				}
				if(!pq.empty()){
					pq.pop();
				}
			}
		}

		long long int ans = iss + isq + ispq;
			
		if(ans == 6){
			cout << "stack" << endl;
		}
		else if(ans == 5){
			cout << "queue" << endl;
		}
		else if(ans == 3){
			cout << "priority queue" << endl;
		}
		else if(ans == 7){
			cout << "impossible" << endl;
		}
		else{
			cout << "not sure" << endl;
		}
	}
}