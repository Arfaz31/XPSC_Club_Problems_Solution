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
        string s;
        cin >> s;

        vector<pair<int, char>> lower, upper;

        int idx = 0; // index in final answer
        for (char c : s)
        {
            if (c == 'b')
            {
                if (!lower.empty())
                    lower.pop_back();
            }
            else if (c == 'B')
            {
                if (!upper.empty())
                    upper.pop_back();
            }
            else if (islower(c))
            {
                lower.push_back({idx, c});
                idx++;
            }
            else
            {
                upper.push_back({idx, c});
                idx++;
            }
        }

        // merge two vectors into one
        vector<pair<int, char>> ans;
        for (auto &p : lower)
            ans.push_back(p);
        for (auto &p : upper)
            ans.push_back(p);

        sort(ans.begin(), ans.end());

        for (auto &p : ans)
            cout << p.second;
        cout << "\n";
    }

    return 0;
}

// কারণ:

// তুমি দুইটা vector (lower ও upper) থেকে ans বানাচ্ছো।

// পরে sort(ans.begin(), ans.end()); দিয়ে index অনুযায়ী arrange করছো।

// যদি index না রাখো, তাহলে uppercase এবং lowercase letters মিশিয়ে sort করলে original input order হারিয়ে যাবে, কারণ sort হবে character এর মান অনুযায়ী।