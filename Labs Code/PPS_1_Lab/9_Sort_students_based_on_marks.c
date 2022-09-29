#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char name[20];
	int marks[3];
	int total_marks;
}student;

void sort_based_on_marks(student result[], int num_of_students)
{
    student swap;
    for(int i = 0; i<num_of_students-1; i++)
        {
             for(int j = i+1; j < num_of_students; j++)
                 {
                 if(result[j].total_marks > result[i].total_marks)
                     {
                           swap = result[j];
                           result[j] = result[i];
                           result[i] = swap;
                     }
                 }
        }
}

int main()
{
    int num_of_students;
    scanf("%d", &num_of_students);
    student result[num_of_students];
    
    for(int i = 0; i<num_of_students; i++)
        {
        scanf("%d %s", &result[i].id, result[i].name);
        for(int j = 0; j < 3; j++)
            scanf("%d ", &result[i].marks[j]);
        
        result[i].total_marks = result[i].marks[0] +  result[i].marks[1]
                                + result[i].marks[2];
        
        }
    
    printf("%d\n", num_of_students);
    sort_based_on_marks(result, num_of_students);
    for(int i=0; i<num_of_students; i++)
        printf("%s %d %d\n", result[i].name, result[i].id, result[i].total_marks);

    return 0;
}