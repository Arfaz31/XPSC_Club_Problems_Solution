#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> v(n);

    for (long long int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    long long int count = 0;

    for (long long int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            count += (v[i - 1] - v[i]);
            v[i] = v[i - 1];
        }
    }

    cout << count << endl;

    return 0;
}
