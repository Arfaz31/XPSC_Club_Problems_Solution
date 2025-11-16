#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mp;
    mp[0] = 0;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        int need = sum - k;
        auto it = mp.find(need);
        if (sum == k)
        {
            ans = max(ans, i + 1);
        }
        if (it != mp.end()) // এই line ছাড়া আমরা subarrays যেগুলো 0 থেকে শুরু হয়নি বা মাঝে শুরু হয়ে sum=k হয় সেগুলো miss করব।
        {
            int len = i - mp[need];
            ans = max(ans, len);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    cout << ans << endl;
    return 0;
}

// Step 4 → i = 4, arr[i] = 1

// sum = 24 + 1 = 25

// need = 25 - 15 = 10 → mp.find(10) → found at index 0

// এখানেই line দরকার:
// len = i - mp[need] = 4 - 0 = 4
// ans = max(ans, len) = 4
// mp[25] = 4

// ans = 4
