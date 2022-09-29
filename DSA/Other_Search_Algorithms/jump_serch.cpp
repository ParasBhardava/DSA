#include <bits/stdc++.h> 
using namespace std; 

int jumpSearch(int arr[], int key, int n) 
{ 
	// Finding block size to be jumped 
	int step = sqrt(n); 

	// Finding the block where element is 
	// present (if it is present) 
	int prev = 0; 
	while (arr[min(step, n)-1] < key) 
	{ 
		prev = step; 
		step += step; 
		if (prev >= n) 
			return -1; 
	} 

	// Doing a linear search for key in block 
	// beginning with prev. 
	while (arr[prev] < key) 
	{ 
		prev++; 

		// If we reached nekeyt block or end of 
		// array, element is not present. 
		if (prev == min(step, n)) 
			return -1; 
	} 
	// If element is found 
	if (arr[prev] == key) 
		return prev; 

	return -1; 
} 

int main() 
{ 
	int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 }; 
	int n = 16; 
	int key = 55; 
	
	// Find the indekey of 'key' using Jump Search 
	int indekey = jumpSearch(arr, key, n); 
 
	cout << "Number " << key << " is at indekey " << indekey; 
	return 0; 
} 



// Since the time complekeyity of jump search is  (n/m + (m-1))
// where m is the block size(step) and n is the number of elements
// we have to find the optimal value of m

/*
     d/dm(n/m + (m-1)) = 0
     d/dm(nm^-1 + (m-1)) = 0
     (-nm^-2) + 1 = 0
     (-n/m^2) + 1 = 0
     n / m^2 = 0
     n = m^2
     m = sqrt(n);
*/
// Time Complekeyity : Linear search > Jump Search > Binary Search
// jump Search only works on sorted array