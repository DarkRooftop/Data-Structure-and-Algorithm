#pragma once
#include<vector>

#define ElementType int
#define MaxSize 50
//基数排序相关
#define MaxDigit 4
#define Radix 10
struct Node {
	int val;
	Node* next;
	Node(int val, Node* next) :val(val), next(next) {}
};
struct HeadNode {
	Node* head, * tail;
	HeadNode() :head(NULL), tail(NULL) {}
};
typedef std::vector<HeadNode*> Bucket;



void CreatArray(std::vector<ElementType>&);
void PrintArray(std::vector<ElementType>&);
															//平均时间复杂度   额外空间复杂度	稳定性
//选择排序
void SimpleSelectionSort(std::vector<ElementType>&);		//	  O(N^2)			O(1)		不稳定
void PercDown(std::vector<ElementType>&, int, int);
void HeapSort(std::vector<ElementType>&);					//	 O(NlogN)			O(1)		不稳定
void InsertionSort(std::vector<ElementType>&);				//	  O(N^2)			O(1)		 稳定
void ShellSort(std::vector<ElementType>&);					//	  O(N^d)			O(1)		不稳定
//交换排序
void BubbleSort(std::vector<ElementType>&);					//	  O(N^2)			O(1)		 稳定
int MiddleOfThree(std::vector<ElementType>&, int, int);
void QuickSort(std::vector<ElementType>&, int, int);
void QuickSort(std::vector<ElementType>&);					//	 O(NlogN)		   O(logN)		不稳定
void MergeSort(std::vector<ElementType>&, int, int);
void MergeSort(std::vector<ElementType>&);					//	 O(NlogN)			O(N)		 稳定
//基数排序
//目前还没想好怎么处理含负数的排序
int GetDigit(int X, int D);
void LSDRadixSort(std::vector<ElementType>&);				//	 O(D(N+R))		   O(N+R)		 稳定