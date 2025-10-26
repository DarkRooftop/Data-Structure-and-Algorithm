#include"Sort.h"

#include<iostream>
using namespace std;

void CreatArray(vector<ElementType>& array) {
	int i = 0;
	ElementType x;
	while (cin>>x) {
		if (x == -1) break;
		array.push_back(x);
	}
	cin.clear();
	cin.sync();
}

void InsertSort(vector<ElementType>& array) {
	if (array.size() == 1) return;
	int i = 0, j = 0;
	while (j < array.size()-1) {
		j = i + 1;
		ElementType key = array[j];
		while (j<array.size()-1&&array[j-1] <= key) {
			j++;
			key = array[j];
		}
		//此时[i]>key，开始向前插入,j指向第一个小元素
		i = j;
		while (j>0&&array[j-1]>key) {
			array[j] = array[j-1];
			j--;
		}
		array[j] = key;
		j = i;
	}
}
void MyEmergeSort(vector<ElementType>& array, int L, int R) {
	
	if (R == L)
		return;
	
	int M = L + (R - L) / 2;
	
	MyEmergeSort(array, L, M);
	MyEmergeSort(array, M+1, R);

	vector<ElementType> temp;
	int i = L, j = M + 1;
	while (i <= M && j <= R) 
		temp.push_back(array[i] < array[j] ? array[i++] : array[j++]);
	while (i <= M) 
		temp.push_back(array[i++]);
	while (j <= R) 
		temp.push_back(array[j++]);

	//拷贝吗居然是
	for (int k = 0; k < temp.size(); k++)
		array[L + k] = temp[k];
	
	
	return;
}
