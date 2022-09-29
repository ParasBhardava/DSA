#include<stdio.h>

struct node
{
    int data;
    struct node *next;            // Self refrential structure
};

int main()
{
    struct node nd1;
    nd1.data = 7;
    nd1.next = NULL;

    struct node nd2;
    nd2.data = 9;
    nd2.next = NULL;
    nd1.next = &nd2;

    struct node nd3;
    nd3.data = 12;
    nd3.next = NULL;
    nd2.next = &nd3;

    printf("%d %d %d", nd1.data, nd2.data, nd3.data);

    return 0;
} 