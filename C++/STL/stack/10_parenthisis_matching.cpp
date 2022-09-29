#include <iostream>
#include <stack>

using namespace std;
bool areBracketsBalanced(string str)
{
    int n = str.length();
    stack<char>st;
    char ch;

    for(int i=0; i<n; i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
            continue;
        }

        if(st.empty())
            return false;

        switch(str[i])
        {
            case ')':
            ch = st.top();
            st.pop();
            if(ch == '{' || ch == '[')
                return false;
            break;

            case '}':
            ch = st.top();
            st.pop();
            if(ch == '(' || ch == '[')
                return false;
            break;


            case ']':
            ch = st.top();
            st.pop();
            if(ch == '(' || ch == '{')
                return false;
            break;    
        }    
    }

    return st.empty();
}

int main()
{
    string str = "[{()}()]";
    if (areBracketsBalanced(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}