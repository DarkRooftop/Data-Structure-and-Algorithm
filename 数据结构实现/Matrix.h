#pragma once
#include<vector>

typedef std::vector<std::vector<int>> Matrix;

class Matrix_coculate {
private://都放到.h里去
	//数据成员类型
	//内部辅助方法
	//记录交易日志的内部方法
	Matrix CreatMatrix(int, int);	
public:
	//构造函数
	//对外提供的接口方法
	//静态公共方法

	//创建矩阵
	Matrix CreatMatrix();

	//乘法运算
	Matrix MultiplyMatrix(Matrix, Matrix);
	
	//加减运算
	Matrix CountMatrix(Matrix, Matrix, char);

	//打印矩阵
	void PrintMatrix(Matrix);
};

class Matrix_devided {
private:
	Matrix Ans;

public:
	Matrix CreatMS(Matrix, int, int);
	Matrix DevideMatrix(Matrix, int);
};

//Matrix CountMatrix(Matrix, int, int, Matrix, int, int,char);


