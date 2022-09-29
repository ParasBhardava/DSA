#include<iostream>
using namespace std;

class Complex
{
    int a, b;
public:
    friend Complex multiplicationComp(Complex, Complex);
    void setData(int n1, int n2){+
        a = n1;
        b = n2;
    }

    void getData(){
        cout<<"Your complex number is "<<a<<" + "<<b<<"i"<<endl;
    }

};

Complex multiplicationComp(Complex o1, Complex o2){
    Complex o3;
    o3.setData( ((o1.a * o2.a)-(o1.b*o2.b))  ,  ((o1.a * o2.b)+(o1.b*o2.a))   );
    return o3;
}

int main()
{
    Complex c1, c2, c3;
    c1.setData(2,1);
    //c1.getData();

    c2.setData(3, 3);
    //c1.getData();

    c3 = multiplicationComp(c1, c2);
    c3.getData();

    return 0;
}
