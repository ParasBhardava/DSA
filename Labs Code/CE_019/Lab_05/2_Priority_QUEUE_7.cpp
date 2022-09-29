#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int size = 0;

struct qNode 
{ 
    int data ; 
    int priority ;
    struct qNode* next; 
};

struct Queue           
{ 
    struct qNode* front ; 
    struct qNode* rear ;
};

void enqueue(struct Queue *Q, int data, int priority) 
{
    struct qNode *qn = new struct qNode;
    if(qn == NULL || size == 10)
    {
        cout << "Queue Overflow";
        exit(0);   
    }
    qn->data = data;
    qn->priority = priority;
    qn->next = NULL;
    if(Q->front == NULL)
    {
        Q->front = Q->rear = qn;
        size++;
        return;
    }
    size++;
    struct qNode *n = Q->front;
    if(Q->front == Q->rear)
    {
        if(n->priority > priority)
        {
            Q->rear = Q->front;
            qn->next = Q->front;
            Q->front = qn;  
            return;
        }
        else 
        {
            Q->front->next = qn;
            Q->rear = qn;
            return;
        }
    }
    while(n->next != NULL && (n->next->priority <= priority))
    {
        n = n->next;
    }
    if(n == Q->rear)
    {
        n->next = qn;
        Q->rear = qn;
        return;
    }
    if(n == Q->front && Q->front->priority > priority)
    {
        qn->next = n;
        Q->front = qn;
        return;
    }
    qn->next = n->next;
    n->next = qn;
}

int dequeue(struct Queue *Q)
{
    if(Q->front == NULL)
    {
        cout <<"Queue Underflow";
        exit(0);
    }
    struct qNode *temp = Q->front;
    int data = temp->data;
    Q->front = Q->front->next;
    free(temp);
    size--;
    return data;
}

void display(struct Queue *Q)
{
    if(Q->front == NULL)
    {
        cout << "Queue is empty";
        exit(0);
    }
    struct qNode *temp = Q->front;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    struct Queue *Q = new struct Queue;
    Q->front = NULL;
    Q->rear = NULL;
    int i;
    while(1)
    {
        cin>>i;
        if(i == 1)
        {
            int val, priority;
            cin>>val>>priority;
            enqueue(Q, val, priority);
        }
        
        else if(i == 2)
        {
            dequeue(Q);
        }
        
        else if(i == 3)
        {
            display(Q);
            break;
        }
        
        else
        {
            cout<<"Operation not supported"<<"\n";
            break;
        }
    }
    
    return 0;
}


