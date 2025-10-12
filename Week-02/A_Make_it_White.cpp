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
        int firsIndex = -1, lastIndex = -1;
        bool isFirst = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                if (isFirst)
                {
                    firsIndex = i;
                    isFirst = false;
                }
                lastIndex = i;
            }
        }

        if (lastIndex == -1)
        {
            cout << 1 << endl;
            continue;
        }

        int count = 0;
        for (int i = firsIndex; i <= lastIndex; i++)
        {
            count++;
        }
        cout << count << endl;
    }

    return 0;
}