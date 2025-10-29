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
        string s, t;
        cin >> s >> t;
        int freqs[26] = {0}, freqt[26] = {0};
        for (int i = 0; i < n; i++)
        {
            freqs[s[i] - 'a']++, freqt[t[i] - 'a']++;
        }
        bool flag = true;
        for (int i = 0; i < 26; i++)
        {
            if (freqs[i] != freqt[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
