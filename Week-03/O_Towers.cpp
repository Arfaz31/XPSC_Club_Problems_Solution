#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    multiset<int> tops;
    for (int k : a)
    {
        auto it = tops.upper_bound(k); // smallest top > k
        if (it == tops.end())
        {
            // no tower can acecpt this cube -> start a new twoer
            tops.insert(k);
        }
        else
        {
            // place cube on this tower: remove old top and insert new top k
            tops.erase(it);
            tops.insert(k);
        }
    }

    cout << tops.size() << "\n";
    return 0;
}
