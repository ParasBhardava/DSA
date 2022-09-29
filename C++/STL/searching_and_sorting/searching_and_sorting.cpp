#include <algorithm>
#include <iostream>

using namespace std;

struct s
{
    int start;
    int end;
};

bool comparator(s s1, s s2)
{
    return (s1.start < s2.start);
}

int main()
{
	int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int asize = sizeof(a) / sizeof(a[0]);
    s arr[] =  { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    int size = sizeof(arr) / sizeof(arr[0]);

	// sort the array
	sort(a, a + asize);
    cout<<"Sort Array in ascending order : ";
    for(int i=0; i<asize; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    sort(a, a+asize, greater<int>());
    cout<<"Sort Array in descending  order : ";
    for(int i=0; i<asize; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    // sort in particular order
    sort(arr, arr+size, comparator);
    cout << "array sorted by starting element : ";
    for (int i = 0; i < size; i++)
        cout << "[" << arr[i].start << "," << arr[i].end
             << "] ";
    cout<<endl;

    if (binary_search(a, a + 10, 2))
         cout<<"found"<<endl;

    if (binary_search(a, a + 10, 10))
        cout<<"found"<<endl;
    else
        cout<<"Not found"<<endl;    

	return 0;
}

// Sorting :-
// sort(startaddress, endaddress, function_pointer)

// startaddress: the address of the first 
//               element of the array
// endaddress: the address of the next 
//             contiguous location of the 
//             last element of the array.
// function_pointer: Optional

// Searching :-
// binary_search(startaddress, endaddress, valuetofind)

// startaddress: the address of the first 
//               element of the array.
// endaddress: the address of the next contiguous 
//             location of the last element of the array.
// valuetofind: the target value which we have 
//              to search for.
// Returns: true if an element equal to valuetofind is found, else false.