/*
 Heap data structure can be implemented in a range using STL which allows faster input into heap and retrieval of a number always results in the largest number i.e. largest number of the remaining numbers is popped out each time. Other numbers of the heap are arranged depending upon the implementation.

1. make_heap() :- This function is used to convert a range in a container to a heap.
2. front() :- This function displays the first element of heap which is the maximum number.

3. push_heap() :- This function is used to insert elements into heap. The size of the heap is increased by 1. New element is placed appropriately in the heap.

4. pop_heap() :- This function is used to delete the maximum element of the heap. The size of heap is decreased by1. The heap elements are reorganised accordingly after this operation.

5. sort_heap() :- This function is used to sort the heap. After this operation, the container is no longer a heap.

6. is_heap() :- This function is used to check whether the container is heap or not. Generally, in most implementations, the reverse sorted container is considered as heap. Returns true if container is heap else returns false.

7. is_heap_until() :- This function returns the iterator to the position till the container is the heap. Generally, in most implementations, the reverse sorted container is considered as heap.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v = {2, 5, 1, 8, 4, 7, 9};
    make_heap(v.begin(), v.end());
    
    cout<<"Heap : ";
    for(auto i : v)
        cout<<i<<" ";
    cout<<"\n";

    cout<<"max_element : "<<v.front()<<"\n";

    v.push_back(11);
    push_heap(v.begin(), v.end());    
    
    for(auto i : v)
        cout<<i<<" ";
    cout<<"\n";

    cout<<"max_element : "<<v.front()<<"\n";

    pop_heap(v.begin(), v.end());
    v.pop_back();

    for(auto i : v)
        cout<<i<<" ";
    cout<<"\n";
    
    cout<<"max_element : "<<v.front()<<"\n";

    cout<<"sorted_heap : ";
    sort_heap(v.begin(), v.end());
    for(auto i : v)
        cout<<i<<" ";
    cout<<"\n";

    // -----------------------------------------------------------------------------------------------
    vector<int> v1 = {40, 30, 25, 35, 15};
      
    // Declaring heap iterator
    vector<int>::iterator it1;
    
    is_heap(v1.begin(), v1.end()) ? cout << "The container is heap ": cout << "The container is not heap";
    cout << endl;
      
    auto it = is_heap_until(v1.begin(), v1.end());
    cout << "The heap elements in container are : ";
    for (it1=v1.begin(); it1!=it; it1++)
       cout << *it1 << " ";
     
    return 0;
}
