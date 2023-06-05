#include<bits/stdc++.h>
using namespace std;
//2021.09.11

int main(){
    
    bool prime[1000000];

    // memset: 對一段內存空間全部設置為某個字符 常用於初始化字串 / 陣列
    // memset( 陣列名稱, 初始化成甚麼, 範圍 )
    memset( prime, false, sizeof(prime) );
    memset( prime, true, 2);

    for( int i = 2; i < 1000000; i++ ){
        
        if( !prime[i] ){

            for( int j = i + i; j < 1000000; j += i ){

                prime[j] = true;

            }

        }
    }

    string n1, n2;
    
    while( getline( cin, n1 ) ){

        n2 = n1;
        reverse( n1.begin(), n1.end() );

        int tmp = 1;
        int num1 = 0, num2 = 0;

        for( int i = 0; i < n1.size(); i++ ){

            num1 += ( n1[i] - '0' ) * tmp;
            num2 += ( n2[i] - '0' ) * tmp;
            tmp *= 10;

        }

        if( prime[num1] ){

            cout << num1 << " is not prime." << endl;
            continue;

        }
        else if( prime[num2] || num1 == num2 ){

            cout << num1 << " is prime." << endl;

        }
        else{

            cout << num1 << " is emirp." << endl;
        }

        n1.clear();
        n2.clear();

    }

}