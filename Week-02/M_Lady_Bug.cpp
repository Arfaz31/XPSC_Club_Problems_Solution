#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        int b_even_zeros = 0, b_odd_zeros = 0;

        for (int i = 0; i < n; i++)
        {
            if (b[i] == '0')
            {
                if (i % 2 == 0)
                    b_even_zeros++;
                else
                    b_odd_zeros++;
            }
        }

        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                if (i % 2 == 0)
                { // a even index → need b odd zero
                    if (b_odd_zeros > 0)
                        b_odd_zeros--;
                    else
                    {
                        possible = false;
                        break;
                    }
                }
                else
                { // a odd index → need b even zero
                    if (b_even_zeros > 0)
                        b_even_zeros--;
                    else
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}
