#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 1; i <= n; ++i)
        dq.push_back(i);

    vector<int> order;
    while (dq.size() > 1)
    {
        int x = dq.front();
        dq.pop_front();
        int y = dq.front();
        dq.pop_front();
        order.push_back(y);
        dq.push_back(x);
    }
    if (!dq.empty())
        order.push_back(dq.front());

    for (int i = 0; i < (int)order.size(); ++i)
    {
        if (i)
            cout << ' ';
        cout << order[i];
    }
    cout << '\n';
    return 0;
}
