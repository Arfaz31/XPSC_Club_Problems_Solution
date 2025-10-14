#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        if (mp[name] == 0)
        {
            cout << "OK\n";
            mp[name] = 1;
        }
        else
        {
            string new_name = name + to_string(mp[name]);
            cout << new_name << "\n";
            mp[name]++;
            mp[new_name] = 1;
        }
    }
    return 0;
}

// Step 0:
// map<string,int> db;  // খালি

// Iteration 1: i = 0, name = "first"
// if (db["first"] == 0) // true, map খালি
// আমরা "OK" print করি
// db update: db["first"] = 1
// first -> 1
// Output so far: OK

// Iteration 2: i = 1, name = "first"
// if (db["first"] == 0) // false, db["first"] = 1
// নতুন name তৈরি: new_name = "first" + to_string(db["first"]) = "first1"

// print "first1"

// update db:
// db["first"]++ → db["first"] = 2
// db["first1"] = 1

// first  -> 2
// first1 -> 1

// Output so far:
// OK
// first1
