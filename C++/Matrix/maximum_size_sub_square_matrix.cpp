#include <bits/stdc++.h>
#define ROW 6
#define COLUMN 5
using namespace std;


void printMaxSubSquare(int M[ROW][COLUMN])
{
	int i,j;
	int ans[ROW][COLUMN];
	int max_of_ans, max_i, max_j;
	
	for(i = 0; i < ROW; i++)
		ans[i][0] = M[i][0];
	
	for(j = 0; j < COLUMN; j++)
		ans[0][j] = M[0][j];
		
	for(i = 1; i < ROW; i++)
	{
		for(j = 1; j < COLUMN; j++)
		{
			if(M[i][j] == 1)
				ans[i][j] = min(ans[i][j-1], min(ans[i-1][j],ans[i-1][j-1])) + 1;
			
            else
				ans[i][j] = 0;
		}
	}
	
	max_of_ans = ans[0][0]; max_i = 0; max_j = 0;
	for(i = 0; i < ROW; i++)
	{
		for(j = 0; j < COLUMN; j++)
		{
			if(max_of_ans < ans[i][j])
			{
				max_of_ans = ans[i][j];
				max_i = i;
				max_j = j;
			}
		}			
	}

	cout<<"Maximum size sub-matrix is: "<< max_of_ans<<"\n";
	for(i = max_i; i > max_i - max_of_ans; i--)
	{
		for(j = max_j; j > max_j - max_of_ans; j--)
		{
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	int M[ROW][COLUMN] = {{0, 1, 1, 0, 1},
					      {1, 1, 0, 1, 0},
					      {0, 1, 1, 1, 0},
					      {1, 1, 1, 1, 0},
					      {1, 1, 1, 1, 1},
					      {0, 0, 0, 0, 0}};
					
	printMaxSubSquare(M);
}
