/*
Reverse polish notation
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it. 
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator add it to answer. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.
*/
#include <iostream>
#include <stack>

using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/')
        return 2;
    else if (c == '*')
        return 1;
    else if (c == '+' || c == '-')
        return -1;
    else
        return -2;
}

string infix_to_postfix(string str)
{
    int n = str.length();
    string ans;
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9'))
        {
            ans += str[i];
        }

        else if (str[i] == '(')
            st.push(str[i]);

        else if (str[i] == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && prec(str[i]) <= prec(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string str = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infix_to_postfix(str);
    cout<<"infix : "<<str<<"\n";
    cout<<"Postfix : "<<postfix<<"\n";
    return 0;
}