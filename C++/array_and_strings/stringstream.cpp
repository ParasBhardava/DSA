#include<iostream>
#include<bits/stdc++.h>

std::string removespace(std::string str)
{
    std::stringstream ss(str);
    str = "";
    std::string temp;

    while(ss>>temp)
    {
        str += temp;
    }

    return str;
}


int main()
{
    std::string str = "My name is Paras";
    std::cout<<removespace(str);

    return 0;
}