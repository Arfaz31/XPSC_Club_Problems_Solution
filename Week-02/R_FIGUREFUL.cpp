#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<pair<int, int>, string> codeToName;

    for (int i = 0; i < n; i++)
    {
        int c1, c2;
        string name;
        cin >> c1 >> c2 >> name;
        codeToName[{c1, c2}] = name; // replace the previous name with same code for example-codeToName[{6, 4}]=Yamuna -> Chitra (then value Yamuna will be replaced by Chitra)
    }

    int t;
    cin >> t;
    while (t--)
    {
        int q1, q2;
        cin >> q1 >> q2;
        cout << codeToName[{q1, q2}] << "\n";
    }
}
