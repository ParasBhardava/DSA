#include <iostream>
#include <string>

using namespace std;

class Employee
{
    string employee_id;
    string employee_name;
    string designation;
    int salary;

public:
    Employee(string employee_id = "", string employee_name = "", string designation = "", int salary = 0)
    {
        this->employee_id = employee_id;
        this->employee_name = employee_name;
        this->designation = designation;
        this->salary = salary;
    }

    void increment(int salary)
    {
        this->salary += salary;
    }

    friend class Company;
};

class Company
{
    string name;
    Employee employee[10];
    int employee_count;

public:
    Company(string name)
    {
        this->name = name;
        employee_count = 0;
    }

    void add_employee(Employee E)
    {
        if (employee_count < 10)
        {
            for (int i = 0; i < employee_count; i++)
            {
                if (employee[i].employee_id == E.employee_id)
                    return;
            }
            employee[employee_count] = E;
            employee_count++;
        }

        else
        {
            return;
        }
    }

    void print()
    {
        for (int i = 0; i < employee_count; i++)
        {
            cout << employee[i].employee_id << " " << employee[i].employee_name << " " << employee[i].designation << " "
                 << employee[i].salary << endl;
        }
    }

    void increase_salary(string employee_id, int increment_salary)
    {
        for (int i = 0; i < employee_count; i++)
        {
            if (employee[i].employee_id == employee_id)
            {
                employee[i].increment(increment_salary);
            }
        }
    }
};

int main()
{

    string company_name;
    cin >> company_name;
    Company C(company_name);

    int n;
    cin >> n;
    string id, employee_name, designation;
    int salary;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> employee_name >> designation >> salary;
        Employee E(id, employee_name, designation, salary);
        C.add_employee(E);
    }

    cin >> n;
    int increment_salary;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> increment_salary;
        C.increase_salary(id, increment_salary);
    }

    C.print();

    return 0;
}