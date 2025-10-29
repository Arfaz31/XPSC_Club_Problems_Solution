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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int count = 0;
        for (int i = 0; i < n;)
        {
            if (s[i] == 'B')
            {
                count++;
                i += k; // skip k characters and move forward
            }
            else
            {
                i++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
