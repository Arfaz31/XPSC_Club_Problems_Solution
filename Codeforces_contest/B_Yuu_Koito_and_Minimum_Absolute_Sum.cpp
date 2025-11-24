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
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long S;

        long long a1 = a[0];
        long long an = a[n - 1];

        if (a1 != -1 && an != -1)
        {
            S = llabs(an - a1);
        }
        else if (a1 != -1 && an == -1)
        {
            an = a1;
            a[n - 1] = an;
            S = 0;
        }
        else if (a1 == -1 && an != -1)
        {
            a1 = an;
            a[0] = a1;
            S = 0;
        }
        else
        {
            a1 = 0;
            an = 0;
            a[0] = 0;
            a[n - 1] = 0;
            S = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
                a[i] = 0;
        }

        cout << S << "\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}