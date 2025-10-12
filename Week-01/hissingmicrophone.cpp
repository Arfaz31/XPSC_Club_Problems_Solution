#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = s.length();
    bool ishissing = false;
    for (int i = 0; i < l - 1; i++)
    {
        if (s[i] == s[i + 1] && s[i] == 's')
        {
            ishissing = true;
            break;
        }
    }
    if (ishissing)
        cout << "hiss" << endl;
    else
        cout << "no hiss" << endl;
    return 0;
}