#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = (n + 1) - a[i];
        }
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}

// We want a[i] + b[i] to increase.

// (n+1) - a[i] ensures that the largest a[i] gets the smallest b[i].

// Intuition:

// If a[i] is small → b[i] is large → a[i] + b[i] is moderate.

// If a[i] is large → b[i] is small → a[i] + b[i] is still moderate.
// n + 1 যোগ করা হলো, যাতে b[i] সবসময় 1 থেকে n এর মধ্যে থাকে।

// a[i] বাদ দেওয়া হলো, যাতে ছোট a[i] বড় b[i] পায় আর বড় a[i] ছোট b[i] পায়।

// যদি শুধু n - a[i] দিতাম → b এর মধ্যে 0 বা negative number আসত → invalid permutation হতো।