#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void createStack(struct stack *ptr, int size)
{
    ptr->size = size;
    ptr->top = -1;
    ptr->arr = (int *)malloc(size * sizeof(int));
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;

    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size) - 1)
        return 1;

    else
        return 0;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", value);
    }

    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int stackBottom(struct stack* sp){
    return sp->arr[0];
}

int peek(struct stack *ptr, int i)
{
    if((ptr->top) - i + 1 < 0)
    {
        printf("Not a valid position for stack\n");
        return -1;
    }

    else
        return ptr->arr[(ptr->top)-i+1];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    
    createStack(s, 4);
    push(s, 4);
    push(s, 2);
    push(s, 6);
    push(s, 8);
    printf("%d\n", peek(s, 2));
    printf("%d\n", stackTop(s));
    printf("%d\n", stackBottom(s));

    // LIFO --- last in first out
    for(int i = 1; i <= s->top+1; i++)
    {
        printf("%d ", peek(s, i));
    }

    return 0;
}