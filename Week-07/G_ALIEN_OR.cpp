#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        map<string, bool> ache;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            ache[s] = true;
        }
        string s(k, '0');
        bool ok = true;
        for (int i = 0; i < k; i++)
        {
            s[i] = '1';
            if (!ache[s])
            {
                ok = false;
                break;
            }
            s[i] = '0';
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

// 2nd solution
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         bool a[k];
//         memset(a, 0, sizeof(a));
//         string s;
//         int c, x;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> s;
//             c = 0;
//             for (int j = 0; j < k; j++)
//             {
//                 if (s[j] == '1')
//                 {
//                     c++;
//                     x = j;
//                 }
//             }
//             if (c == 1)
//             {
//                 a[x] = true;
//             }
//         }
//         bool ok = true;
//         for (int i = 0; i < k; i++)
//         {
//             if (!a[i])
//             {
//                 ok = false;
//                 break;
//             }
//         }
//         cout << (ok ? "YES\n" : "NO\n");
//     }
//     return 0;
// }

// N = 2, K = 2
// A = ["01", "10"]
// ধাপে ধাপে:

// প্রথমে ache-এ থাকবে: ache["01"]=true, ache["10"]=true.

// শুরুতে s = "00"।

// i = 0:

// s[0] = '1' → s = "10".

// দেখে ache["10"] আছে → OK, এখন s[0] = '0' করে s ফের 00 করো।

// i = 1:

// s[1] = '1' → s = "01".

// দেখে ache["01"] আছে → OK, s ফের 00 করো।

// সব i শেষ এবং কোনো মিস হয়নি → ok = true → আউটপুট: YES.