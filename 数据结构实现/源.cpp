#include<iostream>


using namespace std;

//二叉搜索树的插入
#define MaxTree 10
#define ElementType int

typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

Position Find(ElementType X, BinTree BST);
Position Find2(ElementType X, BinTree BST);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

BinTree Insert(ElementType X, BinTree BST);
BinTree Delete(ElementType X, BinTree BST);

int main() {
	


	return 0;
}

Position Find(ElementType X, BinTree BST) {
	if (!BST) return NULL;//没找到
	if (X > BST->Data)
		return Find(X, BST->Right);//大于，右子树找--尾递归
	else if (X < BST->Data)
		return Find(X, BST->Left);//小于，左子树找--尾递归--可以用循环实现（迭代函数，执行效率更高）
	else
		return BST;//找到了，返回结点地址
}
Position Find2(ElementType X, BinTree BST) {
	while (BST) {
		if (X > BST->Data)
			BST = BST->Right;
		else if (X < BST->Data)
			BST = BST->Left;
		else
			return BST;
	}
	return NULL;
}
Position FindMin(BinTree BST) {//递归函数
	if (!BST)return NULL;
	else if (!BST->Left)
		return BST;//叶结点返回
	else
		return FindMin(BST->Left);//沿左分支继续查找
}
Position FindMax(BinTree BST) {//迭代函数
	if (BST)
		while (BST->Right)BST = BST->Right;
	else
		return BST;
}
BinTree Insert(ElementType X, BinTree BST) {
	if (!BST) {
		//若原树为空，生成并返回一个节点的二叉搜索树
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else {//开始找要插入元素的位置
		if (X < BST->Data)
			BST->Left = Insert(X, BST->Left);//递归插入左子树
		else if (X > BST->Data)
			BST->Right = Insert(X, BST->Right);//递归插入右子树
		//else X 已经存在，什么都不做
		return BST;
	}
}