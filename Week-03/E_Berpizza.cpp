#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    queue<int> order;                    // Monocarp এর জন্য arrival order
    priority_queue<pair<int, int>> rich; // Polycarp এর জন্য (money, -id)
    vector<bool> served(q + 5, false);   // served কি না check
    vector<int> money(q + 5, 0);         // customer money

    int id = 0;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int m;
            cin >> m;
            id++;
            money[id] = m;
            order.push(id);      // Monocarp queue
            rich.push({m, -id}); // Polycarp heap
        }
        else if (type == 2)
        {
            while (served[order.front()])
                order.pop();
            int serveId = order.front();
            order.pop();
            served[serveId] = true;
            cout << serveId << " ";
        }
        else
        { // type == 3
            while (served[-rich.top().second])
                rich.pop();
            int serveId = -rich.top().second;
            rich.pop();
            served[serveId] = true;
            cout << serveId << " ";
        }
    }

    return 0;
}
