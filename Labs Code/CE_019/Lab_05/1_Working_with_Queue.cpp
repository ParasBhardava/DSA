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
    struct qNode* next; 
};

struct Queue           
{ 
    struct qNode* front ; 
    struct qNode* rear ;
};

void enqueue(struct Queue *Q, int data) 
{
    if(Q->front == NULL && Q->rear == NULL)
    {
        struct qNode *qn = new struct qNode;
        if(size > 10 || qn == NULL)
        {
            cout << "Queue Overflow";
            exit(0);
        }
        Q->front = qn;
        Q->front->data = data;
        size++;
        Q->front->next = new struct qNode;
        Q->rear = Q->front;
    }
    else
    {
        Q->rear->next->data = data;
        size++;
        struct qNode *qn = new struct qNode;
        if(size > 10 || qn == NULL)
        {
            cout << "Queue Overflow";
            exit(0);
        }
        Q->rear = Q->rear->next;
        Q->rear->next = qn;
    }
}

int dequeue(struct Queue *Q)
{
    if(Q->front == NULL)
    {
        cout << "Queue Underflow";
        exit(0);
    }
    if(Q->front == Q->rear)
    {
        int data = Q->front->data;
        free(Q->front);
        Q->front = NULL;
        Q->rear = NULL;
        size--;
        return data;
    }
    struct qNode *n = Q->front;
    int data = n->data;
    Q->front = Q->front->next;
    free(n);
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
    struct Queue *n = new struct Queue;
    n = Q;
    cout << Q->front->data << " ";
    while(n->front != n->rear)
    {
        n->front = n->front->next;
        cout << n->front->data << " ";
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
            int val;
            cin>>val;
            enqueue(Q, val);
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
}

