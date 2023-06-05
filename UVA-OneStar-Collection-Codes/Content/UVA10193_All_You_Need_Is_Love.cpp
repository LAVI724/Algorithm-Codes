#include <bits/stdc++.h>
using namespace std;
//2021.09.10

int main()
{
    int n, p = 1;
    cin >> n;

    string str1, str2;
    getline(cin, str1);
    // for 神奇的 cin 與 getline 關係

    while (n--)
    {

        getline(cin, str1);
        getline(cin, str2);

        bool flag = false;
        if (str1[0] == '0' || str1.size() == 1 || str2[0] == '0' || str2.size() == 1)
        {
            flag = true;
        }

        long long int tmp1 = 1, tmp2 = 1;
        long long int num1 = 0, num2 = 0;

        for (int i = str1.size() - 1; i >= 0; i--)
        {
            num1 += (str1[i] - '0') * tmp1;
            tmp1 *= 2;
        }
        for (int i = str2.size() - 1; i >= 0; i--)
        {
            num2 += (str2[i] - '0') * tmp2;
            tmp2 *= 2;
        }

        if( num1 < num2){
            int tmp;
            tmp = num1;
            num1 = num2;
            num2 = tmp;
        }
        // 輾轉相除法
        // 如果兩數互質 最終結果其中一方為0時 另一方必為1
        // 若兩數有公因數 最終結果其中一方為0時 另一方必不為1
        while ((num1 %= num2) != 0 && (num2 %= num1) != 0)
            ;

        cout << "Pair #" << p;

        if (!flag && (num1 + num2) != 1)
        {
            cout << ": All you need is love!" << endl;
        }
        else
        {
            cout << ": Love is not all you need!" << endl;
        }

        p++;
        str1.clear();
        str2.clear();
    }
}