#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int const SIZE = 1000;

class HeapData
{
private:
    int data[SIZE];
    int heapSize;

public:
    HeapData()
    {
        heapSize = 0;
    }

    void insert(int value);
    int remove();
    void reHeapUp(int childIndex);
    void reHeapDown(int childIndex);
    void display();
};

void HeapData ::insert(int value)
{
    int child = heapSize;
    heapSize = heapSize + 1;
    data[child] = value;
    reHeapUp(child);
};

void HeapData ::reHeapUp(int childIndex)
{
    int parent = (childIndex - 1) / 2;

    while (data[childIndex] < data[parent] && childIndex > 0)
    {
        swap(data[parent], data[childIndex]);
        childIndex = parent;

        parent = (childIndex - 1) / 2;
    }
};

void HeapData ::display()
{
    for (int i = 0; i < heapSize; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
};

int HeapData ::remove()
{

    int temp = data[0];
    swap(data[0], data[heapSize-1]);

    int sc,parent = 0, rc, lc;


    heapSize = heapSize - 1;
    reHeapDown(0);

    return temp;
};

void HeapData ::reHeapDown(int child)
{

    int parent = child;

    int sc;

    while (parent < heapSize)
    {
        cout << "test";
        int lc = 2 * parent + 1;
        int rc = 2 * parent + 2;
        if (data[lc] < data[rc])
        {
            sc = lc;
            
        }
        else if (data[lc] > data[rc])
        {
            sc = rc;
        }

        swap(data[parent], data[sc]);
        parent = sc;
    }
}

int main()
{
    int num;
    HeapData h;
    cout << "Enter the number of Students in Second Year :";
    cin >> num;

    int data[num];

    for (int i = 0; i < num; i++)
    {
        int marks;
        cout << "Enter the marks of Roll No :" << +i << endl;
        cin >> marks;

        h.insert(marks);
    }

    h.display();

    char flag;
    cout << "Do u want to delete (y or n)";
    cin >> flag;
    if (flag == 'y')
    {
        cout << h.remove();
        cout << endl;
    }
    h.display();
    return 0;
}