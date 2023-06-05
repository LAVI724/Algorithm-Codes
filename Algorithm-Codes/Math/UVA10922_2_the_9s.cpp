#include<bits/stdc++.h>
using namespace std;
//2021.09.12

int main(){
    
    string nine;
    
    while( getline( cin, nine ) ){

        if( nine.size() == 1 && nine[0] == '0' ){

            break;

        }

        int count = 0;

        for( int i = 0; i < nine.size(); i++ ){
            
            cout << nine[i];
            count += nine[i] - '0';

        }

        if( count % 9 ){

            cout << " is not a multiple of 9." << endl;
        }

        else{

            int degree = 1;
            int check = count;

            while( check > 10 ){

                degree++;
                count = check;
                check = 0;

                while( count ){
                    
                    check += count % 10 ;
                    count /= 10;

                }

            }

            cout << " is a multiple of 9 and has 9-degree " << degree << "." << endl;

        }

        nine.clear();

    }

}