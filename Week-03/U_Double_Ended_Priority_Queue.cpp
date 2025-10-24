#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q))
        return 0;
    multiset<ll> ms;
    for (int i = 0; i < N; ++i)
    {
        ll x;
        cin >> x;
        ms.insert(x);
    }

    for (int qi = 0; qi < Q; ++qi)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            ll x;
            cin >> x;
            ms.insert(x);
        }
        else if (type == 1)
        {
            // output and remove one minimum element
            auto it = ms.begin();
            cout << *it << '\n';
            ms.erase(it);
        }
        else if (type == 2)
        {
            // output and remove one maximum element
            auto it = prev(ms.end());
            cout << *it << '\n';
            ms.erase(it);
        }
    }
    return 0;
}
