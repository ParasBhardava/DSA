#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct employee 
{
    char name[20];
    int id;
    int experience;
    int salary;
};

int main()
{
    int n, count =0;
    scanf("%d", &n);
    struct employee person[n];
    
    for(int i=0; i<n; i++)
        {
        scanf("%s %d %d %d", person[i].name, &person[i].id, &person[i].experience, &person[i].salary);
        if(person[i].experience >=7 && person[i].salary <50000)
            count++;
        }
    
        printf("%d\n", count);
        for(int i=0; i<n; i++)
            {
            if(person[i].experience>=7 && person[i].salary<50000)
                printf("%d %s\n", person[i].id, person[i].name);
            }

    return 0;
}
