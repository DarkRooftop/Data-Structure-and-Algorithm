//数据隐藏
//最小权限
//封装变化
//结构稳定
//-->安全性、可维护性、可拓展性
#include<iostream>
#include <iomanip>
#include"Matrix.h"

using namespace std;

//创建矩阵的辅助函数
Matrix Matrix_coculate::CreatMatrix(int x, int y) {
	cout << "请输入矩阵的值：" << endl;
	Matrix M;
	for (int i = 0; i < x; i++) {
		vector<int>t;
		for (int j = 0; j < y; j++) {
			int x;
			cin >> x;
			t.push_back(x);
		}
		M.push_back(t);
	}
	return M;
}
//创建矩阵
Matrix Matrix_coculate::CreatMatrix() {
	int x, y;
	cout << "请输入矩阵的长和宽：" << endl;
	cin >> x >> y;
	return CreatMatrix(x, y);
}
//乘法运算
Matrix Matrix_coculate::MultiplyMatrix(Matrix M1, Matrix M2) {
	Matrix Ans;
	for (int i = 0; i < M1[0].size(); i++) {//选择行
		vector<int>t;
		for (int j = 0; j < M1.size(); j++) {//选择列
			int ans = 0;
			for (int z = 0; z < M1.size(); z++) {//取元素(行列不同的话这里不能这么取)
				ans += M1[i][z] * M2[z][j];
			}
			t.push_back(ans);
		}
		Ans.push_back(t);
	}
	return Ans;
}
//加减运算
Matrix Matrix_coculate::CountMatrix(Matrix M1, Matrix M2, char ch) {
	Matrix Ans;
	if (ch == '+') {
		for (int i = 0; i < M1[0].size(); i++) {//选择行
			vector<int>t;
			for (int j = 0; j < M1.size(); j++) {//选择列

				int ans = M1[i][j] + M2[i][j];

				t.push_back(ans);
			}
			Ans.push_back(t);
		}
	}
	else {
		for (int i = 0; i < M1[0].size(); i++) {//选择行
			vector<int>t;
			for (int j = 0; j < M1.size(); j++) {//选择列

				int ans = M1[i][j] - M2[i][j];

				t.push_back(ans);
			}
			Ans.push_back(t);
		}
	}
	return Ans;
}
//打印矩阵
void Matrix_coculate::PrintMatrix(Matrix M) {
	for (int i = 0; i < M.size(); i++) {
		for (int j = 0; j < M[0].size(); j++) {

			cout << setw(5) << M[i][j] << ' ';
		}
		cout << endl;
	}
}

	

Matrix Matrix_devided::CreatMS(Matrix M, int x, int y) {
	Matrix Ans;
	for (int i = 0; i < M[0].size() / 2; i++) {//选择行
		vector<int>t;
		for (int j = 0; j < M.size() / 2; j++) {//选择列

			int ans = M[x + i][y + j];

			t.push_back(ans);
		}
		Ans.push_back(t);
	}
	return Ans;
}
Matrix Matrix_devided::DevideMatrix(Matrix M, int a) {
	Matrix Ans;
	int x, y;
	int t1 = M[0].size() / 2;
	switch (a) {
	case 1:x = 0; y = 0; break;
	case 2:x = 0; y = t1; break;
	case 3:x = t1; y = 0; break;
	case 4:x = t1; y = t1; break;
	}
	return CreatMS(M, x, y);
}

/*
Matrix CountMatrix(Matrix M1, int x, int y, Matrix M2, int p, int q,char ch) {
	Matrix Ans;
	if (ch == '+') {
		for (int i = 0; i < M1[0].size() / 2; i++) {//选择行
			vector<int>t;
			for (int j = 0; j < M1.size() / 2; j++) {//选择列

				int ans = M1[x + i][y + j] + M2[p + i][q + j];

				t.push_back(ans);
			}
			Ans.push_back(t);
		}
	}
	else {
		for (int i = 0; i < M1[0].size() / 2; i++) {//选择行
			vector<int>t;
			for (int j = 0; j < M1.size() / 2; j++) {//选择列

				int ans = M1[x + i][y + j] - M2[p + i][q + j];

				t.push_back(ans);
			}
			Ans.push_back(t);
		}
	}
	return Ans;
}*/

