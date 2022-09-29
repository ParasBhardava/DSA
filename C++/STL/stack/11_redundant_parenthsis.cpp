#include<iostream>
#include<stack>

using namespace std;

int redundant_parenthisis(string str)
{
    int ans = 0;
    int n = str.size();
    stack<char>st;
    for(int i=0; i<n; i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }

        else if(str[i] == ')')
        {
            if(st.top() == '(')
            {
                ans++;
            }

            while(!st.empty() && st.top() != '(')
            {
                st.pop();
            }
            st.pop();
        }

        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            st.push(str[i]);
        }    
    }

    return ans;
}

int main()
{
    string str = "((a+b)+((b+c)))";
    int red = redundant_parenthisis(str);
    cout<<red;
    return 0;
}