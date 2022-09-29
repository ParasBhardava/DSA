#include<iostream>
#include <sstream>
// #include <boost/lexical_cast.hpp>
#include <string>

using namespace std;
int main()
{
    // 1. using stringstream
    int num = 2016; 
    ostringstream str1;
    str1 << num;
    string geek = str1.str();
    cout << geek << "\n";

    // 2. Using to_string() :
    int i_val = 20;
    float f_val = 30.50;  
    string stri = to_string(i_val);
    string strf = to_string(f_val);
    cout<<stri<<" "<<strf<<"\n";

    // 3. Using boost lexical cast
    // float f1 = 10.5;
    // int i1 = 17;
    // string sf = boost::lexical_cast<string>(f1); 
    // string si = boost::lexical_cast<string>(i1); 
    // cout<<sf<<" "<<si<<"\n";

    return 0;
}