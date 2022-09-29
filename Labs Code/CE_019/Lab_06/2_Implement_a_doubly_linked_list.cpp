#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define MAXSIZE 10

using namespace std;

typedef struct list_node
{
        int item;
        struct list_node *next;
        struct list_node *prev;
}node;

node *head=NULL, *tail=NULL;
int size = 0;

void insert_at_beginning(int value)
{
    node *temp = new node;
    if(size > MAXSIZE)
    {
        cout<<"List can not accommodate more than "<<MAXSIZE<< " elements\n";
        exit(0);
    }
    
    temp->item = value;
    if(size == 0)
    {
        temp->next= NULL;
        temp->prev = NULL;
        head = temp;
        tail = temp;
        size++;
        return;
    }
    
    head->prev = temp;
    temp->next = head;
    temp->prev = NULL;
    head = temp;
    size++;
}

void insert_at_end(int value)
{
    node *temp = new node;
    if(size > MAXSIZE)
    {
        cout<<"List can not accommodate more than "<<MAXSIZE<<" elements";
        exit(0);
    }
    
    temp->item = value;
    if(size == 0)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        tail = temp;
        size++;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    temp->next = NULL;
    tail = temp;
    size++;
}

void delete_from_beginning()
{
    if(head == NULL || size == 0)
    {
        cout<<"INVALID SEQUENCE OF COMMANDS\n";
        exit(0);
    }
    node *temp = head;
    if(temp->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    head->next->prev = NULL;
    head = head->next;
    free(temp);
    size--;
}


void delete_from_end()
{
    if(tail == NULL || size == 0)
    {
        cout<<"INVALID SEQUENCE OF COMMANDS\n";
        exit(0);
    }
    node *temp = tail;
    tail->prev->next = NULL;
    tail = tail->prev;
    free(temp);
    size--;
}

void print_list()
{
    if(head == NULL || size == 0)
    {
        cout<<"List is Empty\n"; 
        exit(0);
    }
    
    node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
    cout<<"\n";
    
    temp = tail;
    while(temp != NULL)
    {
        cout<<temp->item<<" ";
        temp = temp->prev;
    }
}


int main()
{
    int i;
    while(1)
    {
        cin>>i;
        if(i == 0)
        {
            int val;
            cin>>val;
            insert_at_beginning(val);
        }
        
        else if(i == 1)
        {
            int val;
            cin>>val;
            insert_at_end(val);
        }
        
        else if(i == 2)
        {
            delete_from_beginning();
        }
        
        else if(i == 3)
        {
            delete_from_end();
        }
        
        else if(i == 4)
        {
            print_list();
            break;
        }
        
        else
        {
            cout <<"INVALID SEQUENCE OF COMMANDS";
            exit(0); 
        }
    }
    
    return 0;
}