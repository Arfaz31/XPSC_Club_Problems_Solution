#include <bits/stdc++.h>
using namespace std;

// time complexity O(nlogn)
int main()
{
    int n;
    cin >> n;
    vector<int> v(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    if (v[0] != 1)
    {
        cout << 1 << endl;
        return 0;
    }

    int l = v.size();

    for (int i = 0; i < l - 1; i++)
    {
        if (v[i + 1] - v[i] > 1)
        {
            cout << v[i] + 1 << endl;
            return 0;
        }
    }

    cout << n << endl;
    return 0;
}

// time complexity O(n)
//  int main() {
//      long long n;
//      cin >> n;

//     long long total_sum = n * (n + 1) / 2;
//     long long given_sum = 0;

//     for (int i = 0; i < n - 1; i++) {
//         long long x;
//         cin >> x;
//         given_sum += x;
//     }

//     cout << total_sum - given_sum << endl;

//     return 0;
// }