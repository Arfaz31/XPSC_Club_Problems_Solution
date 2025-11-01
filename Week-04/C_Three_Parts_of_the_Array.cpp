#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long left = 0, right = n - 1;
    long long sumL = 0, sumR = 0, ans = 0;

    while (left <= right)
    {
        if (sumL == sumR)
            ans = sumL;

        if (sumL <= sumR)
            sumL += a[left++];
        else
            sumR += a[right--];
    }

    if (sumL == sumR)
        ans = sumL; // final check
    cout << ans << "\n";
}

//  if (sumL == sumR)
//         ans = sumL; // final check
// লুপের ভিতরে equal অবস্থাগুলো ধরা হয়,
// কিন্তু লুপের ঠিক শেষে equal হলে সেটা ধরা হয় না।
// তাই শেষে একবার if (sumL == sumR) দিতে হয়, যেন শেষবারের অবস্থাটাও গণনা হয়।