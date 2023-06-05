#include<bits/stdc++.h>
using namespace std;
//2021.07.16

int main(){
    
    long long int x;
    string s;
    deque<long long int> an;

    while( cin >> x ){

        s.clear();
        an.clear();

        getline(cin,s);
        getline(cin,s);

        stringstream ss;
        ss.clear();
        ss << s;

        while( ss >> s ){

            an.push_back( stoi(s) );
            // cout << stoi(s) <<endl;
        }

        an.pop_back();

        long long int count = 0;
        long long int multiple = 1;

        for( long long int j = an.size()-1, k = 1; j >= 0; j--, k++ ){

            count += ( k )*( an[j] )*( multiple );
            multiple *= x;
            
        }
        cout << count << endl;
    }
}