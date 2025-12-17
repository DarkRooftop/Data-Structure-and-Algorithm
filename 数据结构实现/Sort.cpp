#include<iostream>
#include"Sort.h"
using namespace std;
void CreatArray(vector<ElementType>& array) {
	int N;
	cin >> N;
	ElementType x;
	while (N > 0) {
		cin >> x;
		array.push_back(x);
		N--;
	}

}
void PrintArray(vector<ElementType>& array) {
	for (int i = 0; i < array.size(); i++) {
		cout << array[i];
		if (i < array.size() - 1)
			cout << " ";
	}
}

void SimpleSelectionSort(vector<ElementType>& array) {
	//选择第一小的，选择第二小的，选择...
	for (int i = 0; i < array.size() - 1; i++) {
		int key = array[i];
		int t = i;
		for (int j = i + 1; j < array.size(); j++) {
			if (key > array[j]) {
				t = j;
				key = array[j];
			}
		}
		int temp = array[t];
		array[t] = array[i];
		array[i] = temp;
	}
}

void PercDown(vector<ElementType>& array, int P, int N) {//第二个参数表示根节点
	int Parent, Child;
	ElementType X = array[P];
	for (Parent = P; Parent * 2 + 1 < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if (Child != N - 1 && array[Child] < array[Child + 1]) {
			Child++;
		}
		if (X >= array[Child])break;
		array[Parent] = array[Child];
	}
	array[Parent] = X;
}
void HeapSort(vector<ElementType>& array) {
	int N = array.size();
	//创建最大堆，堆的下标是0到N-1
	for (int i = N / 2 - 1; i >= 0; i--) {//i=最后一个树枝
		PercDown(array, i, N);
	}
	for (int i = N - 1; i > 0; i--) {
		swap(array[0], array[i]);
		PercDown(array, 0, i);//以0为根节点，调整大小为i的树
	}
}

void InsertionSort(vector<ElementType>& array) {
	if (array.size() == 1) return;
	int i = 0, j = 0;
	while (j < array.size() - 1) {
		j = i + 1;
		ElementType key = array[j];
		while (j < array.size() - 1 && array[j - 1] <= key) {
			j++;
			key = array[j];
		}
		//此时[i]>key，开始向前插入,j指向第一个小元素
		i = j;
		while (j > 0 && array[j - 1] > key) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = key;
		j = i;
	}
}

void ShellSort(vector<ElementType>& array) {
	vector<int>Sedgewick = { 929,505,109,41,19,5,1,0 };
	int Si = 0;
	while (Sedgewick[Si] > array.size())Si++;
	for (int D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si]) {
		for (int P = D; P < array.size(); P++) {
			int Tmp = array[P];
			int i = 0;
			for (i = P; i >= D && array[i - D] > Tmp; i -= D) {
				array[i] = array[i - D];
			}
			array[i] = Tmp;
		}
	}
}

void BubbleSort(vector<ElementType>& array) {
	for (int i = 0; i < array.size(); i++) {
		for (int j = i; j < array.size(); j++) {
			if (array[i] > array[j]) {
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

int MiddleOfThree(vector<ElementType>& array, int L, int R) {
	int mid = L + (R - L) / 2;
	if (array[L] > array[R])
		swap(array[L], array[R]);
	if (array[mid] > array[R])
		swap(array[mid], array[R]);
	if (array[mid] > array[L])
		swap(array[mid], array[L]);
	return L;
}
void QuickSort(vector<ElementType>& array, int L, int R) {
	if (R <= L)
		return;
	int SL = L, SR = R;
	int pivit = MiddleOfThree(array, L, R);
	int key = array[pivit];
	swap(array[pivit], array[L]);
	while (L < R) {
		while (L < R && array[R] >= key) R--;
		if (L < R) {
			swap(array[L], array[R]);
			L++;
		}
		while (L < R && array[L] < key) L++;
		if (L < R) {
			swap(array[L], array[R]);
			R--;
		}
	}
	array[L] = key;
	QuickSort(array, SL, L - 1);
	//L==R这里不用划分了
	QuickSort(array, R + 1, SR);
}
void QuickSort(vector<ElementType>& array) {
	QuickSort(array, 0, array.size() - 1);
}

void MergeSort(vector<ElementType>& array, int L, int R) {
	if (R == L)
		return;

	int M = L + (R - L) / 2;

	MergeSort(array, L, M);
	MergeSort(array, M + 1, R);

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
void MergeSort(vector<ElementType>& array) {
	MergeSort(array, 0, array.size() - 1);
}

int GetDigit(int X, int D) {//获取X的第D位数字，最低位为第1位
	int d = 0;
	for (int i = 1; i <= D; i++) {
		d = X % Radix;
		X /= Radix;
	}
	return d;
}
void LSDRadixSort(vector<ElementType>& arr) {
	int N = arr.size();
	Bucket B;
	Node* List = NULL, * tmp;
	for (int i = 0; i < Radix; i++) {//初始化桶
		HeadNode* tmp = new HeadNode();//指针内部元素指向单个桶的头尾元素
		B.push_back(tmp);//给每个桶分配一个指针
	}
	for (int i = 0; i < N; i++) {
		tmp = new Node(arr[i], List);
		List = tmp;//把元素插入链表**头部**
	}
	for (int D = 1; D <= MaxDigit; D++) {//开始处理，从次位到主位
		int Di = 0;
		//分配每个元素到桶
		Node* p = List;
		while (p) {
			Di = GetDigit(p->val, D);//获取元素第D位数字
			tmp = p; p = p->next;
			if (B[Di]->head == NULL) {
				B[Di]->head = B[Di]->tail = tmp;
			}
			else {
				B[Di]->tail->next = tmp;//把元素插入桶尾
				B[Di]->tail = tmp;//更新桶尾指针
			}
		}
		//收集桶里每个元素，用链表串起来
		List = NULL;
		for (Di = Radix - 1; Di >= 0; Di--) {//从最后一个桶依次向前，把元素串起来
			if (B[Di]->head) {//直接接入整个桶
				B[Di]->tail->next = List;
				List = B[Di]->head;
				B[Di]->head = B[Di]->tail = NULL;
			}
		}
	}
	//把链表里元素写回数组
	for (int i = 0; i < N; i++) {
		tmp = List;
		List = List->next;
		arr[i] = tmp->val;
		delete(tmp);//释放节点
	}
}