// head is a pointer to first node in linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 4;           // (*head).data = 4;
    head->next = NULL;

    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = 8;
    head->next->next = NULL;

    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->data = 10;
    head->next->next->next = NULL;

   while(head != NULL)
   {
       printf("%d --> ", head->data);
       head = head->next;
   }

    return 0;
}
