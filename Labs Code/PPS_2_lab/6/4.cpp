#include <iostream>
using namespace std;

int main()
{
    string s, substr;
    int n;

    getline(cin, s);
    cin >> n >> substr;

    string str = s;
    for (int i = 0; i < n; i++)
    {
        str.append(s);
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str.substr(i, substr.length()) == substr)
            cout << i << " ";
    }

    return 0;
}