#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int number_of_candidates, number_of_voters, result, max=0;
    scanf("%d %d", &number_of_candidates, &number_of_voters);
    int vote_per_voter[number_of_voters], votes[number_of_candidates+1];
    
    for(int i = 0; i<number_of_voters; i++)
        {
        scanf("%d ", &vote_per_voter[i]);
        }
    
    for(int i=0; i<number_of_candidates+1; i++)
        {
        votes[i] = 0;
        for(int j = 0; j<number_of_voters; j++)
            {
            if(vote_per_voter[j] == i)
                votes[i]++;
            }
        }
    
    for(int i=0; i<number_of_candidates+1; i++)
        {
        if(votes[i] == max)
            result = -1;
        if(votes[i] > max)
            {
            max =votes[i];
            result= i;
            }
        }
    printf("%d", result);
        
    return 0;
}
