#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> s;
    s.insert("abc"); // O(logn)
    s.insert("xyz");
    s.insert("xyz");
    s.insert("pqr");
    s.insert("mno");
    s.erase("pqr"); // O(logn)

    for (auto val : s)
    {
        cout << val << " ";
    }
    cout << "\n";

    auto it = s.find("abcd"); // O(logn)
    if (it != s.end())
    {
        cout << (*it);
    }

    cout << s.insert("abc").second << "\n";   // return false because "abc" is already present in set
    cout << s.insert("paras").second << "\n"; // return true because "paras" is not pesent in set, it is a new element

    return 0;
}