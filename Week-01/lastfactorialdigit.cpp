#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int fact[n + 1];
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            fact[i] = fact[i - 1] * i;
        }
        cout << fact[n] % 10 << endl;
    }
    return 0;
}