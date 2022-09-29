/*
1) Create a stack to store operands (or values).
2) Scan the given expression from right to left t and do following for every scanned element.
…..a) If the element is a number, push it into the stack
…..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer

*/

#include <iostream>
#include <stack>
#include<string>
using namespace std;

int prefix_evaluation(string str)
{
    int n = str.length();
    stack<int> st;

    for (int i = n-1; i >= 0 ; i--)
    {
        if (isdigit(str[i]))
        {
            st.push(str[i] - '0');
        }

        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            switch (str[i])
            {
            case '+':
                st.push(val1 + val2);
                break;

            case '-':
                st.push(val1 - val2);
                break;

            case '*':
                st.push(val1 * val2);
                break;

            case '/':
                st.push(val1 / val2);
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    string str = "-+7*45+20";
    int ans = prefix_evaluation(str);
    cout <<ans<< "\n";

    return 0;
}