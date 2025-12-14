#pragma once
#include<vector>

//堆的两个特性：
//1.结构性：用数组表示的完全二叉树
//2.有序性：任一结点的关键字是其子树所有结点的最大值（最小值）
struct HeapNode {
    std::vector<int>Data;
    int Size;
};
HeapNode* CreatHeap();
void InsertHeap(int, HeapNode);
int DeleteHeap(HeapNode);
