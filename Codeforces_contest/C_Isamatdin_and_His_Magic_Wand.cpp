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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> odds, evens;
        for (int x : a)
        {
            if (x % 2)
                odds.push_back(x);
            else
                evens.push_back(x);
        }

        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());

        int i = 0, j = 0;
        int o = odds.size(), e = evens.size();
        if (o < 1 || e < 1)
        {
            for (int x : a)
                cout << x << " ";
            cout << "\n";
            continue;
        }
        while (i < o && j < e)
        {
            if (odds[i] < evens[j])
            {
                cout << odds[i] << " ";
                i++;
            }
            else
            {
                cout << evens[j] << " ";
                j++;
            }
        }
        while (i < o)
        {
            cout << odds[i] << " ";
            i++;
        }
        while (j < e)
        {
            cout << evens[j] << " ";
            j++;
        }
        cout << "\n";
    }
    return 0;
}
