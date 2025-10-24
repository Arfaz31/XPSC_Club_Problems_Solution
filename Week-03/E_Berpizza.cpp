#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, customerNo = 1;
    cin >> n;
    set<pair<int, int>> s;
    multiset<pair<int, int>> ml;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int money;
            cin >> money;
            s.insert({customerNo, money});
            ml.insert({money, -customerNo});
            customerNo++;
        }
        else if (type == 2)
        {
            int pos = s.begin()->first, money = s.begin()->second;
            ans.push_back(pos);
            s.erase(s.begin());
            ml.erase({money, -pos});
        }
        else
        {
            int pos = -ml.rbegin()->second, money = ml.rbegin()->first;
            ans.push_back(pos);
            ml.erase(--ml.end());
            s.erase({pos, money});
        }
    }
    for (auto value : ans)
        cout << value << " ";

    cout << endl;

    // second solution
    //  int q;
    //  cin >> q;
    //  queue<int> order;
    //  priority_queue<pair<int, int>> rich;
    //  vector<bool> served(q + 5, false);
    //  vector<int> money(q + 5, 0);
    //  int id = 0;
    //  while (q--)
    //  {
    //      int type;
    //      cin >> type;
    //      if (type == 1)
    //      {
    //          int m;
    //          cin >> m;
    //          id++;
    //          money[id] = m;
    //          order.push(id);      // Monocarp queue
    //          rich.push({m, -id}); // Polycarp heap
    //      }
    //      else if (type == 2)
    //      {
    //          while (served[order.front()])
    //              order.pop();
    //          int serveId = order.front();
    //          order.pop();
    //          served[serveId] = true;
    //          cout << serveId << " ";
    //      }
    //      else
    //      { // type == 3
    //          while (served[-rich.top().second])
    //              rich.pop();
    //          int serveId = -rich.top().second;
    //          rich.pop();
    //          served[serveId] = true;
    //          cout << serveId << " ";
    //      }
    //  }

    return 0;
}

// 3️⃣ কেন -id ব্যবহার?
//-id → if money become equal (smaller id comes first)
// আমরা priority_queue<pair<int,int>> ব্যবহার করি: rich.push({money, -id});
// priority_queue first দিয়ে compare করে, বড় first আগে।

// যদি first সমান হয়, তখন second দিয়ে compare করে।

// আমরা চাই tie-break → smaller id আগে আসবে, কিন্তু max-heap তো বড় value আগে রাখে।

// 💡 Trick: negative id use করা হয় → কারণ small id কে “bigger” হিসেবে handle করতে চাই।

// উদাহরণ:
// | customer | money | id | pair pushed = {money, -id} |
// | -------- | ----- | -- | -------------------------- |
// | #1       | 10    | 1  | (10, -1)                   |
// | #2       | 10    | 2  | (10, -2)                   |
// priority_queue sort করে → (10, -1) আগে আসবে, তারপর (10, -2)

// top এ থাকবে (10, -1) → serve হবে customer #1

// ঠিক একইভাবে tie-break small id works। ✅