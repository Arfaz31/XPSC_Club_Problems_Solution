#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<pair<string, string>> leaves;

    for (int i = 0; i < n; i++)
    {
        string species, color;
        cin >> species >> color;
        leaves.insert({species, color});
    }

    cout << leaves.size() << endl;
    return 0;
}

// solution with map
//  int main()
//  {
//      int n;
//      cin >> n;
//      map<pair<string, string>, bool> leaves;

//     for(int i=1;i<=n;i++)
//     {
//         string s1,s2;
//         cin>>s1>>s2;
//         leaves[{s1,s2}]=true;
//     }
//     // for(auto it :leaves)
//     // {
//     //     pair<string,string> p = it.first;
//     //     bool b = it.second;
//     //     cout<<p.first<<" "<<p.second<<endl;
//     // }
//     cout<<leaves.size()<<endl;

//     return 0;
// }