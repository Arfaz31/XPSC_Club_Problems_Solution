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
        int arr[n];
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            s.insert(arr[i]);
        }
        if (s.size() == 1)
        {
            cout << *(s.begin()) - 1 << endl;
        }
        else if (s.size() > 2)
        {
            cout << *(s.rbegin()) - 1 << endl;
        }
        else
        {
            int mn = *(s.begin());
            int mx = *(s.rbegin());
            for (int i = mx - 1; i >= 0; i--)
            {
                if (i != mn)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
