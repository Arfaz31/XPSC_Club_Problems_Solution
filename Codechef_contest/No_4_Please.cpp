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

        int count1 = 0, count2 = 0, count3 = 0;

        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            if (x == 1)
                count1++;
            else if (x == 2)
                count2++;
            else if (x == 3)
                count3++;
        }

        int deletions = 0;

        if (count2 > 1)
            deletions += (count2 - 1);

        if (count1 > 0 && count3 > 0)
            deletions += min(count1, count3);

        cout << deletions << "\n";
    }

    return 0;
}
