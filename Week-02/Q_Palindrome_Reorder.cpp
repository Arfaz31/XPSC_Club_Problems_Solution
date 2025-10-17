
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> freq;

    for (char c : s)
        freq[c]++;

    int oddCount = 0;
    char oddChar = 0;
    for (auto [ch, cnt] : freq)
    {
        if (cnt % 2 != 0)
        {
            oddCount++;
            oddChar = ch;
        }
    }

    if (oddCount > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    string left = "", right = "";
    for (auto [ch, cnt] : freq)
    {
        left += string(cnt / 2, ch);
    }

    right = left;
    reverse(right.begin(), right.end());

    if (oddChar)
        cout << left << oddChar << right;
    else
        cout << left + right;
}

// ⚠️ কখন palindrome বানানো সম্ভব?

// এটা সবচেয়ে important logic —

// ✅ যদি string এর length even হয় —
// তাহলে প্রতিটা letter-এর count even হতে হবে।

// ✅ যদি string এর length odd হয় —
// তাহলে exactly একটিমাত্র letter-এর count odd হতে পারবে,
// বাকি সব even হতে হবে।

// Input string: AAAACACBA

// Frequency:
// A -> 6
// B -> 1
// C -> 2
// cnt / 2 → আমরা কতটুকু ch left half এ রাখব।

// যেহেতু palindrome symmetric, left half আর right half সমান হবে।
// তাই আমরা অর্ধেক ch left half এ রাখি।
// উদাহরণ: cnt = 6 → cnt / 2 = 3
// string(cnt / 2, ch) → C++ STL এর string constructor, যা cnt/2 সংখ্যক ch character দিয়ে নতুন
// string(3, 'A') → "AAA"
