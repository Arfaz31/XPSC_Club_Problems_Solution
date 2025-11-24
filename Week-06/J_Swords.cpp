#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;

    long long max_a = *max_element(a.begin(), a.end());

    long long z = 0;
    for (int i = 0; i < n; i++)
    {
        long long diff = max_a - a[i];
        z = __gcd(z, diff);
    }

    long long total_stolen = 0;
    for (int i = 0; i < n; i++)
    {
        total_stolen += (max_a - a[i]);
    }

    long long y = total_stolen / z;

    cout << y << " " << z << "\n";

    return 0;
}
