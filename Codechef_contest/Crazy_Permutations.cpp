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
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        for (int i = 0; i < N; ++i)
            cin >> B[i];

        if (N == 1)
        {
            cout << "Yes\n";
            continue;
        }

        bool ok = true;
        for (int i = 0; i + 1 < N; ++i)
        {
            bool a_less = (A[i] < A[i + 1]);
            bool b_less = (B[i] < B[i + 1]);
            if (a_less != b_less)
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
