#include<bits/stdc++.h>
using namespace std;
//2021.09.07

int main(){

    int t;
    cin >> t;

    while( t-- ){

        int n;
        cin >> n;

        int p;
        cin >> p;

        deque<int> h;

        while( p-- ){

            int tmp;
            cin >> tmp;
            h.push_back(tmp);     

        }

        deque<int>::iterator it;

        sort( h.begin(), h.end() );

        for( int i = 0; i < h.size(); i++ ){

            for( int j = i + 1 ; j < h.size(); j++ ){

                if( h[j] % h[i] == 0 ){

                    it = h.begin() + j;
                    h.erase(it);

                }
            }
        }

        int count = 0;
        bool day[3650+5];

        memset( day, false, sizeof(day) );

        for( int i = 0; i < h.size(); i++ ){
            
            for( int j = h[i]; j <= n; j += h[i] ){
                
                if( !day[ j ] ){
                    
                    if( j % 7 != 6 && j % 7 != 0 ){
                        
                        day[ j ] = true;
                        count++;
                        
                    }
                }
            }
        }

        cout << count << endl;
        h.clear();
    }
}