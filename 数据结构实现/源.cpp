#include<iostream>
#include<queue>
#include<vector>

#include"Tree.h"
#include"Sort.h"

using namespace std;


int main() {

	vector<int> array,array2;
	cout << "请输入一串数字,输入-1结束" << endl;
	CreatArray(array);
	//cout << "请输入另一串数字" << endl;
	//CreatArray(array2);
	InsertSort(array);
	//EmergeSort(array);
	for (int i : array)
		cout << i << " ";
	/*
	TreeNode* root;
	//root = CreateSampleTree();
	cout << "请输入一些数字创建二叉树，输入-1以结束" << endl;
	root = CengCreatTree();
	if (!IsEmptyBT(root)) {
		//vector<ElementType> result = PreTraversal(root);
		vector<ElementType> result = CengTraversal(root);
		PrintBT(result);
	}
	//cout<<TreeHeight(root);
	int x;
	cin >> x;
	*/
	return 0;
}


