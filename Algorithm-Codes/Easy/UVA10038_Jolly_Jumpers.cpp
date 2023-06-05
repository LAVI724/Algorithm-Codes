#include<bits/stdc++.h>
using namespace std;
//2021.06.30

int main(){

    deque<int> num;
    set<int> count;
    set<int>::iterator it;

    int n, m;

    while( cin >> n ){

        num.clear();
        count.clear();

        for( int i=0; i<n; i++){
            
            cin >> m;
            num.push_back(m);

        }

        for( int i = 1; i < num.size(); i++ )
            count.insert( abs( num[i] - num[i-1] ));

        bool flag = 0;
        int check = 1;

        for( it = count.begin(); it != count.end(); it++, check++ ){
            
            if( count.size() != n-1 ){

                flag = 1;
                break;

            }

            if( *it != check )
                flag = 1;
        
        }
        
        if( flag )
            cout << "Not jolly" << endl;
        else
            cout << "Jolly" << endl;
    }
}