#include <bits/stdc++.h>
using namespace std;
const int maxN = (1LL << 15);

vector<int> allPalindrome;
bool isPalindrome(int x)
{
    string s = to_string(x);
    int len = s.size();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

void markPalindrome()
{
    for (int i = 0; i < maxN; i++)
    {
        if (isPalindrome(i))
        {
            allPalindrome.push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Step 1: Precompute সব palindrome সংখ্যা (0 থেকে 2¹⁵ পর্যন্ত) কারণ Ai < 2¹⁵ ( অর্থাৎ 32768-এর কম )।
    markPalindrome();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), cnt(maxN + 1);
        // Step 2: প্রতিটি টেস্ট কেসে frequency array বানানো
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }

        long long ans = n; // কারণ (i, i) সবসময় palindrome (Ai ^ Ai = 0) কারণ x ^ x = 0, আর 0 একটি পালিনড্রোম।
                           // Step 4: প্রতিটি element-এর জন্য সব palindrome-এর সাথে XOR করো
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < allPalindrome.size(); j++)
            {
                int curr = (a[i] ^ allPalindrome[j]);
                ans += cnt[curr];
            }
        }

        // 🔹 Step 5: double counting হবার কারণে শেষে ans/2 কারণ (i,j) এবং (j,i) দু’বার গণনা হয়।
        cout << (ans / 2) << '\n';
    }
    return 0;
}