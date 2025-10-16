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
        string s;
        cin >> s;

        int moves = 0;
        stack<char> st;
        for (char c : s)
        {
            if (!st.empty() && st.top() != c)
            {
                st.pop();
                moves++;
            }
            else
            {
                st.push(c);
            }
        }

        if (moves % 2 == 1)
            cout << "Zlatan\n";
        else
            cout << "Ramos\n";
    }
}
