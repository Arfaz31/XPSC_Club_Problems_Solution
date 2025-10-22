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

        int m;
        cin >> m;
        while (m--)
        {
            string s;
            cin >> s;

            if (s.size() != n)
            {
                cout << "NO\n";
                continue;
            }

            unordered_map<long long, char> num_to_char;
            unordered_map<char, long long> char_to_num;
            bool ok = true;

            for (int i = 0; i < n; i++)
            {
                if (num_to_char.count(a[i]) && num_to_char[a[i]] != s[i])
                {
                    ok = false;
                    break;
                }
                if (char_to_num.count(s[i]) && char_to_num[s[i]] != a[i])
                {
                    ok = false;
                    break;
                }
                num_to_char[a[i]] = s[i];
                char_to_num[s[i]] = a[i];
            }

            cout << (ok ? "YES" : "NO") << "\n";
        }
    }
}

// Key Takeaways

// num_to_char → check same number maps to same char

// char_to_num → check same char maps to same number

// Conflict arises যদি either map violates previous mapping