#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;

    map<string, string> mp;
    while (q--)
    {
        string old_name, new_name;
        cin >> old_name >> new_name;

        bool found = false;
        string original;

               for (auto it : mp)
        {
            if (it.second == old_name)
            {
                found = true;
                original = it.first;
                break;
            }
        }

        if (found)
        {
            mp[original] = new_name;
        }
        else
        {
            mp[old_name] = new_name;
        }
    }

    cout << mp.size() << "\n";
    for (auto p : mp)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
