#pragma once

#include<vector>

#define ElementType int
#define MaxSize 50

void CreatArray(std::vector<ElementType>& array);
void InsertSort(std::vector<ElementType>& array);

void MergeSort(std::vector<ElementType>& array);
void MergeSort(std::vector<ElementType>& array, int L, int R);

void ChoSort(std::vector<ElementType>& array);