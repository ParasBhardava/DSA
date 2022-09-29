#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;

    else
        return 0;
}

int presedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;

    else if (ch == '+' || ch == '-')
        return 2;

    else
        return 1;
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

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

char *infixToPostfix(char *infix)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }

        else
        {
            if (presedence(infix[i]) > presedence(stackTop(s)))
            {
                push(s, infix[i]);
                    i++;
            }

            else
            {
                postfix[j] = pop(s);
                j++;
            }
        }
    }

    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *exp = "a-b+c/d";
    printf("%s", infixToPostfix(exp));

        return 0;
}
