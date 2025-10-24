#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        priority_queue<int> pq;
        for (int i = 1; i <= n; i++)
        {
            pq.push(i);
        }

        vector<pair<int, int>> ops;

        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ops.push_back({a, b});

            int new_num = (a + b) / 2;
            pq.push(new_num);
            // cout << "a " << a << " " << "b " << b << " " << new_num << "\n";
            // priority_queue<int> temp = pq;
            // while (!temp.empty())
            // {
            //     cout << temp.top() << " ";
            //     temp.pop();
            // }
            // cout << "\n";
        }

        cout << pq.top() << "\n";

        for (auto &p : ops)
        {
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}
