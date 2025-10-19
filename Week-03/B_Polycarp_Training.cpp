#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int day = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= day + 1)
        {
            day++;
        }
    }

    cout << day << "\n";

    return 0;
}

// Explanation:

// Sorted contests make it easier to always pick the smallest contest that satisfies the day requirement.

// day + 1 মানে “current day এর জন্য কতো problem solve করতে হবে”।

// শুধু সেই contest নিয়ে day increase করো যা satisfy করে।