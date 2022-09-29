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

    void insert(int key)
    {
        if (heapSize >= capacity)
        {
            cout << "Heap Overflow: Could not insertKey\n";
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

    bool isEmpty()
    {
        if (heapSize <= 0)
            return true;

        else
            return false;
    }

    int Top()
    {
        if (heapSize <= 0)
        {
            cout << "Heap is empty !"
                 << "\n";
            exit(0);
        }

        return arr[0];
    }

    void maxHeapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heapSize && arr[left] > arr[i])
            largest = left;

        if (right < heapSize && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

    int extractMax()
    {
        if (heapSize <= 0)
        {
            cout << "Heap Underflow : cannot extract max\n";
        }

        if (heapSize == 1)
        {
            heapSize--;
            return arr[0];
        }

        // Store the minimum value, and remove it from heap
        int max = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        maxHeapify(0);

        return max;
    }

    void increaseKey(int i, int key)
    {
        if (arr[i] > key)
        {
            cout << "Wrong operation\n";
            exit(0);
        }

        arr[i] = key;
        while (i > 0 && arr[(i - 1) / 2] < arr[i])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void decreaseKey(int i, int key)
    {
        if (arr[i] < key)
        {
            cout << "Wrong operation\n";
            exit(0);
        }

        arr[i] = key;
        maxHeapify(i);
    }

    void deleteKey(int i)
    {
        increaseKey(i, INT8_MAX);
        extractMax();
    }
};

int main()
{
    MaxHeap h(7);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(25);
    h.insert(5);
    h.insert(40);
    h.insert(35);
    h.print();

    while (!h.isEmpty())
    {
        cout << h.Top() << " ";      // cout<< h.extractMax()<<" ";
        h.extractMax();
    }

    h.print();

    return 0;
}
