#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string txt, pat;
    cin >> txt >> pat;

    int n = txt.size(), m = pat.size();
    if (m > n)
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> patfreq(26, 0), window(26, 0);
    for (char c : pat)
        patfreq[c - 'a']++;

    int count = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        window[txt[r] - 'a']++; // add new char

        if (r - l + 1 == m)
        { // window is full: check then slide
            if (window == patfreq)
                count++;
            window[txt[l] - 'a']--; // remove left char for next window
            l++;
        }
        r++;
    }

    cout << count << "\n";
    return 0;
}
