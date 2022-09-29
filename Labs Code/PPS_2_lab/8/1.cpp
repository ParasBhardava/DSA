#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Person
{
    short age;

protected:
    string gender;
    string name;

public:
    Person(string name = "", string gender = "", short age = 0)
    {

        if (gender != "male" && gender != "female" && gender != "other")
            this->gender = "other";

        else
            this->gender = gender;

        this->age = age;
        this->name = name;
    }
    void print()
    {
        cout << name << " " << gender << " " << age << " ";
    }
};

class Employee : public Person
{
    int yearly_salary;

protected:
    string employee_id;
    const string employee_since;
    string designation;
    string department;
    static int count;

public:
    Employee(string name, string gender, short age, string department, string designation, const string since, int yearly_salary) : Person(name, gender, age), employee_since(since)
    {
        this->yearly_salary = yearly_salary;
        this->designation = designation;
        this->department = department;
        set_id();
    }
    int get_id()
    {
        this->count++;
        return count;
    }

    void set_id()
    {
        int n = get_id();
        this->employee_id = "E" + std::to_string(n);
    }

    void print()
    {
        cout << employee_id << " ";
        Person::print();
        cout << department << " " << designation << " " << employee_since << " " << yearly_salary << endl;
    }
    int give_salary()
    {
        return yearly_salary;
    }

    void increase(float units)
    {
        yearly_salary += yearly_salary * (units / 100.0);
    }

    string give_designation()
    {
        return designation;
    }
    void set_designation(string des)
    {
        designation = des;
    }
};
int Employee::count = 0;

class Manager : public Employee
{
protected:
    Employee *direct_reports[10];
    static int direct_reports_count;

public:
    Manager(const Employee &e) : Employee(e)
    {
    }

    void print()
    {
        Employee *temp;
        for (int i = 0; i < direct_reports_count - 1; i++)
        {
            for (int j = i + 1; j < direct_reports_count; j++)
            {
                if (direct_reports[i]->give_salary() < direct_reports[j]->give_salary())
                {
                    temp = direct_reports[i];
                    direct_reports[i] = direct_reports[j];
                    direct_reports[j] = temp;
                }
            }
        }

        Employee::print();
        for (int i = 0; i < direct_reports_count; i++)
        {
            direct_reports[i]->Employee::print();
        }
    }

    void add_direct_report(Employee *emp1)
    {
        direct_reports[direct_reports_count] = emp1;
        direct_reports_count++;
    }

    void change_designation(string existing_designation, string new_designation)
    {
        for (int i = 0; i < direct_reports_count; i++)
        {
            if (direct_reports[i]->give_designation() == existing_designation)
            {
                direct_reports[i]->set_designation(new_designation);
            }
        }
    }

    void increase_salary(string designation, float increment_percentage)
    {
        for (int i = 0; i < direct_reports_count; i++)
        {
            if (direct_reports[i]->give_designation() == designation)
            {
                direct_reports[i]->increase(increment_percentage);
            }
        }
    }
};

int Manager::direct_reports_count = 0;

int main()
{
    string name, gender, department, designation, employee_since;
    short age;
    int yearly_salary;
    cin >> name >> gender >> age >> department >> designation;
    cin >> employee_since >> yearly_salary;
    Employee employee(name, gender, age, department, designation,
                      employee_since, yearly_salary);
    Manager manager(employee);

    int direct_reports_count = 0;
    cin >> direct_reports_count;

    Employee *employee_ptr;
    for (int i = 0; i < direct_reports_count; i++)
    {
        getchar(); // removing newline from input buffer
        cin >> name >> gender >> age >> department >> designation;
        cin >> employee_since >> yearly_salary;
        employee_ptr = new Employee(name, gender, age, department,
                                    designation, employee_since,
                                    yearly_salary);
        manager.add_direct_report(employee_ptr);
    }

    getchar(); // Removing newline from input buffer
    string existing_designation, new_designation;
    cin >> existing_designation >> new_designation;
    manager.change_designation(existing_designation, new_designation);

    float increment_percentage;
    cin >> designation >> increment_percentage;
    manager.increase_salary(designation, increment_percentage);

    manager.print();

    return 0;
}