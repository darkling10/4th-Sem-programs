#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int const SIZE = 1000;

class HeapData{
    private:
        int data[SIZE];
        int heapSize;
    public:
        HeapData(){
            heapSize = 0;
        }

        void insert(int value);
        int remove(int child);
        void reHeapUp(int childIndex);
        void reHeapDown(int childIndex);
        void display();
};

void HeapData :: insert(int value){
    int child = heapSize;
    heapSize = heapSize + 1;
    data[child]=value;
    reHeapUp(child);

};

void HeapData :: reHeapUp(int childIndex){
    int parent = (childIndex - 1)/2;

    while (data[childIndex]<data[parent] && childIndex > 0)
    {
        swap(data[parent],data[childIndex]);
        childIndex=parent;

        parent=(childIndex-1)/2;
    }
    
};

void HeapData :: display(){
    for (int i = 0; i < heapSize; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
};

int HeapData :: remove(int child){
    
    int temp = data[0];
    data[0]=data[heapSize];

    reHeapDown(0);

    return temp;
};

void HeapData :: reHeapDown(int child){

    int parent = child;
    child = child*2+1; 
    

}

int main(){
    int num;
    HeapData h;
    cout<<"Enter the number of Students in Second Year :";
    cin>>num;

    int data[num];

    for (int i = 0; i < num; i++)
    {
        int marks;
        cout<<"Enter the marks of Roll No :"<<+i<<endl;
        cin>>marks;

        h.insert(marks);

    }
    
    h.display();
    return 0;
}