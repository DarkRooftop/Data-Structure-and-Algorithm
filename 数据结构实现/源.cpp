#include<iostream>
#include<queue>
#include<vector>

#include"Tree.h"
#include"Sort.h"
#include"Matrix.h"

using namespace std;


int main() {
	class Matrix_coculate mc;
	class Matrix_devided md;

	Matrix M1 = mc.CreatMatrix();
	Matrix M2 = mc.CreatMatrix();

	Matrix A1 = md.DevideMatrix(M1, 1);
	Matrix A2 = md.DevideMatrix(M1, 2);
	Matrix A3 = md.DevideMatrix(M1, 3);
	Matrix A4 = md.DevideMatrix(M1, 4);
	Matrix B1 = md.DevideMatrix(M2, 1);
	Matrix B2 = md.DevideMatrix(M2, 2);
	Matrix B3 = md.DevideMatrix(M2, 3);
	Matrix B4 = md.DevideMatrix(M2, 4);

	Matrix S1 = mc.CountMatrix(B2,B4,'-');
	Matrix S2 = mc.CountMatrix(A1,A2,'+');
	Matrix S3 = mc.CountMatrix(A3,A4,'+');
	Matrix S4 = mc.CountMatrix(B3,B1,'-');
	Matrix S5 = mc.CountMatrix(A1,A4,'+');
	Matrix S6 = mc.CountMatrix(B1,B4,'+');
	Matrix S7 = mc.CountMatrix(A2,A4,'-');
	Matrix S8 = mc.CountMatrix(B3,B4,'+');
	Matrix S9 = mc.CountMatrix(A1,A3,'-');
	Matrix S10 = mc.CountMatrix(B1,B2,'+');
	
	Matrix P1 = mc.MultiplyMatrix(A1, S1);
	Matrix P2 = mc.MultiplyMatrix(S2, B4);
	Matrix P3 = mc.MultiplyMatrix(S3, B1);
	Matrix P4 = mc.MultiplyMatrix(A4, S4);
	Matrix P5 = mc.MultiplyMatrix(S5, S6);
	Matrix P6 = mc.MultiplyMatrix(S7, S8);
	Matrix P7 = mc.MultiplyMatrix(S9, S10);

	Matrix Ct1= mc.CountMatrix(P5, P4, '+'); Matrix Ct2 = mc.CountMatrix(P6, P2, '-');
	Matrix C1 = mc.CountMatrix(Ct1, Ct2, '+');
	Matrix C2 = mc.CountMatrix(P1, P2, '+');
	Matrix C3 = mc.CountMatrix(P3, P4, '+');
	Ct1 = mc.CountMatrix(P5, P1, '+'); Ct2 = mc.CountMatrix(P7, P3, '+');
	Matrix C4 = mc.CountMatrix(Ct1, Ct2, '-');
	mc.PrintMatrix(C1); mc.PrintMatrix(C3);
	cout << endl;
	mc.PrintMatrix(C2); mc.PrintMatrix(C4);
	
	return 0;
}
	
/*vector<int> array,array2;
	cout << "请输入一串数字,输入-1结束" << endl;
	CreatArray(array);
	//cout << "请输入另一串数字" << endl;
	//CreatArray(array2);
	//InsertSort(array);
	ChoSort(array);
	//MergeSort(array);
	for (int i : array)
		cout << i << " ";*/
/*int m, n;
	cout << "请输入矩阵的行和列" << endl;
	cin >> m >> n;
	vector<vector<int>> nums(m, vector<int>(n));
	vector<int> t;
	int x;
	//cin matrix
	//cout << "请输入矩阵的元素" << endl;
	for (int i = 0; i < m; i++) {
		t.clear();
		for (int j = 0; j < n; j++) {
			cin >> x;
			t.push_back(x);
		}
		nums[i]=t;
	}
	//cin xyz
	//cout << "请输入矩阵的未知数" << endl;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}
	//deal matrix
	vector<int> b;
	for(int i = 0; i < m ; i++) {
		int t = 0;
		for (int j = 0; j < n; j++) {
			int A = nums[i][j % n];
			t += A * vec[j];
		}
		b.push_back(t);
	}
	//cout b
	for (int i = 0; i < n; i++) {
		cout << b[i]<<" ";
	}
	*/
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

