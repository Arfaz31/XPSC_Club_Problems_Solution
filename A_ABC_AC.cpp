#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int mid = l / 2;
    string s1 = "";
    for (int i = 0; i < l; i++)
    {
        if (i != mid)
        {
            s1 += s[i];
        }
    }

    cout << s1 << endl;
    return 0;
}
