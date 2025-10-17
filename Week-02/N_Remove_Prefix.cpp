#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        set<int> st;
        int ans = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.find(a[i]) != st.end())
            {

                ans = i + 1; // elements before (and including) i must be removed
                break;
            }
            st.insert(a[i]);
        }
        cout << ans << endl;
    }
}
// st.count(a[i]) return true if a[i] is present in the set. we can also use-
// if (st.find(a[i]) != st.end()) this means- যদি a[i] set-এর মধ্যে পাওয়া যায় (মানে find করলে end()-এ না যায়) তাহলে এটা আগেই ছিল। অর্থাৎ — duplicate পাওয়া গেছে ✅