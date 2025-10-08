#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string new_s = "";
    for (char c : s)
    {
        if (c >= 'A' && c <= 'Z')
        {
            new_s += c;
        }
    }
    cout << new_s << endl;
    return 0;
}