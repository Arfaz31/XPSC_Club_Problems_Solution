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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        //  count frequency using map
        map<int, int> freq;
        for (int x : a)
            freq[x]++;

        // find maximum frequency
        int maxFreq = 0;
        for (auto &p : freq)
            maxFreq = max(maxFreq, p.second);

        int result;

        if (maxFreq <= n / 2)
        {

            result = n % 2;
        }
        else
        {

            result = 2 * maxFreq - n;
        }
        cout << result << "\n";
    }
    return 0;
}

// 🔷 Case 1: যখন maxFreq <= n/2

// মানে হচ্ছে —
// সবচেয়ে বেশি যেই সংখ্যা আছে, সেটার সংখ্যাও অর্ধেক বা তার কম।

// 👉 তাহলে তুমি প্রতিটি সবচেয়ে বেশি সংখ্যার পাশে একটা ভিন্ন সংখ্যা খুঁজে পাবে pair বানানোর জন্য।

// উদাহরণ:
// a = [1,2,3,4,5,6]
// এখানে সব ভিন্ন — maxFreq = 1, n/2 = 3
// তুমি pair করতে পারো:
// (1,2), (3,4), (5,6)
// সব মুছে যাবে → remaining = 0.

// আর যদি n odd হয়, যেমন:
// a = [1,2,3]
// একটা unmatched (যেমন 3) থেকে যাবে → remaining = 1.

// 🔷 Case 2: যখন maxFreq > n/2

// মানে হচ্ছে —
// একটা সংখ্যা এত বেশি এসেছে যে,
// তোমার কাছে pair বানানোর মতো বাকি ভিন্ন সংখ্যা কমে গেছে।

// তাহলে:

// তুমি প্রতিবার maxFreq থেকে একটা element আর others থেকে একটা element pair করে বাদ দিতে পারবে।

// কিন্তু একসময় others শেষ হয়ে যাবে।

// তখন maxFreq এর কিছু elements unmatched থেকে যাবে।

// | পরিস্থিতি                                                      | ব্যাখ্যা                                                      | formula         |
// | ------------------------------------------------------------ | --------------------------------------------------------- | --------------- |
// | ১. যখন সংখ্যাগুলা balance আছে (সবাই প্রায় সমান সংখ্যায় আছে)    | সব pair হয়ে যাবে, শুধু parity অনুযায়ী ০ বা ১টা থাকতে পারে    | `n % 2`         |
// | ২️. যখন একটা সংখ্যা অনেক বেশি এসেছে (majority element)       | অন্যগুলো শেষ হয়ে যাবে, কিছু majority বাকি থাকবে            | `2*maxFreq - n` |

// ধরা যাক:

// লাল বলের সংখ্যা বেশি = maxFreq

// অন্য বলের সংখ্যা কম = n - maxFreq

// তুমি pair করতে পারবে যতবার “অন্য বল” আছে ততবার —
// কারণ প্রতিটি অন্য বলের জন্য একটা করে লাল বল নিতে পারো।

// তাহলে pair করা যাবে (n - maxFreq) বার।

// প্রতি pair-এ ২টা বল ফেলা হয়।
// তাহলে মোট মুছে ফেলা বল = 2 * (n - maxFreq)।

// 🔹 এখন ব্যাগে বাকি বল কত?

// মোট ছিল n টা বল।
// ফেলে দিয়েছো 2*(n - maxFreq) টা বল।

// তাহলে বাকি থাকবে:remaining = n - 2*(n - maxFreq)
// এখন এইটাকে সরল করি (simplify করি):
// remaining = n - 2n + 2*maxFreq
// remaining = 2*maxFreq - n

// 🔹 এখন উদাহরণ দিই

// ধরা যাক n = 7,
// আর লাল বল আছে maxFreq = 5 টা,
// অন্য বল ২টা।

// তুমি pair করতে পারবে ২ বার (প্রতি বার ১টা লাল + ১টা অন্য)।
// এই ২টা pair-এ ৪টা বল মুছে যাবে।

// বাকি থাকবে 7 - 4 = 3 টা বল।
// ফর্মুলায় বসাও: 2*maxFreq - n = 2*5 - 7 = 10 - 7 = 3 ✅

// কিছু বাস্তব উদাহরণ (টেস্ট করে দেখে নেওয়া)

// a = [1,6,1,1,4,4], n=6, maxFreq=3 → maxFreq <= 3 (n/2=3) → result = 6%2 = 0

// a = [1,2], n=2, maxFreq=1 → result = 0

// a = [1,1], n=2, maxFreq=2 → maxFreq > n/2 → result = 2*2 - 2 = 2

// a = [4,5,4,5,4], n=5, maxFreq=3 → maxFreq > n/2 (since n/2 = 2) → result = 6 - 5 = 1

// —all match expected.