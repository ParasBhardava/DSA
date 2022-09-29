#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Product
{
    string name;
    float price;

public:
    Product(string name = "", float price = 0)
    {
        this->name = name;
        this->price = price;
    }

    Product(const Product &p)
    {
        name = p.name;
        price = 2 * p.price;
    }

    void print()
    {
        cout << name << " ";
        printf("%0.2f", price);
    }
};

int main()
{
    string name;
    float price;
    cin >> name >> price;

    Product pr1(name, price);
    Product pr2 = Product(pr1);
    pr2.print();

    return 0;
}
