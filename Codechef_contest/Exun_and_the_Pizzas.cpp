#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, p;
    cin >> n >> k >> p;
    int remaining = n - k;
    int profit = remaining * p;
    cout << profit << endl;
    return 0;
}
