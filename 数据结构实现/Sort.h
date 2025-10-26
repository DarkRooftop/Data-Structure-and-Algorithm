#pragma once

#include<vector>

#define ElementType int
#define MaxSize 50

void CreatArray(std::vector<ElementType>& array);
void InsertSort(std::vector<ElementType>& array);
void MyEmergeSort(std::vector<ElementType>& array, int L, int R);