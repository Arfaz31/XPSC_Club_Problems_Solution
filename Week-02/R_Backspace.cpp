#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    deque<char> dq;
    for (char c : s)
    {
        if (c == '<')
        {
            if (!dq.empty())
            {
                dq.pop_back();
            }
        }
        else
        {
            dq.push_back(c);
        }
    }

    for (char c : dq)
    {
        cout << c;
    }
    cout << '\n';

    return 0;
}
