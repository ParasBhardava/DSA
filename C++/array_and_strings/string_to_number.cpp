#include <iostream>
#include <cstdio>
#include <sstream>
// #include <boost/lexical_cast.hpp>
using namespace std;
 
int main()
{
    // 1. stringstream() :
    string s = "12345";
    stringstream geek(s);
    int x = 0;
    geek >> x;
    cout << "Value of x : " << x <<"\n";

    // 2. sscanf() :
    const char *str = "12345";
    int y;
    sscanf(str, "%d", &y);
    printf("The value of x : %d\n", y);

    // 3. stoi() and atoi() :
    // Syntax :
    // int atoi (const char * str); 
    // int stoi (const string&  str, size_t* starting_index = 0, int base = 10); 

    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "31337 geek";
    int myint1 = stoi(str1);
    int myint2 = stoi(str2);
    int myint3 = stoi(str3);
    cout<<myint1<<" "<<myint2<<" "<<myint3<<"\n";

    //  4. Using boost lexical cast
    /* Boost library offers an inbuild function “lexical_cast(“string”)”, which directly converts a string to number. It returns an exception “bad_lexical_cast” in case of invalid input. */
//     string str = "5";
//     string str1 = "6.5";

//    float f_value = boost::lexical_cast<float>(str1); 
//    int i_value = boost::lexical_cast<int>(str);
  
//    cout << f_value << " " << i_value <<endl;

    return 0;
}