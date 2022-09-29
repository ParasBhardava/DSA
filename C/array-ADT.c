#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;

};

void createArray(struct myArray *a, int tsize, int usize)
{
    a -> total_size = tsize;
    a -> used_size = usize;
    a -> ptr = malloc(tsize*sizeof(int));
}

void setVal(struct myArray * a)
{
    printf("Enter elements:\n");
    for(int i=0; i < a->used_size; i++)
    {
        scanf("%d", &((a->ptr)[i]));
    }
}

void getVal(struct myArray * a)
{
    for(int i=0; i < a->used_size; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
}

int main()
{
    struct myArray array;
    createArray(&array, 100, 10);
    setVal(&array);
    getval(&array);

    return 0;
}