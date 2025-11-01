#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), pre(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    ll ans = 0;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        if (pre[i] == x)
        {
            ans++;
        }
        ans += mp[pre[i] - x]; // mp[pre[i] - x] এখন নেই means key jodi age theke exist na kore (তবে map default 0)
        mp[pre[i]]++;
    }
    cout << ans << endl;

    return 0;
}

// n = 5, x = 7
// a = [2, -1, 3, 5, -2]
// pre (prefix sums) = [2, 1, 4, 9, 7]

// শুরুতে ans = 0, এবং mp খালি ({}).
// (তোর কোডে pre[i]==x আলাদা চেক আছে, তাই আমি সেটাও দেখাবো।)

// আমি প্রতিটি i-এর জন্য ৩টি ধাপ দেখাবো (যেমন কোডে চলছে):

// if (pre[i] == x) ans++;
// ans += mp[pre[i] - x];
// mp[pre[i]]++;

// i = 0
// pre[0] = 2
// Step1: pre[0] == x ? → 2 == 7 → no → ans stays 0.
// Step2: compute pre[0] - x = 2 - 7 = -5. mp[-5] এখন নেই (তবে map default 0)।
// ans += mp[-5] → ans += 0 → ans = 0.
// Step3: mp[ pre[0] ]++ → mp[2]++ → এখন mp = { 2:1 }.
// শেষ অবস্থা: ans=0, mp={2:1}

// i = 1
// pre[1] = 1
// Step1: 1 == 7 ? → no → ans=0
// Step2: pre[1] - x = 1 - 7 = -6. mp[-6] = 0 → ans += 0 → ans=0
// Step3: mp[1]++ → mp = { 2:1, 1:1 }
// শেষ অবস্থা: ans=0, mp={2:1, 1:1}

// i = 2
// pre[2] = 4
// Step1: 4 == 7 ? → no → ans=0
// Step2: pre[2] - x = 4 - 7 = -3. mp[-3] = 0 → ans += 0 → ans=0
// Step3: mp[4]++ → mp = { 2:1, 1:1, 4:1 }
// শেষ অবস্থা: ans=0, mp={2:1, 1:1, 4:1}

// i = 3
// pre[3] = 9
// Step1: 9 == 7 ? → no → ans=0
// Step2: pre[3] - x = 9 - 7 = 2. mp[2] আছে এবং mp[2]=1.
// ans += mp[2] → ans += 1 → ans = 1.
// → এই 1 টি মানে: আগের কোনো position j ছিল যেখানে pre[j] = 2 (এখানে j=0), এবং সেই j+1..i subarray-এর sum = pre[3] - pre[0] = 9 - 2 = 7।
// Step3: mp[9]++ → mp = { 2:1, 1:1, 4:1, 9:1 }
// শেষ অবস্থা: ans=1, mp={2:1,1:1,4:1,9:1}

// i = 4
// pre[4] = 7
// Step1: 7 == 7 ? → yes → ans++ → ans = 2.
// (এইটি subarray [0..4] = পুরো অংশকে নির্দেশ করে, কারণ pre[4] নিজেই x)
// Step2: pre[4] - x = 7 - 7 = 0. mp[0] এখনো 0 (তুমি আগে mp[0] ইনিশিয়ালাইজ করো নি), তাই ans += mp[0] → ans += 0 → ans remains 2.
// (বিকল্প স্টাইল হলে আমরা শুরুতেই mp[0]=1 সেট করলে এখানে ans এ আরেকটি যোগ হতো—তাহলে pre[i]==x আলাদা চেক করা লাগতো না; কিন্তু তোমার কোডে দুটো আলাদা কাজ করছে এবং সেটাও ঠিকই কাজ করে।)
// Step3: mp[7]++ → mp = {2:1,1:1,4:1,9:1,7:1}
// শেষ অবস্থা: ans=2, mp={2:1,1:1,4:1,9:1,7:1}