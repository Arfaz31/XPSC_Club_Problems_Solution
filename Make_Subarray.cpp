#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int min_count = 0;
        int firstIndex = -1;
        int lastIndex = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (firstIndex == -1)
                {
                    firstIndex = i;
                }
                lastIndex = i;
            }
        }
        if (firstIndex == -1)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = firstIndex; i <= lastIndex; i++)
        {
            if (s[i] == '0')
            {
                min_count++;
            }
        }
        cout << min_count << endl;
    }
    return 0;
}