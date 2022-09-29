#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int heapSize;
    int capacity;

public:
    MaxHeap(int capacity)
    {
        this->heapSize = 0;
        this->capacity = capacity;
        this->arr = new int[capacity];
    }

    void Push(int key)
    {
        if (heapSize >= capacity)
        {
            cout << "Heap Overflow: Can not Push into Heap\n";
            exit(0);
        }

        heapSize++;
        int curr = heapSize - 1;
        arr[curr] = key;

        while (curr > 0 && arr[curr] > arr[(curr - 1) / 2])
        {
            swap(arr[curr], arr[(curr - 1) / 2]);
            curr = (curr - 1) / 2;
        }
    }

    void print()
    {
        for (int i = 0; i < heapSize; i++)
            cout << arr[i] << " ";

        cout << "\n";
    }

    int Pop()
    {
        if (heapSize <= 0)
        {
            cout << "Heap Underflow: Could not Pop\n";
            exit(0);
        }

        int deleted = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;

        int curr = 0;

        while ((2*curr+1) < heapSize)
        {
            int child;

            if((2*curr+2) == heapSize)             // We have only left child            
                 child = 2*curr+1;

            else      // If both left and right child are present then find which is maximum
            {
                if(arr[2*curr+1] > arr[2*curr+2])
                    child = 2*curr+1;

                else
                    child = 2*curr+2;
            }

            // If current node is less than max(rightChild, leftChild) thenswap and do maxheapify again for the child
            if(arr[child] > arr[curr])
            {
                swap(arr[child], arr[curr]);
                curr = child;
            }

            // maxHeapify is done (because the curr node is having higher value than both left and right child)
            else
                break;
        }

        return deleted;
    }

    bool isEmpty()
    {
        if(heapSize <= 0)
            return true;

        else
            return false;
    }

    int Top()
    {
        if(heapSize <= 0)
        {
            cout<<"Heap is empty !"<<"\n";
            exit(0);
        }

        return arr[0];
    }

};

int main()
{
    MaxHeap h(7);
    h.Push(10);
    h.Push(20);
    h.Push(30);
    h.Push(25);
    h.Push(5);
    h.Push(40);
    h.Push(35);
    h.print();

    while(!h.isEmpty())
    {
        cout<<h.Top()<<" ";
        h.Pop();
    }

    h.print();
    h.Pop();

    return 0;
}
