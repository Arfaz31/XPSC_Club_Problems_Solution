#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        int count1 = 0, count2 = 0, count3 = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
            if (A[i] == 1)
                count1++;
            else if (A[i] == 2)
                count2++;
            else if (A[i] == 3)
                count3++;
        }

        int pairs = 0;

        pairs += count1 * (count1 - 1) / 2;

        pairs += count1 * count2;

        pairs += count2 * count3;

        cout << pairs << endl;
    }
    return 0;
}
