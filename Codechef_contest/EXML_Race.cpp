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
        int N;
        cin >> N;

        int bestCar = 1;
        int bestSpeed = -1;

        for (int i = 1; i <= N; i++)
        {
            int d, t;
            cin >> d >> t;
            int speed = d / t;

            if (speed > bestSpeed)
            {
                bestSpeed = speed;
                bestCar = i;
            }
        }

        cout << bestCar << "\n";
    }

    return 0;
}
