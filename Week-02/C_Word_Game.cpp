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
        vector<string> a(n), b(n), c(n);
        map<string, int> freq;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            freq[b[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            freq[c[i]]++;
        }

        int A = 0, B = 0, C = 0;

        for (string w : a)
        {
            if (freq[w] == 1)
                A += 3;
            else if (freq[w] == 2)
                A += 1;
        }
        for (string w : b)
        {
            if (freq[w] == 1)
                B += 3;
            else if (freq[w] == 2)
                B += 1;
        }
        for (string w : c)
        {
            if (freq[w] == 1)
                C += 3;
            else if (freq[w] == 2)
                C += 1;
        }
        cout << A << ' ' << B << ' ' << C << endl;
    }
    return 0;
}