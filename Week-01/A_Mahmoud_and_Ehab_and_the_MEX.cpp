#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    int freq[101] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int count = 0;
    for (int i = 0; i < x; i++)
    {
        if (freq[i] == 0)
        {
            count++;
        }
    }
    if (freq[x] > 0)
        count++;
    cout << count << endl;

    return 0;
}