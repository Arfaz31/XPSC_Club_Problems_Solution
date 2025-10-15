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

    set<string> nonPossessed;

    for (int i = 0; i < n; i++)
    {
        if (nonPossessed.find(names[i]) == nonPossessed.end())
        {
            nonPossessed.insert(names[i]);
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
