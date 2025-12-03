#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        string s;
        cin >> s;

        int sumNormal = 0, sumSpecial = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                sumNormal += a[i];
            else
                sumSpecial += a[i];
        }

        int coins = sumNormal;

        if (sumNormal >= c)
        {
            coins = max(coins, sumNormal - c + sumSpecial);
        }

        cout << coins << endl;
    }

    return 0;
}
