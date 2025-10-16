#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int mintime = min(a, min(b, c));
    cout << mintime << endl;
    return 0;
}