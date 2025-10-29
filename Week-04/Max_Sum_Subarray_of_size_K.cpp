#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = 0;
    long long ans = 0, sum = 0;
    // sliding window
    while (r < n)
    {
        sum += a[r];
        if (r - l + 1 == k) // 0 based indext 0 1 2 3 first window is 2 and if l=0,r=2 then 2-0+1=3 which is equal to k then it is valid window and we have to find max sum of that window and update ans, sum(sum -= a[l] this means if we hit the window(r-l+1==k) then we move forward one step and that's why we do remove a[l]) and l
        {
            ans = max(ans, sum);
            sum -= a[l];
            l++;
        }
        r++;
    }
    cout << ans << endl;
    return 0;
}
