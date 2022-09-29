#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int r_no;
    int marks;
    char dept[3];
}student;

int main()
{
    int num, max = 0, max_marks_of_CE = 0, max_marks_of_EC = 0, max_marks_of_IT = 0;
    scanf("%d", &num);
    int arr_CE[25], arr_EC[25], arr_IT[25];
    
    student *ptr;
    ptr = (student *)malloc(num * sizeof(student));
    
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &(ptr + i)->r_no);
        scanf("%d", &(ptr + i)->marks);
        scanf("%s", (ptr + i)->dept);
    }
    
    int j = 0, k = 0, l = 0;
    for (int i = 0; i < num; i++)
    {
        if (!(strcmp((ptr + i)->dept, "CE")))
        {

            arr_CE[j] = i;
            j++;
        }
        if (!(strcmp((ptr + i)->dept, "EC")))
        {

            arr_EC[k] = i;
            k++;
        }
        if (!(strcmp((ptr + i)->dept, "IT")))
        {

            arr_IT[l]= i;
            l++;
        }
        
        if (max < ((ptr + i)->marks))
            max = (ptr + i)->marks;
    }
    printf("%d\n", max);
    
    if (j == 0)
    {
        printf("0\tCE\n");
    }
    else
    {
        for (int i = 0; i < j; i++)
        {
            if (max_marks_of_CE < ((ptr + (arr_CE[i]))->marks))
                max_marks_of_CE = (ptr + (arr_CE[i]))->marks;
        }

        printf("%d\tCE\n", max_marks_of_CE);
    }

    if (k == 0)
    {
        printf("0\tEC\n");
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            if (max_marks_of_EC < ((ptr + (arr_EC[i]))->marks))
                max_marks_of_EC = (ptr + (arr_EC[i]))->marks;
        }
        
        printf("%d\tEC\n", max_marks_of_EC);
    }

    if (l == 0)
    {
        printf("0\tIT\n");
    }
    else
    {
        for (int i = 0; i < l; i++)
        {
            if (max_marks_of_IT < ((ptr + (arr_IT[i]))->marks))
                max_marks_of_IT = (ptr + (arr_IT[i]))->marks;
        }

        printf("%d\tIT\n", max_marks_of_IT);
    }
    
    return 0;
}
