#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *insert(node **head_ptr, int value)
{
    if(head_ptr == NULL)
        return NULL;
    
    node *new_node;
    new_node = (node *)malloc(sizeof(node));

    if(new_node == NULL)
        return NULL;

    new_node->data = value;
    new_node->next = *head_ptr;
    *head_ptr = new_node;

    return new_node;       
}

node *insert_at_beggining(node **head_ptr, int value)
{
    return insert(head_ptr, value);
}

node *insert_at_end(node **head_ptr, int value)
{
    if(head_ptr == NULL)
        return NULL;

    while(*head_ptr != NULL)
    {
        head_ptr = &((*head_ptr)->next);
    }    

    return insert(head_ptr, value);
}

node *insert_at_index(node **head_ptr, int value, int index)
{
    if(head_ptr == NULL)
        return NULL;

    for(int i=0; i<index; i++)
        head_ptr = &((*head_ptr)->next);

    return insert(head_ptr, value);    
}

node *insert_after_node(node **head_ptr, int value, int node)
{
    if(head_ptr == NULL)
        return NULL;

    for(int i=0; i<node; i++)
        head_ptr = &((*head_ptr)->next);

    return insert(head_ptr, value);
}

node *insert_in_order(node **head_ptr, int value)
{
    if(head_ptr == NULL)
        return NULL;

    while(*head_ptr != NULL && (*head_ptr)->data <= value)
    {
        head_ptr = &((*head_ptr)->next);
    }    

    return insert(head_ptr, value);
}

int delete(node **head_ptr)
{
    if(head_ptr == NULL || *head_ptr == NULL)
        return 0;

    node *temp =  *head_ptr;
    *head_ptr = (*head_ptr)->next;
    free(temp);
    return 1;   
}

int delete_from_beginning(node **head_ptr)
{
    return delete(head_ptr);
}

int delete_from_end(node **head_ptr)
{
    if(head_ptr == NULL || *head_ptr == NULL)
        return 0;

    while((*head_ptr)->next != NULL)
        head_ptr = &((*head_ptr)->next);

    return delete(head_ptr);        
}

int delete_value(node **head_ptr, int value)
{
    if(head_ptr == NULL || *head_ptr == NULL)
        return 0;

    while((*head_ptr)->next != NULL && (*head_ptr)->data != value)
        head_ptr = &((*head_ptr)->next);

    if((*head_ptr)->data == value)
        return delete(head_ptr);
    else
        return 0;
}

int delete_at_index(node **head_ptr, int index)
{
    if(head_ptr == NULL || *head_ptr == NULL)
        return 0;

    for(int i=0; i<index; i++)
        head_ptr = &((*head_ptr)->next);

    return delete(head_ptr);         

}

int delete_after_node(node **head_ptr, int node)
{
    if(head_ptr == NULL || *head_ptr == NULL)
        return 0;

    for(int i=0; i<node; i++)
        head_ptr = &((*head_ptr)->next);    

    return delete(head_ptr);    

} 

void print(node *nd)
{
    while(nd != NULL)
    {
        printf("%d --> ", nd->data);
        nd = nd->next;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    
    insert_at_end(&head, 3);
    insert_at_end(&head, 8);
    insert_at_end(&head, 6);
    insert_at_end(&head, 1);
    print(head);
    delete_after_node(&head, 2);
    print(head);
    return 0;
}