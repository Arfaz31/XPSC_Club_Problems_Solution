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
        vector<long long> A(N), B(N);

        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];

        vector<long long> endA(N), endB(N), startA(N), startB(N);

        // prefix (ending at i)
        endA[0] = A[0];
        endB[0] = B[0];
        for (int i = 1; i < N; i++)
        {
            endA[i] = max(A[i], endA[i - 1] + A[i]);
            endB[i] = max(B[i], endB[i - 1] + B[i]);
        }

        // suffix (starting at i)
        startA[N - 1] = A[N - 1];
        startB[N - 1] = B[N - 1];
        for (int i = N - 2; i >= 0; i--)
        {
            startA[i] = max(A[i], startA[i + 1] + A[i]);
            startB[i] = max(B[i], startB[i + 1] + B[i]);
        }

        long long ans = LLONG_MIN;

        for (int x = 0; x < N; x++)
        {
            long long bestA = endA[x] + startA[x] - A[x];
            long long bestB = endB[x] + startB[x] - B[x];

            ans = max(ans, bestA + bestB);
        }

        cout << ans << "\n";
    }
}
