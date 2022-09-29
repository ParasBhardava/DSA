#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

int main()
{
    int n;
    scanf("%d", &n);
    int num;
    node *head = NULL, *last = NULL, *temp = NULL;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        temp = (node*)malloc(sizeof(node));

        if(temp == NULL)
            exit(1);

        temp->data = num;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            last = temp;
        }

        else
        {
            last->next = temp;
            last = temp;
        }    
    }

    temp = head;
    while(temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }


    return 0;
}