#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A, B;
    cin >> A >> B;
    int ans = max(2 * (max(A, B)) - 1, (A + B));
    cout << ans << endl;
    return 0;
}