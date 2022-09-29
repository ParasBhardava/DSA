#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sort_list(float list[], int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(list[j] < list[i])
            {
            int temp = list[j];
            list[j] = list[i];
            list[i] = temp;
            }
        }
    }
}

int main()
{
    int n;
    float sum = 0;
    float list[10000];

    for(int i =0;i<10000; i++)
    {
        scanf("%f ", &list[i]);
        n = i;
        if(list[i] == -1)
        {
            break;
        }
     } 
   
    sort_list(list, n);
        for(int i = 0; i<n; i++)
        {
            sum += list[i];
        }
    float mean = sum/n;
    printf("%.2f ", mean);
    
    float median;
    if(n%2 == 0)
        median  = (list[n/2] + list[n/2-1])/2;
    else 
        median = list[(n-1)/2];
    printf("%.2f ", median);
    
    int frequency[n];
    float mode;
    int max_frequency = 1;
    for(int i= 0; i<n; i++)
    {
        frequency[i] = 1;
        for(int j = i+1; j<n; j++)
        {
            if(list[i] == list[j])
            {
                frequency[i]++;
            }
        }
    }

    for(int i = 0; i<n; i++)
    {
        if(frequency[i] == max_frequency)
            mode = -1.00;
        if(frequency[i] > max_frequency)
        {
            max_frequency = frequency[i];
            mode = list[i];
        } 
    }
    printf("%.2f", mode);

    return 0;
}
