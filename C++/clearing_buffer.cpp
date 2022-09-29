/*
1. Using "cin.ignore(numeric_limits::max(),'\n');" :- Typing "cin.ignore(numeric_limits::max(),'\n');" after the    
   "cin" statement discards everything in the input stream including the newline.

2. Using "cin.sync()" : Typing "cin.sync()" after the "cin" statement discards all that is left in buffer. Though  
   "cin.sync()" does not work in all implementations (According to C++11 and above standards).   

3. Using "cin >> ws" : Typing "cin>>ws" after "cin" statement tells the compiler to ignore buffer and also to  
   discard all the whitespaces before the actual content of string or character array.    
*/

#include<iostream>

using namespace std;

int main()
{
    int a;
    string s;

    // 1st method  
    cin >> a;    
    cin >> ws;
    getline(cin, s);
    
    // 2nd method
    /* 
        cin >> a;
        cin.sync();
        getline(cin, s);
    */

   // 3rd method
   /*
        cin >> a;
        cin >> ws;
        getline(cin, s);
   */
    
    cout << a << endl;
    cout << s << endl;

    return 0;
}