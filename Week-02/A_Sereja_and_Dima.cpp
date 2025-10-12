#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int sum1 = 0, sum2 = 0;
    int i = 0, j = n - 1;
    int turn = 0; // 0 → Sereja, 1 → Dima

    while (i <= j)
    {
        int choice;
        if (a[i] > a[j])
        {
            choice = a[i];
            i++;
        }
        else
        {
            choice = a[j];
            j--;
        }

        if (turn % 2 == 0)
            sum1 += choice;
        else
            sum2 += choice;

        turn++;
    }

    cout << sum1 << " " << sum2 << endl;
    return 0;
}
