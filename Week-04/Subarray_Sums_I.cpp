#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long curr_sum = 0, count = 0;
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        curr_sum += a[r];

        while (curr_sum > x && l <= r)
        {
            curr_sum -= a[l];
            l++;
        }

        if (curr_sum == x)
            count++;
    }

    cout << count << "\n";
    return 0;
}
