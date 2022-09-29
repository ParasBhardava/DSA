#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
}date;


void sorts_array_of_date(date dates[], int n)
    {
    printf("%d\n", n);
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            {
            date swap;
            if(dates[i].year > dates[j].year)
                {
                swap = dates[j];
                dates[j] = dates[i];
                dates[i] = swap;
                }  
            else if(dates[i].month > dates[j].month)
                {
                swap = dates[j];
                dates[j] = dates[i];
                dates[i] = swap;
                }
            else if(dates[i].day > dates[j].day)
                {
                swap = dates[j];
                dates[j] = dates[i];
                dates[i] = swap;
                }
            else if(dates[i].hour > dates[j].hour)
                {
                swap = dates[j];
                dates[j] = dates[i];
                dates[i] = swap;
                }
            else if(dates[i].minute > dates[j].minute)
                {
                swap = dates[j];
                dates[j] = dates[i];
                dates[i] = swap;
                }
            else if(dates[i].second > dates[j].second)
                {
                swap = dates[j];
                dates[j] = dates[i];
                dates[i] = swap;
                }  
            }
    }

void print_date(date dates[], int n)
    {
    for(int i=0; i<n; i++)
        printf("%02d/%02d/%04d %02d:%02d:%02d\n", dates[i].day, dates[i].month, dates[i].year, dates[i].hour, dates[i].minute, dates[i].second);
    }


int main()
{
    int n;
    scanf("%d", &n);
    date dates[n];
    
    for(int i=0; i<n; i++)
        {
        scanf("%d %d %d %d %d %d ", &dates[i].year, &dates[i].month, &dates[i].day ,&dates[i].hour, &dates[i].minute, &dates[i].second);
        }
    
    sorts_array_of_date(dates, n);
    print_date(dates, n);
    
    return 0;
}