#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++)
        cin >> names[i];

    set<string> seen;
    vector<string> result;

    for (int i = n - 1; i >= 0; i--)
    {
        if (seen.find(names[i]) == seen.end())
        {
            result.push_back(names[i]);
            seen.insert(names[i]);
        }
    }

     for (auto &name : result)
        cout << name << "\n";

    return 0;
}
