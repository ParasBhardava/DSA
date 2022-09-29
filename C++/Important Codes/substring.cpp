#include<iostream>
#include<string>

int to_char(char ch)
{
    return ch-'0';
}

void subString(std::string str)
{
    int n = str.length();
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n-i; j++)
            std::cout<<str.substr(i, j)<<std::endl;   
    }
}

int sum_of_subSting(std::string str)
{
    int n = str.length();
    int current;
    int num = to_char(str[0]);
    int previous = num;
    int result = num;

    for(int i = 1; i<n; i++)
    {
        num = to_char(str[i]);
        current = (i+1) * num + 10*previous;
        result += current;
        previous = current;
    }

    return result;
}

int main()
{
    std::string str = "1234";
    subString(str);
    std::cout<<"Sum of all possible substring is : "<<sum_of_subSting(str);  
}

// Sum Of Substring
// 1234 :-
// 1 : 1
// 2 : 2+12 = 14
// 3 : 3+23+123 = 149
// 4 : 4+34+234+1234 = 1506
// 1 + 14 + 149 + 1506 = 1670