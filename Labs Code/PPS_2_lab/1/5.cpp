#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n, key;
    string str;
    cin >> n >> key;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] >= 'A' && str[j] <= 'Z')
                str[j] = (str[j] - 'A' + key) % 26 + 'A';

            else if (str[j] >= 'a' && str[j] <= 'z')
                str[j] = (str[j] - 'a' + key) % 26 + 'a';

            else
                str[j] = (str[j] - 48 + key) % 10 + 48;
        }

        cout << str << endl;
    }

    return 0;
}