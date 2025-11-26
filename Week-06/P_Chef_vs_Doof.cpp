#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        bool all_odd = true;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
                all_odd = false;
        }

        if (all_odd)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
