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
        long long X;
        cin >> N >> X;

        long long L = 0, G = 0, E = 0;

        for (int i = 0; i < N; i++)
        {
            long long a;
            cin >> a;
            if (a < X)
                L++;
            else if (a > X)
                G++;
            else
                E++;
        }

        if (L > 0 && G > 0 && E == 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
