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
        string s;
        cin >> s;

        long long initial = 0;
        vector<long long> gains;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                initial += i;                     // L contribution
                long long gain = (n - 1 - i) - i; // L -> R flip gain
                if (gain > 0)
                    gains.push_back(gain);
            }
            else
            {
                initial += (n - 1 - i);           // R contribution
                long long gain = i - (n - 1 - i); // R -> L flip gain
                if (gain > 0)
                    gains.push_back(gain);
            }
        }

        sort(gains.rbegin(), gains.rend()); // descending order

        long long sum = initial;
        int m = gains.size();
        for (int k = 1; k <= n; k++)
        {
            if (k <= m)
                sum += gains[k - 1];
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}

// Summary Relation to Problem

// initial → line value যখন কেউ flip হয়নি।

// gains → flip করলে কত gain হবে প্রতিটি ব্যক্তির।

// sort descending → আমরা সর্বোচ্চ লাভদায়ক flips প্রথমে করি।

// loop k=1..n → প্রতি k এর জন্য maximum value বের করা, যেখানে at most k flips allowed।

// **Problem Summary**

// আমাদের কাছে n জন মানুষ আছে, যারা এক লাইনে দাঁড়ানো।

// প্রত্যেকজন L বা R দিকে তাকাচ্ছে।

// প্রত্যেকজনের value = কতজন লোক তার দিকের দিকে আছে।

// আমাদের goal: কতজন লোকের দিক পরিবর্তন করলে max value পাওয়া যায়, k=1..n।

// Step 1: Initial Value

// Logic:

// যদি কেউ L দিকে থাকে, তার value = কতোজন left এ আছে = index i

// যদি কেউ R দিকে থাকে, তার value = কতোজন right এ আছে = n-1-i

// Example: "LLR"

// | Index | Char | Contribution |
// | ----- | ---- | ------------ |
// | 0     | L    | 0            |
// | 1     | L    | 1            |
// | 2     | R    | 0            |

// Initial value = 0 + 1 + 0 = 1

// initial = 1
// gains = [2, 2]

// Step 3: Sort Gains Descending

// আমরা যদি একের বেশি person flip করতে পারি, তাহলে সবচেয়ে বড় gain গুলো আগে ব্যবহার করব।

// তাই gains descending order এ sort করি।

// মূল idea: first flip the person with largest gain → maximize value early

// | Step        | k     | Condition  | Action                  | sum | Output    |
// | ----------  | ----- | ---------  | ----------------------- | --- | --------- |
// | 🔹 Start    | —     | —          | sum = 1                 | 1   | —         |
// | ✅ 1st loop | k = 1 | (1 ≤ 2) ✅ | sum += gains[0] = 1 + 2 | 3   | print `3` |
// | ✅ 2nd loop | k = 2 | (2 ≤ 2) ✅ | sum += gains[1] = 3 + 2 | 5   | print `5` |
// | ❌ 3rd loop | k = 3 | (3 ≤ 2) ❌ | skip addition           | 5   | print `5` |

// 📤 Final Output:
// 3 5 5
