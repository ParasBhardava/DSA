#include <iostream>
#include <string>
using namespace std;

class Person
{
    string name;
    int age;

public:
    Person() {}

    Person(string s, int a)
    {
        name = s;
        age = a;
    }

    void print()
    {
        cout << age << " " << name << "\n";
    }
};

class Family
{
    Person p[20];
    int member_count;

public:
    Family()
    {
        member_count = 0;
    }

    void add_member(string s, int i)
    {
        p[member_count] = Person(s, i);
        member_count++;
    }

    void print()
    {
        for (int i = 0; i < member_count; i++)
            p[i].print();
    }
};

int main()
{

    int n;
    cin >> n;
    Family f;

    for (int i = 0; i < n; i++)
    {
        string s;
        int k;
        cin >> s >> k;
        f.add_member(s, k);
    }

    f.print();

    return 0;
}