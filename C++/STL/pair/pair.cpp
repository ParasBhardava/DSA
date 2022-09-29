#include<iostream>
#include<bits/stdc++.h>
#include<utility>

using namespace std;

// Syntax :
// pair<data_type1, data_type2> Pair_name;

/*
1. The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
2. Pair is used to combine together two values which may be different in type. Pair provides a way to store two heterogeneous objects as a single unit.
3. Pair can be assigned, copied and compared. The array of objects allocated in a map or hash_map are of type ‘pair’ by default in which all the ‘first’ elements are unique keys associated with their ‘second’ value objects.
4. To access the elements, we use variable name followed by dot operator followed by the keyword first or second.
5. operators(=, ==, !=, >=, <=) : We can use operators with pairs as well. 

Member functions :
make_pair() : Pair_name = make_pair (value1,value2);
swap() : pair1.swap(pair2); or swap(pair1, pair2);
tie() : tie(int &, int &) = pair1; 
*/

int main()
{
    // pair intializing
    pair<int, char> pair1;
    cout<<pair1.first<<" "<<pair1.second<<"\n";

    pair1.first = 1;
    pair1.second = 'a';
    cout<<pair1.first<<" "<<pair1.second<<"\n";

    pair1 = make_pair(2,'b'); 
    cout<<pair1.first<<" "<<pair1.second<<"\n";

    pair1 = {3, 'c'}; 
    cout<<pair1.first<<" "<<pair1.second<<"\n";
    
    pair<int, char>pair2(26, 'z');
    cout<<pair2.first<<" "<<pair2.second<<"\n";

    // copy of pair
    pair<int, char>pair3(pair2);
    cout<<pair3.first<<" "<<pair3.second<<"\n";

    pair3 = pair1;
    cout<<pair3.first<<" "<<pair3.second<<"\n";


    // tie() function
    int x, y;
    char z;
    tie(x, z) = pair3;
    cout<<x<<" "<<z<<"\n";


    pair<int, pair<int, char> > pair4 = { 3, { 4, 'a' } };
    x = pair4.first;
    // tie(x,y,z) = pair3; Gives compilation error
    // tie(x, tie(y,z)) = pair3; Gives compilation error
    // Each pair needs to be explicitly handled
    tie(y, z) = pair4.second;
    cout<<x<<" "<<y<<" "<<z<<"\n";


    //swap function
    swap(pair3, pair2);
    cout<<pair3.first<<" "<<pair3.second<<"\n";
    pair3.swap(pair1);
    cout<<pair3.first<<" "<<pair3.second<<"\n";

    return 0;
}