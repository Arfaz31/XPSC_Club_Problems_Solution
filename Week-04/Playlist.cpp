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

    set<int> s;
    int ans = 0;
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        while (s.find(a[r]) != s.end())
        {
            // 👉 যখন কোনো duplicate পাওয়া যায় (a[r] আগে থেকেই set-এ আছে), তখন কোডটা বাম দিক (left pointer, অর্থাৎ l) থেকে একে একে element গুলো erase করে যতক্ষণ না ওই duplicate value set থেকে বাদ যায়।
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        ans = max(ans, (int)s.size());
    }

    cout << ans << "\n";
    return 0;
}
