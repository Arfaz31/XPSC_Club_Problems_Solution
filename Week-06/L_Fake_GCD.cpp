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

        for (int i = N; i >= 1; i--)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
