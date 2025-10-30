#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            cout << pre[b - 1] << endl;
        }
        else
        {
            cout << pre[b - 1] - pre[a - 2] << endl;
        }
    }
    return 0;
}
