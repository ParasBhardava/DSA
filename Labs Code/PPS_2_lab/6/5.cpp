#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Engineer
{
    string name;
    int salary;

public:
    void setter(int n, string s)
    {
        salary = n;
        name = s;
    }

    void print()
    {
        cout << name << " " << salary << "\n";
    }
};

class Manager
{
    string name;
    int salary;

public:
    void setter(int n, string s)
    {
        salary = n;
        name = s;
    }

    void print()
    {
        cout << name << " " << salary << "\n";
    }
};

class TeamLeader
{
    string name;
    int salary;

public:
    void setter(int n, string s)
    {
        salary = n;
        name = s;
    }

    void print()
    {
        cout << name << " " << salary << "\n";
    }
};

void total_bonus(int &EngineerBonus, int &ManagerBonus, int &TeamLeaderBonus, int &totalBonus, char ch, int sal)
{
    switch (ch)
    {
    case 'E':
        EngineerBonus += sal * 0.25;
        totalBonus += sal * 0.25;
        break;

    case 'M':
        ManagerBonus += sal * 0.3;
        totalBonus += sal * 0.3;
        break;

    case 'T':
        TeamLeaderBonus += sal * 0.28;
        totalBonus += sal * 0.28;
        break;
    }
}

int main()
{

    int n, salary, Engineer_bonus = 0, Manager_bonus = 0, TeamLeader_bonus = 0, Total_bonus = 0;
    string name;
    char ch;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        cin >> salary;
        getline(cin, name);

        if (ch == 'E')
        {
            Engineer e;
            e.setter(salary, name);
            e.print();
            total_bonus(Engineer_bonus, Manager_bonus, TeamLeader_bonus, Total_bonus, ch, salary);
        }

        else if (ch == 'M')
        {
            Manager mng;
            mng.setter(salary, name);
            mng.print();
            total_bonus(Engineer_bonus, Manager_bonus, TeamLeader_bonus, Total_bonus, ch, salary);
        }

        else if (ch == 'T')
        {
            TeamLeader t;
            t.setter(salary, name);
            t.print();
            total_bonus(Engineer_bonus, Manager_bonus, TeamLeader_bonus, Total_bonus, ch, salary);
        }
    }

    cout << Engineer_bonus << " " << TeamLeader_bonus << " " << Manager_bonus << " " << Total_bonus;

    return 0;
}
