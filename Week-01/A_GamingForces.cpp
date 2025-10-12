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
        int arr[n];
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        int sum;
        if (count1 % 2 == 0)
        {
            sum = (count1 / 2) + count2;
            cout << sum << endl;
        }
        else
        {
            sum = (count1 / 2) + count2 + 1;
            cout << sum << endl;
        }
    }
    return 0;
}