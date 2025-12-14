#include"Heap.h"
using namespace std;


HeapNode* CreatHeap() {
    HeapNode* H = new HeapNode;
    H->Data.push_back(INT_MAX);
    H->Size = 0;
    return H;
}
void InsertHeap(int x, HeapNode* H) {
    H->Data.push_back(0);
    int i = ++(H->Size);
    while (x > H->Data[i / 2]) {
        H->Data[i] = H->Data[i / 2];
        i /= 2;
    }
    H->Data[i] = x;
}
int DeleteHeap(HeapNode* H) {
    int MaxItem = H->Data[1];
    int LastItem = H->Data[H->Size--];
    int Child = 0, Parent = 0;
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Data[Child] < H->Data[Child + 1]))
            Child++;
        if (LastItem > H->Data[Child])
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = LastItem;
    return MaxItem;
}
