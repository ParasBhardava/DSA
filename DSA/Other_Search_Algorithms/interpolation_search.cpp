// Sorted array of uniformly distributed values(difference between every consecutive elemnets is same)
// lets search for element key
// formula = start + (key - arr[start] / arr[end] - arr[start]) * (end - start)
// if sorted array is unoformaly distributed then time complekeyity is O(1)
// if uniformality of given data is increases then the number of step increases 
// if uniformality of given data is decreases then the number of step dicreases 

#include<bits/stdc++.h> 
using namespace std; 

int interpolationSearch(int arr[], int n, int key) 
{ 
	int start = 0, end = (n - 1); 

	while (start <= end && key >= arr[start] && key <= arr[end]) 
	{ 
		if (start == end) 
		{ 
			if (arr[start] == key)
                return start; 
			return -1; 
		} 

		int pos = start + (((double)(end - start) / (arr[end] - arr[start])) * (key - arr[start])); 

		if (arr[pos] == key) 
			return pos; 

		if (arr[pos] < key) 
			start = pos + 1; 

		else
			end = pos - 1; 
	} 
	return -1; 
} 

int main() 
{

	int n = 15; 
	int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47}; 

	int key = 18; 
	int indekey = interpolationSearch(arr, n, key); 

	if (indekey != -1) 
		cout << "Element found at indekey " << indekey; 
	else
		cout << "Element not found."; 

	return 0; 
}