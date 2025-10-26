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
void EmergeSort(vector<ElementType>& array) {
	return;
}
