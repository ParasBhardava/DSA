// Polish notation 
// first reverse the diven string : )l-k+a(*)c/b-a(
// Then 2 method :
// 1) conver the parenthisis through loop : (l-k+a)*(c/b-a)
// 2) put condition based on this reverse parenthisis
// after choosing one methos follow infix to postfix

#include<iostream>
#include<stack>
#include<algorithm> // for reverse string

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

string infix_to_prefix(string str)
{
    string ans = "";
    reverse(str.begin(), str.end());
    int n = str.length();
    stack<char>st;

    for(int i=0; i<n; i++)
    {
        if((str[i] >= 'A' && str[i] <='B') || (str[i] >= 'a' && str[i] <='z') || (str[i] >= '0' && str[i] <='9'))
        {
            ans+= str[i];
        }

        else if(str[i] == ')')
            st.push(str[i]);

        else if(str[i] == '(')
        {
            while(st.top() != ')')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }    

        else
        {
            while(!st.empty() && prec(str[i]) <= prec(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans; 
}

int main()
{
    string str = "(a-b/c)*(a/k-l)"; //*-a/bc-akl
    string prefix = infix_to_prefix(str);
    cout<<"Infix : "<<str<<"\n";
    cout<<"Prefix : "<<prefix<<"\n";
    return 0;
}