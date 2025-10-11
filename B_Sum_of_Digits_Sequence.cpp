#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll digit_sum(ll x)
{
    ll sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n + 1);
    vector<ll> pref(n + 1);
    pref[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        v[i] = pref[i - 1];
        pref[i] = pref[i - 1] + digit_sum(v[i]);
    }
    cout << v[n] << endl;

    return 0;
}