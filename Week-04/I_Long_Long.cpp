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

        long long sum = 0;
        int count = 0;
        bool inNegBlock = false;

        for (int i = 0; i < n; i++)
        {
            sum += abs(a[i]); // maximum sum

            if (a[i] < 0)
            {
                if (!inNegBlock)
                {
                    count++;
                    inNegBlock = true;
                }
            }
            else if (a[i] > 0)
            {
                inNegBlock = false;
            }
                }

        cout << sum << " " << count << "\n";
    }
}
